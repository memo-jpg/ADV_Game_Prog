#include "_Scene.h"
#include "_lightSetup.h"
#include "_Models.h"
#include "_KbMs.h"
#include "_parallax.h"
#include "_SkyBox.h"
#include "_Skybox2.h"
#include "_Camera.h"
#include "_2DPlayer.h"
#include "_Bullet.h"

_lightSetup *myLight = new _lightSetup();
_Models *teaPot = new _Models(); //new _Models() calls the constructor
_KbMs *KbMs = new _KbMs();
_parallax *plx = new _parallax();
_parallax *plx2 = new _parallax();
_SkyBox *sky = new _SkyBox();
_Skybox2 *sky2 = new _Skybox2();
_Camera *cam = new _Camera();
_2DPlayer *pl = new _2DPlayer();
// *b = new _Bullet();
_Bullet b[20];


_Scene::_Scene()
{
    //ctor

    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth =   GetSystemMetrics(SM_CXSCREEN);
}

_Scene::~_Scene()
{
    //dtor
}
GLint _Scene::initGL()
{
    glShadeModel(GL_SMOOTH); //for smooth render
    glClearColor(0,0,0,0); //Background Color. 1's is white, 0's is dark
    glClearDepth(2.0f); //test on Depth layer
    glEnable(GL_DEPTH_TEST); //Activate depth Test
    glDepthFunc(GL_LEQUAL); //Depth function type. L stands for Less Than

    glEnable(GL_COLOR_MATERIAL);
    myLight->setLight(GL_LIGHT0); //setting my first light

    //getting rid of backgrounds of images
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    cam->camInit();

    glEnable(GL_TEXTURE_2D); //enables texture
    teaPot->initModel("images/tex2.jpg");
    plx->parallaxInit("images/bck.png");
    plx2->parallaxInit("images/grnd.jpg");
    //sky->skyBoxInit();
    sky2->skyBoxInit("images/bk.png");

    //pl->initPlayer(8, 5, "images/SonicSpriteSheet.png");
    pl->initPlayer(6, 4, "images/player.png");

    for(int i=0; i<20; i++)
    b[i].initBullet("no images");

    return true;
}

GLint _Scene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); //clearing matrices

    cam->setUpCam();

    //teaPot->rotateX += 0.005;
    /*
      glPushMatrix();
    myLight->movingLight(GL_LIGHT0);
    teaPot->drawModel();
     glPopMatrix();
    //glColor3f(1.0,0.0,0.4); //Base Color; RGB format; 1.0 is max
    //glTranslated(0,0,-3); //move teapot back in the scene
    //glutSolidTeapot(0.5); //draw teapot

    glPushMatrix();
    glScalef(3.33,3.33,1);

    plx->parallaxDraw(screenWidth,screenHeight);
    plx->parallaxScroll(true, "left", 0.005);
    glPopMatrix();
    */
    glPushMatrix();
    //sky->drawSkyBox();
    sky2->skyBoxDraw();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(0.0, -2.0, -100.0);
    glTranslatef(0,-10,1);
    glRotatef(90, 1.0, 0.0, 0.0);
    //glRotatef(85, 0.0, 1.0, 0.0);
    glScalef(100, 50, -1.0);
    plx2->parallaxDraw(screenWidth, screenHeight);
    plx2->parallaxScroll(true, "right", 1.0);
    glPopMatrix();

    for(int i=0; i < 20; i++){
        b[i].drawBullet();
        b[i].bulletAction();
    }

    glDisable(GL_LIGHTING);
    pl->drawPlayer();
    pl->actions();
    glEnable(GL_LIGHTING);



    return true;
}

GLvoid _Scene::resizeScene(GLsizei width, GLsizei height) //listener function
{
    GLfloat aspectRatio = (GLfloat)width/height;

    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspectRatio,0.1,3000); //setting up close and far values
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

GLvoid _Scene::mouseMapping(int x, int y) //x&y are mouse coords
{
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth =   GetSystemMetrics(SM_CXSCREEN);

    GLint viewPort[4];
    GLdouble modelViewM[16]; //modelView Matrix; 4x4 matrix???
    GLdouble projectionM[16]; //projection matrix
    GLfloat winX, winY, winZ;

    float scale = 60*(screenWidth/screenHeight); //supposed to give us an estimation of mouse coords

    glGetDoublev(GL_MODELVIEW_MATRIX, modelViewM); //gets values from arg1 and stores them in arg2
    glGetDoublev(GL_PROJECTION_MATRIX, projectionM);
    glGetIntegerv(GL_VIEWPORT, viewPort);

    winX = (GLfloat)x;
    winY = (GLfloat)(viewPort[3] - y);
    glReadPixels(x,int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ); //takes all that bs and stores it into winZ

    //init mouse coords
    mouseX = (GLfloat)(x - screenWidth/2.0)/scale;
    mouseY = (GLfloat)(screenHeight/2.0 - y)/scale;
    mouseZ = -100.0;


    gluUnProject(winX, winY, winZ, modelViewM, projectionM, viewPort, &mouseX, &mouseY, &mouseZ);
}


int _Scene::winMsg(
              HWND	hWnd,			// Handle For This Window
			  UINT	uMsg,			// Message For This Window
			  WPARAM wParam,		// Additional Message Information
			  LPARAM lParam)
{
    KbMs->wParam = wParam;
    //cout<< wParam<<endl;
    switch(uMsg){
        //KbMs->wParam = wParam;

    case WM_KEYDOWN: //when a 'KEY' gets pressed down
        KbMs->keyPress(teaPot); //when user press a key on model
        //KbMs->moveBck(plx, 0.005);
        KbMs->moveBck(plx, 0.0005);
        KbMs->keyPress(sky);
         KbMs->keyPress(sky2);
         KbMs->keyPress(cam);
         KbMs->keyPress(pl);
        break;

    case WM_KEYUP: //when a 'KEY' is let up OR when 'KEY' is released
        KbMs->keyUp();
        KbMs->keyUp(pl);
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(teaPot, (double) GET_WHEEL_DELTA_WPARAM(wParam));
        break;

    case WM_MOUSEMOVE:
        KbMs->mouseMove(teaPot,LOWORD(lParam), HIWORD(lParam));
     //   KbMs->mouseMove(cam, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_LBUTTONDOWN: //Left Click
        mouseMapping(LOWORD(lParam), HIWORD(lParam));
        KbMs->mouseEventDown(mouseX, mouseY);
        mouseClicks = (mouseClicks+1)%20;

        b[mouseClicks].src.x = pl->plPos.x;
        b[mouseClicks].src.y = pl->plPos.y;
        b[mouseClicks].src.z = pl->plPos.z;

        b[mouseClicks].des.x = mouseX;
        b[mouseClicks].des.y = mouseY;
        b[mouseClicks].des.z = mouseZ;

        b[mouseClicks].t = 0;
        b[mouseClicks].actionTrigger = b[mouseClicks].SHOOT;
        b[mouseClicks].live = true;
        mouseClicks++;
/* Move around objects that you click on.
        cam->des.x = mouseX; //rotate camera around selected objects
        cam->des.y = mouseY;
        cam->des.z = mouseZ;
*/
        break;

         //To-Do
            //case for Right Button Down
    case WM_RBUTTONDOWN:
        KbMs->mouseEventDown(LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_LBUTTONUP:
        //b->live = false;
        break;

    case WM_RBUTTONUP:
        //
    case WM_MBUTTONUP:
        KbMs->mouseEventUp();
        break;

    }



}


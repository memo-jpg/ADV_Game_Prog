#include "_Scene.h"
#include "_lightSetup.h"
#include "_Models.h"
#include "_KbMs.h"

_lightSetup *myLight = new _lightSetup();
_Models *teaPot = new _Models(); //new _Models() calls the constructor
_KbMs *KbMs = new _KbMs();

_Scene::_Scene()
{
    //ctor
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
    return true;
}

GLint _Scene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); //clearing matrices

    //teaPot->rotateX += 0.005;
    myLight->movingLight(GL_LIGHT0);
    teaPot->drawModel();
    //glColor3f(1.0,0.0,0.4); //Base Color; RGB format; 1.0 is max
    //glTranslated(0,0,-3); //move teapot back in the scene
    //glutSolidTeapot(0.5); //draw teapot

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

    case WM_KEYDOWN:
        KbMs->keyPress(teaPot); //when user press a key on model
        break;

    case WM_KEYUP:
        KbMs->keyUp();
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(teaPot, (double) GET_WHEEL_DELTA_WPARAM(wParam));
        break;

    case WM_MOUSEMOVE:
        KbMs->mouseMove(teaPot,LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_LBUTTONDOWN:
        KbMs->mouseEventDown(LOWORD(lParam), HIWORD(lParam));
        break;

         //To-Do
            //case for Right Button Down
    case WM_RBUTTONDOWN:
        KbMs->mouseEventDown(LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_LBUTTONUP:
        //
    case WM_RBUTTONUP:
        //
    case WM_MBUTTONUP:
        KbMs->mouseEventUp();
        break;

    }



}


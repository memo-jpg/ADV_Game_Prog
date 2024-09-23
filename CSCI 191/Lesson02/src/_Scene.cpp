#include "_Scene.h"
#include "_lightSetup.h"

_lightSetup *myLight = new _lightSetup();

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

    myLight->movingLight(GL_LIGHT0);
    glColor3f(1.0,0.0,0.4); //Base Color; RGB format; 1.0 is max
    glTranslated(0,0,-3); //move teapot back in the scene
    glutSolidTeapot(0.5); //draw teapot

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

#include "_Models.h"

_Models::_Models()
{
    //ctor

    rotateX = 0.0; //rotate selected axis
    rotateY = 0.0;
    rotateZ = 0.0;

    pos.x = 0.0; //get position of selected axis
    pos.y = 0.0;
    pos.z = -30.0;

     color.r = 0.0;
     color.g = color.b = 1.0;

    myTime->startTime = clock();
}

_Models::~_Models()
{
    //dtor
}
GLvoid _Models::initModel(char* fileName)
{
    myTex->loadTexture(fileName);
}

GLvoid _Models::drawModel()
{
    // glColor3f(0.5, 1.0, 0.6); //color of the model
      glColor3f(color.r, color.g, color.b); //color of the model
      glTranslatef(pos.x,pos.y,pos.z);


       glRotatef(rotateX,1,0,0);
       glRotatef(rotateY,1,0,0);
      glRotatef(rotateZ,1,0,0);

      myTex->bindTexture();
      glutSolidTeapot(1.5); //Model, size = 2.5
}

GLvoid _Models::moveModel()
{
    if(clock()-myTime->startTime > 20){
        (pos.x < -40)?dir=1:(pos.x>40?dir=-1:NULL); //2 if statments, using ? terney (?) operator
        pos.x += dir*0.2;
        myTime->startTime = clock();
    }

}

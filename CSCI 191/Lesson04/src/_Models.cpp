#include "_Models.h"

_Models::_Models()
{
    //ctor

    rotateX = 0.0; //rotate selected axis
    rotateY = 0.0;
    rotateZ = 0.0;

    posX = 0.0; //get position of selected axis
    posY = 0.0;
    posZ = -8.0;
}

_Models::~_Models()
{
    //dtor
}
GLvoid _Models::drawModel()
{
    glColor3f(0.5, 1.0, 0.6); //color of the model
    glTranslatef(posX,posY,posZ);

    glRotatef(rotateX,1,0,0);
     glRotatef(rotateY,1,0,0);
      glRotatef(rotateZ,1,0,0);

      glutSolidTeapot(2.5); //Model, size = 2.5
}

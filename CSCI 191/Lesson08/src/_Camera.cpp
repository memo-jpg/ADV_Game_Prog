#include "_Camera.h"

_Camera::_Camera()
{
    //ctor

}

_Camera::~_Camera()
{
    //dtor
}
void _Camera::camInit()
{
    //Initialize Camera Values
    eye.x = eye.y = eye.z = 0; //eye position
    des.x=0.0, des.y=0.0, des.z= -100.0; //destination position
    upVec.x = upVec.z = 0; upVec.y = 1.0;
}

void _Camera::setUpCam()
{
    //Setup Camera w/ Values
    gluLookAt(eye.x, eye.y, eye.z, des.x, des.y, des.z, upVec.x, upVec.y, upVec.z);
}

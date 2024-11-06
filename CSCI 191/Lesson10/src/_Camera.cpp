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
    eye.x = eye.y = 0; eye.z = 5.0; //eye position
    des.x=0.0, des.y=0.0, des.z= -10.0; //destination position
    upVec.x = upVec.z = 0; upVec.y = 1.0;

    zoom = sqrt( pow(des.x-eye.x,2)+pow(des.y-eye.y,2)+pow(des.z-eye.z,2) ); //radius
}

void _Camera::setUpCam()
{
    eye.x = des.x + zoom * std::cos(thetaY * PI / 180.0) * std::sin(thetaX * PI / 180.0);
    eye.y = des.y + zoom * std::sin(thetaY * PI / 180.0);
    eye.z = des.z + zoom * std::cos(thetaY * PI / 180.0) * std::cos(thetaX * PI / 180.0);

    //Setup Camera w/ Values
    gluLookAt(eye.x, eye.y, eye.z, des.x, des.y, des.z, upVec.x, upVec.y, upVec.z);
}

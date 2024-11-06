#ifndef _CAMERA_H
#define _CAMERA_H

#include "_Common.h"

class _Camera
{
    public:
        _Camera();
        virtual ~_Camera();

        vec3 eye;
        vec3 des;
        vec3 upVec;

        float zoom;

        float thetaX = 0.0, thetaY = 0.0;

        void camInit();
        void setUpCam();

        void rotateXYP(vec3); //rotate x&y-axis around P
        void rotateUDP(vec3); //rotate Up&Down around P

    protected:

    private:
};

#endif // _CAMERA_H

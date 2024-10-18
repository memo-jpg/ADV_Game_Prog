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

        void camInit();
        void setUpCam();

    protected:

    private:
};

#endif // _CAMERA_H

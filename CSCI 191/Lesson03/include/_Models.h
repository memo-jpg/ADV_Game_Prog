#ifndef _MODELS_H
#define _MODELS_H

#include "_Common.h"

class _Models
{
    public:
        _Models();
        virtual ~_Models();

        GLfloat rotateX; //rotate selected axis
        GLfloat rotateY;
        GLfloat rotateZ;

        GLfloat posX; //get position of selected axis
        GLfloat posY;
        GLfloat posZ;

        GLvoid drawModel();

    protected:

    private:
};

#endif // _MODELS_H

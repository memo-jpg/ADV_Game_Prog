#ifndef _MODELS_H
#define _MODELS_H

#include "_Common.h"
#include "_TextureLoader.h"

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

        _TextureLoader* myTex = new _TextureLoader();
        GLvoid initModel(char* fileName);
        GLvoid drawModel();



    protected:

    private:
};

#endif // _MODELS_H

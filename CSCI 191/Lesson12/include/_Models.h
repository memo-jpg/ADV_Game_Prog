#ifndef _MODELS_H
#define _MODELS_H

#include "_Common.h"
#include "_TextureLoader.h"
#include "_Timer.h"

class _Models
{
    public:
        _Models();
        virtual ~_Models();

        GLfloat rotateX; //rotate selected axis
        GLfloat rotateY;
        GLfloat rotateZ;

        vec3 pos;
        int dir=1; //direction
        //int hitCount = 0;
        col3 color;

        /*
        GLfloat posX; //get position of selected axis
        GLfloat posY;
        GLfloat posZ;
        */

        _TextureLoader* myTex = new _TextureLoader();
        _Timer *myTime = new _Timer();
        GLvoid initModel(char* fileName);
        GLvoid drawModel();
        GLvoid moveModel();



    protected:

    private:
};

#endif // _MODELS_H

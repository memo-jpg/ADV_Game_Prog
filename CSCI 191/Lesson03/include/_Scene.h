#ifndef _SCENE_H
#define _SCENE_H

#include "_Common.h"

class _Scene
{
    public:
        _Scene();
        virtual ~_Scene();
        GLint initGL(); //Initialize the scene
        GLint drawScene(); //Render scene
        GLvoid resizeScene(GLsizei, GLsizei); //address resize


    protected:

    private:
};

#endif // _SCENE_H

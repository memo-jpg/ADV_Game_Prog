#include "_SkyBox.h"

_SkyBox::_SkyBox()
{
    //ctor
}

_SkyBox::~_SkyBox()
{
    //dtor
}

void _SkyBox::skyBoxInit()
{
    skyTex[0].loadTexture("images/front.jpg");
    skyTex[1].loadTexture("images/back.jpg");
    skyTex[2].loadTexture("images/top.jpg");
    skyTex[3].loadTexture("images/bottom.jpg");
    skyTex[4].loadTexture("images/left.jpg");
    skyTex[5].loadTexture("images/right.jpg");

    xMin=yMin=0.0;
    xMax=yMax=1.0;
    xRotation = 0, yRotation =0, zRotation = 0;
    xTranslate=0, yTranslate=0, zTranslate=0;
}

void _SkyBox::drawSkyBox()
{
    glDisable(GL_LIGHTING);

    glTranslatef(xTranslate,yTranslate, zTranslate);
    glRotatef(xRotation, 1,0,0);
        glRotatef(yRotation, 0,1,0);
            glRotatef(zRotation,0,0,1);

    //drawing the FRONT wall
    skyTex[0].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMin);
    glVertex3f(-1.0,1.0,1.0);//front face
        glTexCoord2f(xMax, yMin);
    glVertex3f(1.0,1.0,1.0);
        glTexCoord2f(xMax, yMax);
    glVertex3f(1.0,-1.0,1.0);
        glTexCoord2f(xMin, yMax);
    glVertex3f(-1.0,-1.0,1.0);
    glEnd();

    //drawing BACK wall
    skyTex[1].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax);
    glVertex3f(1.0,-1.0,-1.0);//front face
        glTexCoord2f(xMax, yMax);
    glVertex3f(-1.0,-1.0,-1.0);
        glTexCoord2f(xMax, yMin);
    glVertex3f(-1.0,1.0,-1.0);
        glTexCoord2f(xMin, yMin);
    glVertex3f(1.0,1.0,-1.0);
    glEnd();

    //drawing LEFT wall
    skyTex[5].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMin);
    glVertex3f(-1.0,1.0,-1.0);//front face
        glTexCoord2f(xMax, yMin);
    glVertex3f(-1.0,1.0,1.0);
        glTexCoord2f(xMax, yMax);
    glVertex3f(-1.0,-1.0,1.0);
        glTexCoord2f(xMin, yMax);
    glVertex3f(-1.0,-1.0,-1.0);
    glEnd();

    //drawing RIGHT wall
    skyTex[4].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(xMax, yMin);
    glVertex3f(1.0,1.0,-1.0);//front face
        glTexCoord2f(xMax, yMax);
    glVertex3f(1.0,-1.0,-1.0);
        glTexCoord2f(xMin, yMax);
    glVertex3f(1.0,-1.0,1.0);
        glTexCoord2f(xMin, yMin);
    glVertex3f(1.0,1.0,1.0);
    glEnd();

    //drawing TOP wall
    skyTex[2].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax);
    glVertex3f(1.0,1.0,-1.0);//front face
        glTexCoord2f(xMin, yMin);
    glVertex3f(1.0,1.0,1.0);
        glTexCoord2f(xMax, yMin);
    glVertex3f(-1.0,1.0,1.0);
        glTexCoord2f(xMax, yMax);
    glVertex3f(-1.0,1.0,-1.0);
    glEnd();

    //drawing BOTTOM wall
    skyTex[3].bindTexture();
    glBegin(GL_QUADS);
        glTexCoord2f(xMax, yMax);
    glVertex3f(-1.0,-1.0,1.0);//front face
        glTexCoord2f(xMin, yMax);
    glVertex3f(1.0,-1.0,1.0);
        glTexCoord2f(xMin, yMin);
    glVertex3f(1.0,-1.0,-1.0);
        glTexCoord2f(xMax, yMin);
    glVertex3f(-1.0,-1.0,-1.0);
    glEnd();

    glEnable(GL_LIGHTING);

}

#include "_Skybox2.h"

_Skybox2::_Skybox2()
{
    //ctor
}

_Skybox2::~_Skybox2()
{
    //dtor
}
void _Skybox2::skyBoxInit(char* fileName)
{
    tex->loadTexture(fileName);
    tMax.x = tMax.y = 1;
    tMin.x = tMin.y = 0.0;
    scale.x = 200;
    scale.y = 100;
    scale.z = 200; //scaler value
    trans.x = trans.y = trans.z = 0; //Translation
    rot.x = rot.y = rot.z = 0; //Rotations
}

void _Skybox2::skyBoxDraw()
{
    glDisable(GL_LIGHTING); //depends on your skybox

    glTranslatef(trans.x, trans.y, trans.z);
    glRotatef(rot.x, 1,0,0);
        glRotatef(rot.y, 0,1,0);
            glRotatef(rot.z,0,0,1);
    glScalef(scale.x, scale.y, scale.z);

   tex->bindTexture();

   tMin.x = 1.0 / 4.0;
   tMax.x =2.0 / 4.0;
   tMin.y = 1.0 / 3.0;
   tMax.y =  2.0 / 3.0;
   //drawing the FRONT wall
    glBegin(GL_QUADS);
        glTexCoord2f(tMin.x, tMin.y); glVertex3f(-1.0,1.0,1.0);
        glTexCoord2f(tMax.x, tMin.y); glVertex3f(1.0,1.0,1.0);
        glTexCoord2f(tMax.x, tMax.y); glVertex3f(1.0,-1.0,1.0);
        glTexCoord2f(tMin.x, tMax.y); glVertex3f(-1.0,-1.0,1.0);



    tMin.x = 3.0/4.0;
    tMax.x = 4.0/4.0;
    tMin.y = 1.0/ 3.0;
    tMax.y = 2.0/3.0;
    //drawing BACK wall
        glTexCoord2f(tMax.x, tMin.y);glVertex3f(-1.0,1.0,-1.0);
        glTexCoord2f(tMax.x, tMax.y);glVertex3f(-1.0,-1.0,-1.0);
        glTexCoord2f(tMin.x, tMax.y);glVertex3f(1.0,-1.0,-1.0);
        glTexCoord2f(tMin.x, tMin.y);glVertex3f(1.0,1.0,-1.0);


   tMin.x = 1.0/4.0;
   tMax.x = 2.0/4.0;
   tMin.y = 0.0/ 3.0;
   tMax.y = 1.0/3.0;
    //drawing TOP wall
        glTexCoord2f(tMax.x, tMin.y); glVertex3f(1.0,1.0,-1.0);
        glTexCoord2f(tMax.x, tMax.y); glVertex3f(1.0,1.0,1.0);
        glTexCoord2f(tMin.x, tMax.y); glVertex3f(-1.0,1.0,1.0);
        glTexCoord2f(tMin.x, tMin.y); glVertex3f(-1.0,1.0,-1.0);


   tMin.x = 1.0/4.0;
   tMax.x = 2.0/4.0;
   tMin.y = 2.0/ 3.0;
   tMax.y = 3.0/3.0;
    //drawing BOTTOM wall
        glTexCoord2f(tMin.x, tMin.y);glVertex3f(-1.0,-1.0,1.0);//front face
        glTexCoord2f(tMax.x, tMin.y);glVertex3f(1.0,-1.0,1.0);
        glTexCoord2f(tMax.x, tMax.y);glVertex3f(1.0,-1.0,-1.0);
        glTexCoord2f(tMin.x, tMax.y);glVertex3f(-1.0,-1.0,-1.0);


    tMin.x = 0.0/4.0;
   tMax.x = 1.0/4.0;
   tMin.y = 1.0/3.0;
   tMax.y = 2.0/3.0;
    //drawing LEFT wall
        glTexCoord2f(tMin.x, tMin.y);glVertex3f(-1.0,1.0,-1.0);//front face
        glTexCoord2f(tMax.x, tMin.y);glVertex3f(-1.0,1.0,1.0);
        glTexCoord2f(tMax.x, tMax.y);glVertex3f(-1.0,-1.0,1.0);
        glTexCoord2f(tMin.x, tMax.y);glVertex3f(-1.0,-1.0,-1.0);

   tMin.x = 2.0/4.0;
   tMax.x = 3.0/4.0;
   tMin.y = 1.0/3.0;
   tMax.y = 2.0/3.0;
    //drawing RIGHT wall
        glTexCoord2f(tMax.x, tMin.y);glVertex3f(1.0,1.0,-1.0);//front face
        glTexCoord2f(tMax.x , tMax.y);glVertex3f(1.0,-1.0,-1.0);
        glTexCoord2f(tMin.x, tMax.y);glVertex3f(1.0,-1.0,1.0);
        glTexCoord2f(tMin.x, tMin.y);glVertex3f(1.0,1.0,1.0);
    glEnd();

    glEnable(GL_LIGHTING);

}

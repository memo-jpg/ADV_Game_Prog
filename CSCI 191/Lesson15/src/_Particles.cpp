#include "_Particles.h"

_Particles::_Particles()
{
    //ctor
}

_Particles::~_Particles()
{
    //dtor
}

void _Particles::initParticles(int x, int y, int z, char* fileName)
{
    myTex->loadTexture(fileName);
    myTime->startTime = clock();
}

void _Particles::drawParticles()
{
    myTex->bindTexture();
    for(int i = 0; i < numDrops; i++){

        if(drops[i].live){
            glPushMatrix();
                BuildQuad(drops[i].pos.x, drops[i].pos.y, drops[i].pos.z, 1);
            glPopMatrix();
        }
    }
}

void _Particles::updateParticles()
{
    if(clock() - myTime->startTime > 50){

        for(int i = 0; i < numDrops; i++){
            if(drops[i].live){
                drops[i].pos.x += drops[i].velocity.x;
                drops[i].pos.y += drops[i].velocity.y;
                drops[i].pos.z += drops[i].velocity.z;

                drops[i].alpha -= 1;
                drops[i].t += 0.0001;
            }

            if(drops[i].alpha < 0){
                drops[i].live = false;
                drops[i].t = 0;

            }

        }
    }
}

void _Particles::generateParticles(float mx, float my)
{
    newDrops = rand() % 30 +1;

    if(newDrops + numDrops > MAX_DROPS){
        newDrops = MAX_DROPS - numDrops;
    }

    for(int i = numDrops; i < (newDrops+numDrops); i++)
    {
        drops[i].live = true;
        drops[i].radius = 1.01;

        drops[i].pos.x = mx;
        drops[i].pos.y = my;
        drops[i].pos.z = ( (rand() % 50) / 100.0)-5.0;

        drops[i].expRadius = 0.1;

        drops[i].angle = rand() % 360;
        drops[i].alpha = rand() % 50;
        drops[i].t = 0;

        drops[i].velocity.x = sin(drops[i].angle) * drops[i].expRadius;
        drops[i].velocity.y = cos(drops[i].angle) * drops[i].expRadius;
        drops[i].velocity.z = cos(drops[i].angle) * drops[i].expRadius;
    }
     numDrops += newDrops;
    (numDrops >= MAX_DROPS)?numDrops=0:NULL;
}

void _Particles::BuildQuad(float x, float y, float z, float w)
{
    glEnable(GL_BLEND);
       // glBlendFunc(GL_ONE, GL_ONE);

        glTranslatef(x,y,z);
        glScalef(0.5, 0.5, 1.0);

    glBegin(GL_QUADS);

        glTexCoord2f(xMin, yMax);
        glVertex3f(-1,-1,1);

        glTexCoord2f(xMax, yMax);
        glVertex3f(1,-1,1);

        glTexCoord2f(xMax, yMin);
        glVertex3f(1,1,1);

        glTexCoord2f(xMin, yMin);
        glVertex3f(-1,1,1);

    glEnd();

}

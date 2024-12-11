#include "_2DPlayer.h"

_2DPlayer::_2DPlayer()
{
    //ctor
}

_2DPlayer::~_2DPlayer()
{
    //dtor
}

void _2DPlayer::initPlayer(int xFrames, int yFrames, char* fileName)
{
    //Drawing a Quad
    vert[0].x = -1.0; vert[0].y = -1.0; vert[0].z = -1.0;
    vert[1].x = 1.0; vert[1].y = -1.0; vert[1].z = -1.0;
    vert[2].x = 1.0; vert[2].y = 1.0; vert[2].z = -1.0;
    vert[3].x = -1.0; vert[3].y = 1.0; vert[3].z = -1.0;

    plPos.x = 0.0; plPos.y = -0.5; plPos.z = -2.0;
    plScale.x = 0.5; plScale.y = 0.5; plScale.z = 1.0;

        tex->loadTexture(fileName);

    framesX = xFrames; framesY = yFrames;

    actionTrigger = 0;
    myTime->startTime=clock();

    xMin=0;
    yMax = 1.0/(float)framesY;
    xMax = 1.0/(float)framesX;
    yMin= (yMax- 1.0) / (float)framesY;
}

void _2DPlayer::drawPlayer(){
    glPushMatrix();

    glTranslatef(plPos.x, plPos.y, plPos.z);
    glScalef(plScale.x, plScale.y, plScale.z);

    //Background color
    glColor3f(1.0,1.0,1.0); //white
    tex->bindTexture();

    glBegin(GL_QUADS);

        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[0].x, vert[0].y, vert[0].z);

        glTexCoord2f(xMax, yMax);
        glVertex3f(vert[1].x, vert[1].y, vert[1].z);

        glTexCoord2f(xMax, yMin);
        glVertex3f(vert[2].x, vert[2].y, vert[2].z);

        glTexCoord2f(xMin, yMin);
        glVertex3f(vert[3].x, vert[3].y, vert[3].z);

    glEnd();

    glPopMatrix();
}

void _2DPlayer::actions()
{
    //later...
    switch(actionTrigger){
        case STAND:
            xMin=0;
            xMax = 1.0/(float)framesX; //number of frames on X direction
            yMax = 1.0/(float)framesY;
            yMin = yMax - 1.0/(float)framesY;
            break;

        case WALKLEFT:
            if(clock() - myTime->startTime > 60)
            {
                if(xMin<1)
                {
                    //jump one frame
                    xMax += 1.0 / (float)framesX;
                    xMin += 1.0 / (float)framesX;
                }
                else {
                    xMax=0;
                    xMin = 1.0/(float)framesX; //number of frames on X direction

                    if(yMax<1)
                    {
                        yMax += 1.0/(float)framesY;
                        yMin += 1.0/(float)framesY;

                    }
                    else{
                        yMax = 1.0 / (float)framesY;
                        yMin = 0.0 / (float)framesY;
                    }

               // xMax +=  1.0/(float)framesX;
                //xMin += 1.0/(float)framesX
                }
                myTime->startTime = clock();
            }

            break;

        case WALKRIGHT:
            if(clock() - myTime->startTime > 60)
            {
                if(xMax < 1) {
                xMax +=  1.0/(float)framesX;
                xMin += 1.0/(float)framesX;
                }
                else{
                    xMin = 0;
                    xMax = 1.0/(float)framesX;

                    if(yMax < 1){
                        yMax += 1.0 / (float)framesY;
                        yMin += 1.0 / (float)framesY;
                    }
                    else{
                        yMax = 1.0 / (float)framesY;
                        yMin  = 0.0 / (float)framesY;

                    }
                }

                myTime->startTime = clock();
            }
            break;

    }
}

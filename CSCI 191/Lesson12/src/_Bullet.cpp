#include "_Bullet.h"

_Bullet::_Bullet()
{
    //ctor
}

_Bullet::~_Bullet()
{
    //dtor
}

void _Bullet::initBullet(char* fileName)
{
    pos.x = 0; pos.y = 0; pos.z = 0;
    t = 0;
    des.x = 0; des.y = 20.0; des.z = -50.0;
    src.x = 0.0; src.y = 0.0; src.z = 0.0;
    live = false;
}

void _Bullet::drawBullet()
{
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    //if(actionTrigger == SHOOT) //Only draw when on the move
    if(live)
    {
        glTranslatef(pos.x, pos.y, pos.z);
        glutSolidSphere(0.5, 20, 20);
    }
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);

}

void _Bullet::bulletAction()
{
    switch(actionTrigger)
    {
        case READY:
            pos.x=0.0; pos.y =0.0; pos.z=0.0;

            src.x = 0.0; src.y = 0.0; src.z = 0.0;
            live = false;
            t = 0;
            break;

        case DEAD:
            live = 0; //false
            t = 0;
            actionTrigger = 0;
            break;

        case SHOOT:
            //live = true;
            if(live)
            {
                if(clock()-myTime->startTime < 70)
                {
                    if(t < 1) t = 0.001; else actionTrigger = READY;
                    pos.x = src.x + t*(des.x - src.x);
                    pos.y = src.y + t*(des.y - src.y);
                    pos.z = src.z + t*(des.z - src.z);

                    src.x = pos.x; src.y = pos.y; src.z = pos.z;
                }
                myTime->startTime = clock();
            }
            break;

        case HIT:
            //use this to show explosion or any other action
            break;
    }

}

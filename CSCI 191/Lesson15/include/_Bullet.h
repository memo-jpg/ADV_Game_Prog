#ifndef _BULLET_H
#define _BULLET_H

#include "_Common.h"
#include "_TextureLoader.h"
#include "_Timer.h"


class _Bullet
{
    public:
        _Bullet();
        virtual ~_Bullet();

     _TextureLoader *tex = new _TextureLoader();
     _Timer *myTime = new _Timer();

     vec3 pos;
     vec3 des;
     vec3 src; //source
     vec3 scale;
     float t = 0.0; //parameter for the bullet path
     bool live = true;

     enum{READY, //ready to shoot
            DEAD, //Out of bounds or already hit
            SHOOT,
            HIT};

     void initBullet(char *);
     void drawBullet();
     void bulletAction();

     int actionTrigger;

    protected:

    private:
};

#endif // _BULLET_H

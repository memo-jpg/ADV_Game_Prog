#ifndef _PARTICLES_H
#define _PARTICLES_H

#include "_Common.h"
#include "_Timer.h"
#include "_TextureLoader.h"

#define MAX_DROPS 50000

class _Particles
{
    public:
        _Particles();
        virtual ~_Particles();
        _TextureLoader *myTex = new _TextureLoader();
        _Timer *myTime = new _Timer();

        int numDrops;
        int newDrops;

        typedef struct{
            bool live;
            vec3 pos;
            vec3 dir;
            col3 color;
            vec3 velocity;
            float alpha;
            float t=0;

            float mass;
            float radius;

            float expRadius; //explosion radius
            float angle;
        }particle;

        particle drops[MAX_DROPS];

        float xMax = 1.0f, xMin = 0.0f;
        float yMax = 1.0f, yMin = 0.0f;

        void drawParticles();
        void updateParticles();
        void generateParticles(float, float);
        void BuildQuad(float, float, float, float);
        void initParticles(int, int, int, char*);

    protected:

    private:
};

#endif // _PARTICLES_H

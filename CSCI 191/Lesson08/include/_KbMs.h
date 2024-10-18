#ifndef _KBMS_H
#define _KBMS_H

#include "_Common.h"
#include "_Models.h"
#include "_parallax.h"
#include "_SkyBox.h"
#include "_Skybox2.h"
#include "_Camera.h"

class _KbMs
{
    public:
        _KbMs();
        virtual ~_KbMs();


        WPARAM wParam; //Windows Parameter


        void keyPress(_Models *);
        void keyPress(_SkyBox *);
        void keyPress(_Skybox2 *);
        void keyPress(_Camera *);
        void moveBck(_parallax*, float);
        void keyUp();

        void mouseEventDown(double, double);
        void mouseEventUp();

        void mouseWheel(_Models*, double);
        void mouseMove(_Models*, double, double);
        void mouseMove(_SkyBox *, double, double);
        void mouseMove(_Skybox2 *, double, double);
        void mouseMove(_Camera *, double, double);



        double prev_Mousex;
        double prev_MouseY;

        double prev_CamMousex;
        double prev_CamMouseY;

        bool mouseTranslation;
        bool mouseRotation;

    protected:

    private:
};

#endif // _KBMS_H

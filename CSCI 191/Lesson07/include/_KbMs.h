#ifndef _KBMS_H
#define _KBMS_H

#include "_Common.h"
#include "_Models.h"
#include "_parallax.h"
#include <_SkyBox.h>

class _KbMs
{
    public:
        _KbMs();
        virtual ~_KbMs();


        WPARAM wParam; //Windows Parameter


        void keyPress(_Models *);
        void keyPress(_SkyBox *);
        void moveBck(_parallax*, float);
        void keyUp();

        void mouseEventDown(double, double);
        void mouseEventUp();

        void mouseWheel(_Models*, double);
        void mouseMove(_Models*, double, double);
        void mouseMove(_SkyBox *, double, double);

        double prev_Mousex;
        double prev_MouseY;

        bool mouseTranslation;
        bool mouseRotation;

    protected:

    private:
};

#endif // _KBMS_H

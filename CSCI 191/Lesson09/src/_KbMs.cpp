#include "_KbMs.h"

_KbMs::_KbMs()
{
    //ctor

    prev_Mousex =0;
    prev_MouseY=0;
    prev_CamMousex = 0;
    prev_CamMouseY = 0;

    mouseTranslation = false;
    mouseRotation = false;
}

_KbMs::~_KbMs()
{
    //dtor
}
void _KbMs::keyPress(_Models* model)
{
    switch(wParam){
        case VK_LEFT:
                model->rotateY += 1.0;
                break;

        case VK_RIGHT:
                model->rotateY -= 1.0;
                break;

            //todo
                //VK_DOWN
                //VK_UP

                //do Z-rotations
    }
}

void _KbMs::keyUp()
{
    switch(wParam){
        default: break;
    }
}

void _KbMs::mouseEventDown(double x, double y)
{//when mouse is pressed down
    prev_Mousex = x;
    prev_MouseY = y;

    switch(wParam){
    case MK_LBUTTON: //Set translation flag
            mouseTranslation = true;
            break;
    case MK_RBUTTON: //Set Rotation flag
            mouseRotation = true;
            break;

    case MK_MBUTTON:
            break;
    }
}

void _KbMs::mouseEventUp()
{
    mouseRotation = false;
    mouseTranslation = false;
}

void _KbMs::mouseWheel(_Models* mdl, double delta)
{
    mdl->posZ += delta/100;
}

void _KbMs::mouseMove(_Models* mdl, double x, double y)
{
    if(mouseTranslation){
        mdl->posX += (x-prev_Mousex)/100.0;
        mdl->posY -= (y - prev_MouseY)/100.0;

    }
    //To-do
        //apply for rotations
            //using mouseWheel maybe?

        prev_Mousex = x;
        prev_MouseY = y;
}
void _KbMs::moveBck(_parallax* prlx, float speed)
{
    switch(wParam){
        case VK_LEFT:
                prlx->xMax -= speed;
                prlx->xMin -= speed;
                break;

        case VK_RIGHT:
                prlx->xMax += speed;
                prlx->xMin += speed;
                break;

            //todo
                //VK_DOWN
                //VK_UP

                //do Z-rotations
    }
}
void _KbMs::keyPress(_SkyBox* sky)
{
     switch(wParam){
        case VK_LEFT:
                sky->yRotation -= 1.0;
                break;

        case VK_RIGHT:
                sky->yRotation += 1.0;
                break;

            //todo
        case VK_DOWN:
                sky->xRotation += 1.0;
                break;

        case VK_UP:
                sky->xRotation -=1.0;
                break;

                //do Z-rotations
    }
}

void _KbMs::mouseMove(_SkyBox* sky, double, double)
{

}

void _KbMs::keyPress(_Skybox2* sky)
{
   switch(wParam){
        case VK_LEFT:
                sky->rot.y -= 1.0;
                break;

        case VK_RIGHT:
                sky->rot.y += 1.0;
                break;

            //todo
        case VK_DOWN:
                sky->rot.x += 1.0;
                break;

        case VK_UP:
                sky->rot.x -=1.0;
                break;

                //do Z-rotations
    }
}

void _KbMs::keyPress(_Camera* cam)
{
    switch(wParam){
        case 0x41: //A key
                cam->des.x -= 1.0;
                break;

        case 0x53: //S key
                cam->des.y -= 1.0;
                break;

            //todo
        case 0x57: //W key
                cam->des.y += 1.0;
                break;

        case 0x44: //D key
                cam->des.x += 1.0;
                break;

                //do Z-rotations
    }
}

void _KbMs::keyPress(_2DPlayer* pls)
{
   switch(wParam){
        case VK_LEFT:
                pls->actionTrigger = pls->WALKLEFT;
                break;

        case VK_RIGHT:
               pls->actionTrigger = pls->WALKRIGHT;
                break;

   }
}

void _KbMs::keyUp(_2DPlayer* pl)
{
    pl->actionTrigger = pl->STAND;
}



void _KbMs::mouseMove(_Skybox2* sky, double, double)
{

}

void _KbMs::mouseMove(_Camera* cam, double x, double y)
{

        cam->des.x += (x-prev_CamMousex)/3.0;
        cam->des.y -= (y - prev_CamMouseY)/3.0;

        //cout << "I got here! \n";

    //To-do
        //apply for rotations
            //using mouseWheel maybe?

        prev_CamMousex = x;
        prev_CamMouseY = y;
}




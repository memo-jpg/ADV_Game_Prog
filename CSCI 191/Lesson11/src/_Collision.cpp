#include "_Collision.h"

_Collision::_Collision()
{
    //ctor
}

_Collision::~_Collision()
{
    //dtor
}

bool _Collision::isLinearCollision(vec2, vec2)
{

}

bool _Collision::isRadialCollision(vec2 obj1, vec2 obj2, float r1, float r2, float threshold)
{
    return ( std::abs(r1+r2) - std::sqrt( std::pow(obj1.x-obj2.x,2)+std::pow(obj1.y-obj2.y,2) ) < threshold);
}

bool _Collision::isHitPlane(vec2, vec2)
{

}

bool _Collision::isCubicCollision(vec3, vec3)
{

}

bool _Collision::isSphereCollision(vec3 obj1, vec3 obj2, float r1, float r2, float threshold)
{
    return (std::abs((r1+r2)-std::sqrt( std::pow(obj1.x-obj2.x,2)+std::pow(obj1.y-obj2.y,2)+std::pow(obj1.z-obj2.z,2)) ) < threshold);
}

bool _Collision::isHitPlane3D(vec3, vec3)
{

}

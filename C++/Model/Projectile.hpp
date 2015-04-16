#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.hpp"

class Projectile: public Entity {
public:
    Projectile(const unsigned long _id);
    Projectile(const unsigned long _id, Azimuth _or);
    void forward();
protected:
};

#endif

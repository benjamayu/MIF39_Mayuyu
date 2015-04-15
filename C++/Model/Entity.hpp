#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    Entity (long _id);
    long getId();
    long getX();
    long setX(long _x);
    long getY();
    long setY(long _y);
    long getZ();
    long setZ(long _z);
protected:
    long id;
    long x;
    long y;
    long z;
};

#endif

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    Entity (const unsigned long _id);
    const unsigned long getId();
    long getX();
    void setX(long _x);
    long getY();
    void setY(long _y);
    long getZ();
    void setZ(long _z);
    float getDirection();
    void setDirection(float _direction);
protected:
    const unsigned long id;
    long x,y,z;
    float direction;
};

#endif

#ifndef ENTITY_H
#define ENTITY_H

typedef enum {
    North,
    East,
    South,
    West
} Azimuth;

class Entity {
public:
    Entity (const unsigned long _id);
    const unsigned long getId();
    long getX();
    void setX(long _x);
    long getY();
    void setY(long _y);
    Azimuth getOrientation();
    void setOrientation(Azimuth _orientation);
    void goNorth(int speed);
    void goEast(int speed);
    void goSouth(int speed);
    void goWest(int speed);
protected:
    const unsigned long id;
    long x,y;
    Azimuth orientation;
};

#endif

#ifndef ENTITY_H
#define ENTITY_H

#include "Point.hpp"

typedef enum {
    North,
    East,
    South,
    West
} Azimuth;

class Entity {
public:
    Entity();
    Entity (const unsigned long _id);
    const unsigned long getId();
    Azimuth getOrientation();
    void setOrientation(Azimuth _orientation);
    Point getCoords();
    void setCoords(long _x, long _y);
    void setCoords(Point p);
    Point getNext();
    void setNext(long _x, long _y);
    void setNext(Point p);
    void goNorth(int speed);
    void goEast(int speed);
    void goSouth(int speed);
    void goWest(int speed);
protected:
    const unsigned long id;
    Point coords;
    Point next;
    Azimuth orientation;
};

#endif

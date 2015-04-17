#include "Entity.hpp"
#include <math.h>

Entity::Entity() : id(0) {}

Entity::Entity(const unsigned long _id) : id(_id) {}

const unsigned long Entity::getId(){
	return id;
}

Azimuth Entity::getOrientation(){
    return orientation;
}

void Entity::setOrientation(Azimuth _orientation){
    orientation=_orientation;
}

Point Entity::getCoords() {
    return coords;
}

void Entity::setCoords(long _x, long _y) {
    coords.setX(_x);
    coords.setY(_y);
}

void Entity::setCoords(Point p) {
    coords = p;
}

Point Entity::getNext() {
    return next;
}

void Entity::setNext(long _x, long _y) {
    next.setX(_x);
    next.setY(_y);
}

void Entity::setNext(Point p) {
    next = p;
}

void Entity::goNorth(int speed) {
    coords.setY(coords.getY()+speed);
}

void Entity::goEast(int speed) {
    coords.setX(coords.getX()+speed);
}

void Entity::goSouth(int speed) {
    coords.setY(coords.getY()-speed);
}

void Entity::goWest(int speed) {
    coords.setX(coords.getX()-speed);
}

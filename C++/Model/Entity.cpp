#include "Entity.hpp"
#include <math.h>

Entity::Entity(const unsigned long _id) : id(_id) {}

const unsigned long Entity::getId(){
	return id;
}

long Entity::getX(){
	return x;
}

void Entity::setX(long _x){
	x=_x;
}

long Entity::getY(){
	return y;
}

void Entity::setY(long _y){
	y=_y;
}

Azimuth Entity::getOrientation(){
    return orientation;
}

void Entity::setOrientation(Azimuth _orientation){
    orientation=_orientation;
}

void Entity::goNorth(int speed) {
    y+=speed;
}

void Entity::goEast(int speed) {
    x+=speed;
}

void Entity::goSouth(int speed) {
    y-=speed;
}

void Entity::goWest(int speed) {
    x-=speed;
}

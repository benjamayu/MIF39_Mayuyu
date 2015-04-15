#include "Entity.hpp"

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

long Entity::getZ(){
	return z;
}

void Entity::setZ(long _z){
	z=_z;
}

float Entity::getOrientation(){
    return orientation;
}
void Entity::setOrientation(float _orientation){
    orientation=_orientation;
}

#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const unsigned long _id) : NPC(_id) {}

unsigned long Animal::getMaster() {
    return master;
}

void Animal::setMaster(unsigned long _master) {
    master = _master;
}

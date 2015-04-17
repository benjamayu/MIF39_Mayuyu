#ifndef ANIMAL_H
#define ANIMAL_H

#include "NPC.hpp"

class Animal : public NPC {
public:
    Animal();
    Animal(const unsigned long _id);
    unsigned long getMaster();
    void setMaster(unsigned long _master);
protected:
    unsigned long master;
};

#endif

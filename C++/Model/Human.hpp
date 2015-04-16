#ifndef HUMAN_H
#define HUMAN_H

#include "NPC.hpp"

class Human : public NPC {
public:
    Human(const unsigned long _id);
    unsigned int getStamina();
    void setStamina(unsigned int _stamina);
protected:
    unsigned int stamina;
};

#endif

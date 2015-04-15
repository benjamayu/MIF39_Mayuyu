#ifndef HUMAN_H
#define HUMAN_H

#include "NPC.hpp"

class Human : public NPC {
public:
    Human(const unsigned long _id);
    unsigned int getStamina();
    void setStamina(unsigned int _stamina);
    unsigned int getFear();
    void setFear(unsigned int _fear);
protected:
    unsigned int stamina, fear;
};

#endif

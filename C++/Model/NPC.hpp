#ifndef NPC_H
#define NPC_H

#include "Entity.hpp"

class NPC : public Entity {
public:
	NPC(const unsigned long _id);
    int getHp();
    void setHp(int _hp);
protected:
    int hp;
};

#endif

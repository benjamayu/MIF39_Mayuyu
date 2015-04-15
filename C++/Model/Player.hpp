#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"

class Player : public Entity {
public:
    Player(const unsigned long _id);
    unsigned int getStamina();
    void setStamina(unsigned int _Stamina);
    unsigned int getScore();
    void setScore(unsigned int _score);
protected:
    unsigned int stamina,score;
};

#endif

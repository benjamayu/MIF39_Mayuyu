#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"
#include <string>

class Player : public Entity {
public:
    Player();
    Player(const unsigned long _id);
    unsigned int getStamina();
    void setStamina(unsigned int _Stamina);
    unsigned int getScore();
    void setScore(unsigned int _score);
    std::string getName();
    void scoreUp();
    void staminaUp();
    void staminaDown();
    void shot();
protected:
    unsigned int stamina, score;
    std::string name;
};

#endif

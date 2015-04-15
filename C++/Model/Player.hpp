#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity {
public:
    Player();
    unsigned int getStamina();
    void setStamina(unsigned int _Stamina);
    unsigned int getScore();
    void setScore(unsigned int _score);
protected:
    unsigned int stamina,score;
};

#endif

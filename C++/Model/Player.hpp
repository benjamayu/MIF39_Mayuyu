#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity {
public:
    Player();
    unsigned int getFatigue();
    void setFatigue(unsigned int _fatigue);
    unsigned int getScore();
    void setScore(unsigned int _score);
protected:
    unsigned int fatigue,score;
};

#endif

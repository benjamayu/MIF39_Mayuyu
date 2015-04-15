#include "Player.hpp"

Player::Player() : fatigue(100),score(0) {}
unsigned int Player::getStamina(){
    return stamina;
}
void Player::setStamina(unsigned int _stamina){
    stamina=_stamina;
}
unsigned int Player::getScore(){
	return score;
}
void Player::setScore(unsigned int _score){
	score=_score;
}

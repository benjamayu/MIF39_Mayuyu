#include "Player.hpp"

Player::Player() : fatigue(0),score(0) {}
unsigned int Player::getFatigue(){
	return fatigue;
}
void Player::setFatigue(unsigned int _fatigue){
	fatigue=_fatigue;
}
unsigned int Player::getScore(){
	return score;
}
void Player::setScore(unsigned int _score){
	score=_score;
}

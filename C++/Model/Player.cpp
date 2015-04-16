#include "Player.hpp"
#include "Projectile.hpp"

Player::Player(const unsigned long _id) : stamina(100),score(0),Entity::Entity(_id) {}

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

void Player::scoreUp() {
   score++;
}

void Player::staminaUp() {
    stamina++;
    if (stamina > 100)
        stamina = 100;
}

void Player::staminaDown() {
    stamina--;
    if(stamina < 0)
        stamina = 0;
}

void Player::shot() {
    Projectile(1, orientation);
}

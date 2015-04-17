#include "Human.hpp"

Human::Human() {}

Human::Human(const unsigned long _id) : NPC(_id),stamina(100) {}

unsigned int Human::getStamina(){
    return stamina;
}

void Human::setStamina(unsigned int _stamina){
    stamina=_stamina;
}

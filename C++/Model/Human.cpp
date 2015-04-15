#include "Human.hpp"

Human::Human(const unsigned long _id) : NPC(_id),stamina(100),fear(0) {}

unsigned int Human::getStamina(){
    return stamina;
}
void Human::setStamina(unsigned int _stamina){
    stamina=_stamina;
}
unsigned int Human::getFear(){
    return fear;
}
void Human::setFear(unsigned int _fear){
    fear=_fear;
}

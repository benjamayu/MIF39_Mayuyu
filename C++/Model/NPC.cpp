#include "NPC.hpp"

NPC::NPC() {}

NPC::NPC(const unsigned long _id) : Entity(_id) {}

int NPC::getHp() {
    return hp;
}

void NPC::setHp(int _hp) {
    hp = _hp;
}

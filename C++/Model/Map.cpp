#include "Map.hpp"

Map::Map(){}
Map::Map(unsigned long _width,unsigned long _height) : width(_width),height(_height) {}

unsigned long Map::getWidth(){
    return width;
}
void Map::setWidth(unsigned long _width){
    width=_width;
}
unsigned long Map::getHeight(){
    return height;
}
void Map::setHeight(unsigned long _height){
    height=_height;
}

void Map::addPlayer(Player player) {
    mapPlayer.insert(std::pair<unsigned int, Player>(player.getId(), player));
}

void Map::removePlayer(unsigned long id) {
    mapPlayer.erase(id);
}

Player Map::getPlayer(unsigned long id) {
    return mapPlayer.at(id);
}

void Map::addNPC(NPC npc) {
    mapNPC.insert(std::pair<unsigned int, NPC>(npc.getId(), npc));
}

void Map::removeNPC(unsigned long id) {
    mapNPC.erase(id);
}

NPC Map::getNPC(unsigned long id) {
    return mapNPC.at(id);
}

void Map::addProjectile(Projectile projectile) {
    mapProjectile.insert(std::pair<unsigned int, Projectile>(projectile.getId(), projectile));
}

void Map::removeProjectile(unsigned long id) {
    mapProjectile.erase(id);
}

Projectile Map::getProjectile(unsigned long id) {
    return mapProjectile.at(id);
}

void Map::moveProjectiles() {
    std::map<unsigned long, Projectile>::iterator it;
    for(it = mapProjectile.begin();it != mapProjectile.end(); ++it)
    {
        it->second.forward();
    }
}

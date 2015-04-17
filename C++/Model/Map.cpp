#include "Map.hpp"

Map::Map(){}
Map::Map(unsigned long _width,unsigned long _height) :
width(_width), height(_height), nbPlayer(0), nbNPC(0), nbProjectile(0){}

Map::~Map() {
    std::map<unsigned long, Player*>::iterator itPlayer;
    for(itPlayer = mapPlayer.begin();itPlayer != mapPlayer.end(); ++itPlayer)
    {
        delete itPlayer->second;
    }
    std::map<unsigned long, NPC*>::iterator itNPC;
    for(itNPC = mapNPC.begin();itNPC != mapNPC.end(); ++itNPC)
    {
        delete itNPC->second;
    }
    std::map<unsigned long, Projectile*>::iterator itProjectile;
    for(itProjectile = mapProjectile.begin();itProjectile != mapProjectile.end(); ++itProjectile)
    {
        delete itProjectile->second;
    }
}

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

void Map::addPlayer(Player* player) {
    mapPlayer.insert(std::pair<unsigned long, Player*>(player->getId(), player));
}

void Map::removePlayer(unsigned long id) {
    delete Map::getPlayer(id);
    mapPlayer.erase(id);
}

Player* Map::getPlayer(unsigned long id) {
    return mapPlayer.at(id);
}

void Map::addNPC(NPC* npc) {
    mapNPC.insert(std::pair<unsigned long, NPC*>(npc->getId(), npc));
}

void Map::removeNPC(unsigned long id) {
    delete Map::getNPC(id);
    mapNPC.erase(id);
}

NPC* Map::getNPC(unsigned long id) {
    return mapNPC.at(id);
}

void Map::addProjectile(Projectile* projectile) {
    mapProjectile.insert(std::pair<unsigned long, Projectile*>(projectile->getId(), projectile));
}

void Map::removeProjectile(unsigned long id) {
    delete Map::getProjectile(id);
    mapProjectile.erase(id);
}

Projectile* Map::getProjectile(unsigned long id) {
    return mapProjectile.at(id);
}

template <typename T> void updatePosition(T t, Azimuth orientation) {
    switch(orientation) {
        case North:
            t.goNorth();
            break;
        case East:
            t.goEast();
            break;
        case South:
            t.goSouth();
            break;
        case North:
            t.goWest();
            break;
    }
}

void Map::moveProjectiles() {
    std::map<unsigned long, Projectile*>::iterator it;
    for(it = mapProjectile.begin();it != mapProjectile.end(); ++it)
    {
        it->second->forward();
    }
}

unsigned int Map::getNbPlayer() {
    return nbPlayer;
}

void Map::setNbPlayer(unsigned int nb){
    nbPlayer = nb;
}

void Map::nbPlayerUp(){
    nbPlayer++;
}

unsigned int Map::getNbNPC(){
    return nbNPC;
}

void Map::setNbNPC(unsigned int nb){
    nbNPC = nb;
}

void Map::nbNPCUp(){
    nbNPC++;
}

unsigned int Map::getNbProjectile(){
    return nbProjectile;
}

void Map::setNbProjectile(unsigned int nb){
    nbProjectile = nb;
}

void Map::nbProjectileUp(){
    nbProjectile++;
}

void Map::iteration() {

}

#ifndef MAP_H
#define MAP_H

#include <map>
#include "Player.hpp"
#include "NPC.hpp"
#include "Projectile.hpp"

class Map {
public:
    Map();
    Map(unsigned long _width,unsigned long _height);
    unsigned long getWidth();
    void setWidth(unsigned long _width);
    unsigned long getHeight();
    void setHeight(unsigned long _height);
    void addPlayer(Player player);
    void removePlayer(unsigned long id);
    Player getPlayer(unsigned long id);
    void addNPC(NPC npc);
    void removeNPC(unsigned long id);
    NPC getNPC(unsigned long id);
    void addProjectile(Projectile projectile);
    void removeProjectile(unsigned long id);
    Projectile getProjectile(unsigned long id);

protected:
    void moveProjectiles();
    unsigned long width,height;
    std::map<unsigned long, Player> mapPlayer;
    std::map<unsigned long, NPC> mapNPC;
    std::map<unsigned long, Projectile> mapProjectile;
};

#endif

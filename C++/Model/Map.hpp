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
    ~Map();

    unsigned long getWidth();
    void setWidth(unsigned long _width);
    unsigned long getHeight();
    void setHeight(unsigned long _height);

    void addPlayer(Player* player);
    void removePlayer(unsigned long id);
    Player* getPlayer(unsigned long id);

    void addNPC(NPC* npc);
    void removeNPC(unsigned long id);
    NPC* getNPC(unsigned long id);

    void addProjectile(Projectile* projectile);
    void removeProjectile(unsigned long id);
    Projectile* getProjectile(unsigned long id);

    unsigned int getNbPlayer();
    void setNbPlayer(unsigned int nb);
    void nbPlayerUp();

    unsigned int getNbNPC();
    void setNbNPC(unsigned int nb);
    void nbNPCUp();

    unsigned int getNbProjectile();
    void setNbProjectile(unsigned int nb);
    void nbProjectileUp();

    void iteration();

protected:
    unsigned long id;   //num dans le vector dans Game
    unsigned long width,height;
    std::map<unsigned long, Player*> mapPlayer;
    unsigned int nbPlayer;
    std::map<unsigned long, NPC*> mapNPC;
    unsigned int nbNPC;
    std::map<unsigned long, Projectile*> mapProjectile;
    unsigned int nbProjectile;


    void moveProjectiles();
};

#endif

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Map.hpp"

class Game {
public:
     Game();
//     Map & getMap();
//     std::vector<Player> & getPlayers();
//     std::vector<NPC> & getNPC();
//     void addPlayer(const Player & _player);
//     void addNPC(const NPC & _npc);
protected:
     std::vector<Map> meshMap;
//     std::vector<Player> players;
//     std::vector<NPC> npc;
};

#endif

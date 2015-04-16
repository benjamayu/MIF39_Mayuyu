#include "Game.hpp"

Game::Game() {}

Map & Game::getMap(){
     return map;
}

std::vector<Player> & Game::getPlayers(){
     return players;
}
std::vector<NPC> & Game::getNPC(){
     return npc;
}

void Game::addPlayer(const Player & _player){
     players.push_back(_player);
}
void Game::addNPC(const NPC & _npc){
     npc.push_back(_npc);
}

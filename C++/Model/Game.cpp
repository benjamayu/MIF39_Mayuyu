#include "Game.hpp"
#include <iostream>

Game::Game() {}

Map Game::getMap(int id) {
    if(id < meshMap.size())
        return meshMap[id];
    else {
        std::cout << "Error" << std::endl;
        exit(1);
    }
}

void play() {
    while(true) {
    //MAYUYU
    }
}

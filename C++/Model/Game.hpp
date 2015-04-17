#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Map.hpp"

class Game {
public:
    Game();
//     Map & getMap();
    Map getMap(int id);
    void play();
protected:
    std::vector<Map> meshMap;
};

#endif

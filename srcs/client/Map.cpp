//
// Map.cpp for  in /Users/antoinegalpin/PSU_2016_zappy/srcs/client/
//
// Made by Antoine Galpin
// Login   <antoine.galpin@epitech.eu>
//
// Started on  Wed Jun 21 03:19:58 2017 Antoine Galpin
// Last update Wed Jun 21 03:24:38 2017 Antoine Galpin
//

#include "../../include/Map.hpp"
#include <sstream>

Map::Map(int x, int y) {
  _x = x;
  _y = y;
  std::stringstream buff;
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      buff << 'x';
    }
    _map.push_back(buff.str());
    buff.str().clear();
  }
}

const std::vector<std::string> Map::getMap() const { return _map; }

void Map::dumpMap() {
  for (int i = 0; i < _y; i++) {
    for (int j = 0; j < _x; j++) {
      std::cout << _map[i][j];
    }
    std::cout << std::endl;
  }
}

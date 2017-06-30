//
// Map.cpp for  in /Users/antoinegalpin/PSU_2016_zappy/srcs/client/
//
// Made by Antoine Galpin
// Login   <antoine.galpin@epitech.eu>
//
// Started on  Wed Jun 21 03:17:50 2017 Antoine Galpin
// Last update Wed Jun 21 03:24:00 2017 Antoine Galpin
//

#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include <string>
#include <vector>

class Map {
public:
  Map(int x, int y);
  const std::vector<std::string> getMap() const;
  void dumpMap();

private:
  int _x;
  int _y;
  std::vector<std::string> _map;
};

#endif

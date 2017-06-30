//
// client.hpp for  in /Users/antoinegalpin/PSU_2016_zappy/include/
//
// Made by Antoine Galpin
// Login   <antoine.galpin@epitech.eu>
//
// Started on  Tue Jun 13 22:09:04 2017 Antoine Galpin
// Last update Fri Jun 30 00:55:17 2017 Antoine Galpin
//

#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include "Map.hpp"
#include "Socket.hpp"
#include "my_getline.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <map>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

class Client {
public:
  Client(int fd);
  ~Client();
  std::vector<std::string> sendToServerOne(const std::string &message);
  std::vector<std::string> sendToServerMultiple(const std::string &message);

  const std::vector<std::string> getParse(char *buff) const;
  void mainloop();
  void initWindow(std::vector<std::string> elems);
  void updateMap(const std::vector<std::string> &datas);
  void updatePokemons(const std::vector<std::string> &datas);
  void initMap(int x, int y);
  void dumpMap();
  void display();
  void initSprites(std::string size);
  void initPikachu(const std::string &name, const std::string &size);
  void initLugia(const std::string &name, const std::string &size);
  void initMewtwo(const std::string &name, const std::string &size);
  void initDracaufeu(const std::string &name, const std::string &size);
  void initRaichu(const std::string &name, const std::string &size);
  void initPyroli(const std::string &name, const std::string &size);
  void initMentaly(const std::string &name, const std::string &size);
  void initTenefix(const std::string &name, const std::string &size);
  void initHerbizarre(const std::string &name, const std::string &size);
  void getLvl();
  void getInventory();
  void clean_map(int x, int y, char c);
  void coutNbOfElems();

private:
  int _fd;
  sf::RenderWindow _window;
  std::vector<std::string> _mapR;
  std::vector<std::string> _mapP;
  int _x;
  int _y;
  int _size;

  /* TEXTURES */
  sf::Texture _floor;
  sf::Texture _food;

  std::vector<sf::Texture> _pikachu;
  std::vector<sf::Texture> _luguia;
  std::vector<sf::Texture> _mewtwo;
  std::vector<sf::Texture> _dracaufeu;
  std::vector<sf::Texture> _raichu;
  std::vector<sf::Texture> _pyroli;
  std::vector<sf::Texture> _mentaly;
  std::vector<sf::Texture> _tenefix;
  std::vector<sf::Texture> _herbizarre;
  sf::Texture _inventory;
  sf::Texture _linemate;
  sf::Texture _deraumere;
  sf::Texture _sibur;
  sf::Texture _mendiane;
  sf::Texture _phiras;
  sf::Texture _thystame;
  sf::Texture _ressources;
  sf::Texture _nbOfPok;

  /* SPRITES */
  sf::Sprite _spriteInventory;
  sf::Sprite _spriteFloor;
  sf::Sprite _spriteFood;
  sf::Sprite _spriteLinemate;
  sf::Sprite _spriteDeraumere;
  sf::Sprite _spriteSibur;
  sf::Sprite _spriteMendiane;
  sf::Sprite _spritePhiras;
  sf::Sprite _spriteThystame;
  sf::Sprite _spriteRessources;
  sf::Sprite _spriteNbOfPok;

  /* DIRECTION */
  int pikachuDir;
  int luguiaDir;
  int mewtowDir;
  int dracaufeuDir;
  int raichuDir;
  int pyroliDir;
  int mentalyDir;
  int tenefixDir;
  int herbizarreDir;

  /* TEXT */
  std::vector<std::string> _textInventory;
  sf::Text _pikachuInventory;
  sf::Text _luguiaInventory;
  sf::Text _mewtwoInventory;
  sf::Text _dracaufeuInventory;
  sf::Text _RaichuInventory;
  sf::Text _pyroliInventory;
  sf::Text _mentalyInventory;
  sf::Text _TenefixInventory;
  sf::Text _herbizarreInventory;
  sf::Text _nbOfRessources;
  // sf::Text _nbOfPokText;

  /* FONT */
  sf::Font _font;

  /* COUNTERS */
  int nbOfpokValue;
  int nbOfRessourcesValue;
};

#endif

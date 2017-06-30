//
// client.cpp for  in /Users/antoinegalpin/PSU_2016_zappy/srcs/client/
//
// Made by Antoine Galpin
// Login   <antoine.galpin@epitech.eu>
//
// Started on  Tue Jun 13 22:10:30 2017 Antoine Galpin
// Last update Fri Jun 30 01:40:07 2017 Antoine Galpin
//

#include "../../include/client.hpp"
#include <stdlib.h>
#include <string.h>
#include <thread>

sf::Text _nbOfPokText;
bool firstWindow = false;

Client::Client(int fd) {
  write(fd, "GRAPHIC\n", 8);
  _fd = fd;
  pikachuDir = 1;
  luguiaDir = 1;
  mewtowDir = 1;
  dracaufeuDir = 1;
  raichuDir = 1;
  pyroliDir = 1;
  mentalyDir = 1;
  tenefixDir = 1;
  herbizarreDir = 1;
  nbOfpokValue = 0;
  for (auto i = 0; i <= 9; i++) {
    _textInventory.push_back("0 0 0 0 0 0 0");
  }
  if (!_font.loadFromFile("font/font.ttf"))
    exit(-1);
  _pikachuInventory.setFont(_font);
  _pikachuInventory.setColor(sf::Color::White);
  _pikachuInventory.setPosition(sf::Vector2f(70, 1015));

  _luguiaInventory.setFont(_font);
  _luguiaInventory.setColor(sf::Color::White);
  _luguiaInventory.setPosition(sf::Vector2f(70, 1080));

  _mewtwoInventory.setFont(_font);
  _mewtwoInventory.setColor(sf::Color::White);
  _mewtwoInventory.setPosition(sf::Vector2f(70, 1145));

  _dracaufeuInventory.setFont(_font);
  _dracaufeuInventory.setColor(sf::Color::White);
  _dracaufeuInventory.setPosition(sf::Vector2f(440, 1015));

  _RaichuInventory.setFont(_font);
  _RaichuInventory.setColor(sf::Color::White);
  _RaichuInventory.setPosition(sf::Vector2f(440, 1080));

  _pyroliInventory.setFont(_font);
  _pyroliInventory.setColor(sf::Color::White);
  _pyroliInventory.setPosition(sf::Vector2f(440, 1145));

  _mentalyInventory.setFont(_font);
  _mentalyInventory.setColor(sf::Color::White);
  _mentalyInventory.setPosition(sf::Vector2f(790, 1015));

  _TenefixInventory.setFont(_font);
  _TenefixInventory.setColor(sf::Color::White);
  _TenefixInventory.setPosition(sf::Vector2f(790, 1080));

  _herbizarreInventory.setFont(_font);
  _herbizarreInventory.setColor(sf::Color::White);
  _herbizarreInventory.setPosition(sf::Vector2f(790, 1145));

  _nbOfRessources.setFont(_font);
  _nbOfRessources.setColor(sf::Color::White);
  _nbOfRessources.setCharacterSize(72);
  _nbOfRessources.setPosition(sf::Vector2f(250, 1050));

  _nbOfPokText.setFont(_font);
  _nbOfPokText.setColor(sf::Color::White);
  _nbOfPokText.setCharacterSize(72);
  _nbOfPokText.setPosition(sf::Vector2f(860, 1050));

  _pikachuInventory.setString(_textInventory[1]);
  _luguiaInventory.setString(_textInventory[2]);
  _mewtwoInventory.setString(_textInventory[3]);
  _dracaufeuInventory.setString(_textInventory[4]);
  _RaichuInventory.setString(_textInventory[5]);
  _pyroliInventory.setString(_textInventory[6]);
  _mentalyInventory.setString(_textInventory[7]);
  _TenefixInventory.setString(_textInventory[8]);
  _herbizarreInventory.setString(_textInventory[9]);
  _nbOfRessources.setString("0");
  _nbOfPokText.setString("0");
}

const std::vector<std::string> Client::getParse(char *buff) const {
  std::istringstream f(buff);
  std::vector<std::string> elems;
  std::string tmp;
  while (std::getline(f, tmp, ' '))
    elems.push_back(tmp);
  return elems;
}

std::vector<std::string>
Client::sendToServerMultiple(const std::string &message) {
  struct timeval timeout;
  std::vector<std::string> datas;
  write(_fd, message.c_str(), strlen(message.c_str()));
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(_fd, &fds);
  while (1) {
    timeout.tv_sec = 0;
    timeout.tv_usec = 10000;
    if (select(_fd + 1, &fds, 0, 0, &timeout) == 1) {
      char *buff;
      if ((buff = my_getline(_fd)) == NULL)
        buff = strdup("unknow");
      datas.push_back(buff);
    } else
      break;
  }
  return datas;
}

std::vector<std::string> Client::sendToServerOne(const std::string &message) {
  std::vector<std::string> datas;
  struct timeval timeout;

  write(_fd, message.c_str(), strlen(message.c_str()));
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(_fd, &fds);
  timeout.tv_sec = 0;
  timeout.tv_usec = 10000;
  if (select(_fd + 1, &fds, 0, 0, &timeout) == 1) {
    char *buff;
    if ((buff = my_getline(_fd)) == NULL)
      buff = strdup("unknow");
    std::istringstream f(buff);
    std::string tmp;
    while (std::getline(f, tmp, ' ')) {
      datas.push_back(tmp);
    }
  } else {
    std::string test("unknown");
    datas.push_back(test);
    return datas;
  }
  return datas;
}

void Client::initPikachu(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_pikachu[i].loadFromFile(namePath))
      exit(-1);
    _pikachu[i].setSmooth(true);
  }
}

void Client::initLugia(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_luguia[i].loadFromFile(namePath))
      exit(-1);
    _luguia[i].setSmooth(true);
  }
}

void Client::initMewtwo(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_mewtwo[i].loadFromFile(namePath))
      exit(-1);
    _mewtwo[i].setSmooth(true);
  }
}

void Client::initDracaufeu(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_dracaufeu[i].loadFromFile(namePath))
      exit(-1);
    _dracaufeu[i].setSmooth(true);
  }
}

void Client::initRaichu(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_raichu[i].loadFromFile(namePath))
      exit(-1);
    _raichu[i].setSmooth(true);
  }
}

void Client::initPyroli(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_pyroli[i].loadFromFile(namePath))
      exit(-1);
    _pyroli[i].setSmooth(true);
  }
}

void Client::initMentaly(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_mentaly[i].loadFromFile(namePath))
      exit(-1);
    _mentaly[i].setSmooth(true);
  }
}

void Client::initTenefix(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_tenefix[i].loadFromFile(namePath))
      exit(-1);
    _tenefix[i].setSmooth(true);
  }
}

void Client::initHerbizarre(const std::string &name, const std::string &size) {
  std::vector<std::string> dir;

  dir.push_back("/face.png");
  dir.push_back("/back.png");
  dir.push_back("/left.png");
  dir.push_back("/right.png");
  for (int i = 0; i < 4; i++) {
    std::string namePath;
    namePath = "assets/pokemons/";
    namePath += name;
    namePath += "/";
    namePath += size;
    namePath += dir[i];
    if (!_herbizarre[i].loadFromFile(namePath))
      exit(-1);
    _herbizarre[i].setSmooth(true);
  }
}

void Client::initSprites(std::string size) {
  std::string namePathFloor;
  std::string namePathFood;
  std::string namePathLinemate;
  std::string namePathDeraumere;
  std::string namePathSibur;
  std::string namePathMendiane;
  std::string namePathPhiras;
  std::string namePathThystame;

  namePathFloor = "assets/floor/";
  namePathFloor += size;
  namePathFloor += "_floor.png";

  namePathFood = "assets/elems/food/";
  namePathFood += size;
  namePathFood += "_food.png";

  namePathLinemate = "assets/elems/linemate/";
  namePathLinemate += size;
  namePathLinemate += ".png";

  namePathDeraumere = "assets/elems/deraumere/";
  namePathDeraumere += size;
  namePathDeraumere += ".png";

  namePathSibur = "assets/elems/sibur/";
  namePathSibur += size;
  namePathSibur += ".png";

  namePathMendiane = "assets/elems/mendiane/";
  namePathMendiane += size;
  namePathMendiane += ".png";

  namePathPhiras = "assets/elems/phiras/";
  namePathPhiras += size;
  namePathPhiras += ".png";

  namePathThystame = "assets/elems/thystame/";
  namePathThystame += size;
  namePathThystame += ".png";

  if (!_floor.loadFromFile(namePathFloor))
    exit(-1);
  if (!_food.loadFromFile(namePathFood))
    exit(-1);
  if (!_linemate.loadFromFile(namePathLinemate))
    exit(-1);
  if (!_deraumere.loadFromFile(namePathDeraumere))
    exit(-1);
  if (!_sibur.loadFromFile(namePathSibur))
    exit(-1);
  if (!_mendiane.loadFromFile(namePathMendiane))
    exit(-1);
  if (!_phiras.loadFromFile(namePathPhiras))
    exit(-1);
  if (!_thystame.loadFromFile(namePathThystame))
    exit(-1);
  if (!_inventory.loadFromFile("assets/inventory/inventory.png"))
    exit(-1);
  if (!_ressources.loadFromFile("assets/inventory/ressources.png"))
    exit(-1);
  if (!_nbOfPok.loadFromFile("assets/inventory/nbOfpok.png"))
    exit(-1);
  _spriteInventory.setTexture(_inventory);
  _spriteFloor.setTexture(_floor);
  _spriteFood.setTexture(_food);
  _spriteLinemate.setTexture(_linemate);
  _spriteDeraumere.setTexture(_deraumere);
  _spriteSibur.setTexture(_sibur);
  _spriteMendiane.setTexture(_mendiane);
  _spritePhiras.setTexture(_phiras);
  _spriteThystame.setTexture(_thystame);
  _spriteRessources.setTexture(_ressources);
  _spriteNbOfPok.setTexture(_nbOfPok);

  _pikachu.reserve(4);
  _luguia.reserve(4);
  _mewtwo.reserve(4);
  _dracaufeu.reserve(4);
  _raichu.reserve(4);
  _pyroli.reserve(4);
  _mentaly.reserve(4);
  _tenefix.reserve(4);
  _herbizarre.reserve(4);
  initPikachu("pikachu", size);
  initLugia("luguia", size);
  initMewtwo("mewtwo", size);
  initDracaufeu("dracaufeu", size);
  initRaichu("raichu", size);
  initPyroli("pyroli", size);
  initMentaly("mentaly", size);
  initTenefix("tenefix", size);
  initHerbizarre("herbizarre", size);
}

void Client::initWindow(std::vector<std::string> elems) {
  _x = std::stoi(elems[1]);
  _y = std::stoi(elems[2]);
  Map map(std::stoi(elems[1]), std::stoi(elems[2]));
  map.dumpMap();
  _mapR = map.getMap();
  Map mapP(std::stoi(elems[1]), std::stoi(elems[2]));
  mapP.dumpMap();
  _mapP = map.getMap();
  int size = 0;
  std::string sizeString;
  if (std::stoi(elems[1]) <= 10 && std::stoi(elems[2]) <= 10) {
    size = 100;
    sizeString = "100";
  } else if ((std::stoi(elems[1]) > 10 && std::stoi(elems[1]) <= 20) &&
             (std::stoi(elems[2]) > 10 && std::stoi(elems[2]) <= 20)) {
    size = 50;
    sizeString = "50";
  } else if ((std::stoi(elems[1]) > 20 && std::stoi(elems[1]) <= 30) &&
             (std::stoi(elems[2]) > 20 && std::stoi(elems[2]) <= 30)) {
    size = 33;
    sizeString = "33";
  } else {
    size = 33;
    sizeString = "33";
  }
  int x = std::stoi(elems[1]) * size;
  int y = std::stoi(elems[2]) * size + 200;
  initSprites(sizeString);
  _size = size;
  _window.create(sf::VideoMode(x, y), "Zappy");
}

void Client::display() {
  _spriteInventory.setPosition(0, 1000);
  _spriteRessources.setPosition(0, 1000);
  _spriteNbOfPok.setPosition(0, 1000);
  for (size_t i = 0; i < _mapR.size(); i++) {
    for (size_t j = 0; j < _mapR[i].size(); j++) {
      if (_mapR[i][j] == 'x') {
        _spriteFloor.setPosition(j * _size, i * _size);
        _window.draw(_spriteFloor);
      }
      if (_mapR[i][j] == 'F') {
        _spriteFood.setPosition(j * _size, i * _size);
        _window.draw(_spriteFood);
      }
      if (_mapR[i][j] == 'L') {
        _spriteLinemate.setPosition(j * _size, i * _size);
        _window.draw(_spriteLinemate);
      }
      if (_mapR[i][j] == 'D') {
        _spriteDeraumere.setPosition(j * _size, i * _size);
        _window.draw(_spriteDeraumere);
      }
      if (_mapR[i][j] == 'S') {
        _spriteSibur.setPosition(j * _size, i * _size);
        _window.draw(_spriteSibur);
      }
      if (_mapR[i][j] == 'M') {
        _spriteMendiane.setPosition(j * _size, i * _size);
        _window.draw(_spriteMendiane);
      }
      if (_mapR[i][j] == 'P') {
        _spritePhiras.setPosition(j * _size, i * _size);
        _window.draw(_spritePhiras);
      }
      if (_mapR[i][j] == 'T') {
        _spriteThystame.setPosition(j * _size, i * _size);
        _window.draw(_spriteThystame);
      }
      if (_mapP[i][j] == '1') {
        sf::Sprite tmp;
        tmp.setTexture(_pikachu[pikachuDir]);
        tmp.setPosition(j * _size, i * _size);
        _window.draw(tmp);
      }
      if (_mapP[i][j] == '2') {
        sf::Sprite tmp2;
        tmp2.setTexture(_luguia[luguiaDir]);
        tmp2.setPosition(j * _size, i * _size);
        _window.draw(tmp2);
      }
      if (_mapP[i][j] == '3') {
        sf::Sprite tmp3;
        tmp3.setTexture(_mewtwo[mewtowDir]);
        tmp3.setPosition(j * _size, i * _size);
        _window.draw(tmp3);
      }
      if (_mapP[i][j] == '4') {
        sf::Sprite tmp4;
        tmp4.setTexture(_dracaufeu[dracaufeuDir]);
        tmp4.setPosition(j * _size, i * _size);
        _window.draw(tmp4);
      }
      if (_mapP[i][j] == '5') {
        sf::Sprite tmp5;
        tmp5.setTexture(_raichu[dracaufeuDir]);
        tmp5.setPosition(j * _size, i * _size);
        _window.draw(tmp5);
      }
      if (_mapP[i][j] == '6') {
        sf::Sprite tmp6;
        tmp6.setTexture(_pyroli[pyroliDir]);
        tmp6.setPosition(j * _size, i * _size);
        _window.draw(tmp6);
      }
      if (_mapP[i][j] == '7') {
        sf::Sprite tmp6;
        tmp6.setTexture(_mentaly[mentalyDir]);
        tmp6.setPosition(j * _size, i * _size);
        _window.draw(tmp6);
      }
      if (_mapP[i][j] == '8') {
        sf::Sprite tmp6;
        tmp6.setTexture(_tenefix[tenefixDir]);
        tmp6.setPosition(j * _size, i * _size);
        _window.draw(tmp6);
      }
      if (_mapP[i][j] == '9') {
        sf::Sprite tmp7;
        tmp7.setTexture(_herbizarre[herbizarreDir]);
        tmp7.setPosition(j * _size, i * _size);
        _window.draw(tmp7);
      }
    }
  }
}

void Client::clean_map(int x, int y, char c) {
  for (int i = 0; i < _y; i++)
    for (int j = 0; j < _x; j++) {
      if ((i != y || j != x) && _mapP[i][j] == c)
        _mapP[i][j] = 'x';
    }
}

void Client::updatePokemons(const std::vector<std::string> &datas) {
  std::string stack;
  std::string tmp;

  if (datas[0] == "pgt") {
    std::cout << "->      " << datas[0] << std::endl;
    std::vector<std::string> inventory;
    std::vector<std::string> map;
    usleep(10000);
    map = sendToServerMultiple("mct\n");
    for (const auto &e : map) {
      if (e.find("bct") == std::string::npos) {
        return;
      }
    }
    updateMap(map);
    for (int i = 0; i < _y; i++) {
      for (int j = 0; j < _x; j++)
        if (_mapP[i][j] == datas[1][1]) {
          _mapR[i][j] = 'x';
        }
    }
  } else if (datas[0] == "ppo" && datas[1][1] == '1') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '1';
    if (datas[4][3] == '1') {
      pikachuDir = 1;
    } else if (datas[4][3] == '5') {
      pikachuDir = 0;
    } else if (datas[4][3] == '7') {
      pikachuDir = 2;
    } else if (datas[4][3] == '3') {
      pikachuDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '1');
  } else if (datas[0] == "ppo" && datas[1][1] == '2') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '2';
    if (datas[4][3] == '1') {
      luguiaDir = 1;
    } else if (datas[4][3] == '5') {
      luguiaDir = 0;
    } else if (datas[4][3] == '7') {
      luguiaDir = 2;
    } else if (datas[4][3] == '3') {
      luguiaDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '2');
  } else if (datas[0] == "ppo" && datas[1][1] == '3') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '3';
    if (datas[4][3] == '1') {
      mewtowDir = 1;
    } else if (datas[4][3] == '5') {
      mewtowDir = 0;
    } else if (datas[4][3] == '7') {
      mewtowDir = 2;
    } else if (datas[4][3] == '3') {
      mewtowDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '3');
  } else if (datas[0] == "ppo" && datas[1][1] == '4') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '4';
    if (datas[4][3] == '1') {
      dracaufeuDir = 1;
    } else if (datas[4][3] == '5') {
      dracaufeuDir = 0;
    } else if (datas[4][3] == '7') {
      dracaufeuDir = 2;
    } else if (datas[4][3] == '3') {
      dracaufeuDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '4');
  } else if (datas[0] == "ppo" && datas[1][1] == '5') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '5';
    if (datas[4][3] == '1') {
      raichuDir = 1;
    } else if (datas[4][3] == '5') {
      raichuDir = 0;
    } else if (datas[4][3] == '7') {
      raichuDir = 2;
    } else if (datas[4][3] == '3') {
      raichuDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '5');
  } else if (datas[0] == "ppo" && datas[1][1] == '6') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '6';
    if (datas[4][3] == '1') {
      pyroliDir = 1;
    } else if (datas[4][3] == '5') {
      pyroliDir = 0;
    } else if (datas[4][3] == '7') {
      pyroliDir = 2;
    } else if (datas[4][3] == '3') {
      pyroliDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '6');
  } else if (datas[0] == "ppo" && datas[1][1] == '7') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '7';
    if (datas[4][3] == '1') {
      mentalyDir = 1;
    } else if (datas[4][3] == '5') {
      mentalyDir = 0;
    } else if (datas[4][3] == '7') {
      mentalyDir = 2;
    } else if (datas[4][3] == '3') {
      mentalyDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '7');
  } else if (datas[0] == "ppo" && datas[1][1] == '8') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '8';
    if (datas[4][3] == '1') {
      tenefixDir = 1;
    } else if (datas[4][3] == '5') {
      tenefixDir = 0;
    } else if (datas[4][3] == '7') {
      tenefixDir = 2;
    } else if (datas[4][3] == '3') {
      tenefixDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '8');
  } else if (datas[0] == "ppo" && datas[1][1] == '9') {
    _mapP[std::stoi(datas[3])][std::stoi(datas[2])] = '9';
    if (datas[4][3] == '1') {
      herbizarreDir = 1;
    } else if (datas[4][3] == '5') {
      herbizarreDir = 0;
    } else if (datas[4][3] == '7') {
      herbizarreDir = 2;
    } else if (datas[4][3] == '3') {
      herbizarreDir = 3;
    }
    clean_map(std::stoi(datas[2]), std::stoi(datas[3]), '9');
  }
}

void Client::updateMap(const std::vector<std::string> &datas) {
  std::vector<std::string> tmp;
  std::string line;
  for (auto e : datas) {
    std::istringstream f(e);
    while (std::getline(f, line, ' ')) {
      tmp.push_back(line);
    }
    size_t index = 3;
    while (index <= 9) {
      if (std::stoi(tmp[index]) == 1 && index == 3)
        _mapR[std::stoi(tmp[2])][std::stoi(tmp[1])] = 'F';
      else if (std::stoi(tmp[index]) == 1 && index == 4)
        _mapR[std::stoi(tmp[2])][std::stoi(tmp[1])] = 'L';
      else if (std::stoi(tmp[index]) == 1 && index == 5)
        _mapR[std::stoi(tmp[2])][std::stoi(tmp[1])] = 'D';
      else if (std::stoi(tmp[index]) == 1 && index == 6)
        _mapR[std::stoi(tmp[2])][std::stoi(tmp[1])] = 'S';
      else if (std::stoi(tmp[index]) == 1 && index == 7)
        _mapR[std::stoi(tmp[2])][std::stoi(tmp[1])] = 'M';
      else if (std::stoi(tmp[index]) == 1 && index == 8)
        _mapR[std::stoi(tmp[2])][std::stoi(tmp[1])] = 'P';
      else if (std::stoi(tmp[index]) == 1 && index == 9)
        _mapR[std::stoi(tmp[2])][std::stoi(tmp[1])] = 'T';
      index++;
    }
    tmp.clear();
  }
}

void Client::coutNbOfElems() {
  nbOfpokValue = 0;
  nbOfRessourcesValue = 0;
  for (int i = 0; i < _y; i++) {
    for (int j = 0; j < _x; j++) {
      if (_mapP[i][j] >= '0' && _mapP[i][j] <= '9')
        nbOfpokValue += 1;
    }
  }
  for (int i = 0; i < _y; i++) {
    for (int j = 0; j < _x; j++) {
      if (_mapR[i][j] == 'L' || _mapR[i][j] == 'D' || _mapR[i][j] == 'F' ||
          _mapR[i][j] == 'S' || _mapR[i][j] == 'M' || _mapR[i][j] == 'P' ||
          _mapR[i][j] == 'T')
        nbOfRessourcesValue += 1;
    }
  }
}

void Client::getLvl() {
  std::vector<std::string> pokemon;
  std::vector<std::string> init;
  int i = 1;
  for (auto i = 0; i <= 9; i++) {
    init.push_back("0");
  }
  _pikachuInventory.setString(init[1]);
  _luguiaInventory.setString(init[2]);
  _mewtwoInventory.setString(init[3]);
  _dracaufeuInventory.setString(init[4]);
  _RaichuInventory.setString(init[5]);
  _pyroliInventory.setString(init[6]);
  _mentalyInventory.setString(init[7]);
  _TenefixInventory.setString(init[8]);
  _herbizarreInventory.setString(init[9]);
  while (i <= 9) {
    std::string str;
    str = "plv #";
    str += std::to_string(i);
    str += "\n";
    pokemon = sendToServerOne(str);
    for (const auto &e : pokemon) {
      std::cout << e << std::endl;
    }
    if (pokemon[0] == "plv") {
      if (pokemon[1][1] == '1') {
        _pikachuInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '2') {
        _luguiaInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '3') {
        _mewtwoInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '4') {
        _luguiaInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '5') {
        _dracaufeuInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '6') {
        _RaichuInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '7') {
        _pyroliInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '8') {
        _mentalyInventory.setString(pokemon[2]);
      } else if (pokemon[1][1] == '9') {
        _herbizarreInventory.setString(pokemon[2]);
      }
    }
    i++;
  }
}

void Client::getInventory() {
  int i = 1;
  std::vector<std::string> inventory;
  std::string stack;
  std::string str;
  std::vector<std::string> init;
  for (auto i = 0; i <= 9; i++) {
    init.push_back("0 0 0 0 0 0 0");
  }
  _pikachuInventory.setString(init[1]);
  _luguiaInventory.setString(init[2]);
  _mewtwoInventory.setString(init[3]);
  _dracaufeuInventory.setString(init[4]);
  _RaichuInventory.setString(init[5]);
  _pyroliInventory.setString(init[6]);
  _mentalyInventory.setString(init[7]);
  _TenefixInventory.setString(init[8]);
  _herbizarreInventory.setString(init[9]);
  while (i <= 9) {
    str = "pin #";
    str += std::to_string(i);
    str += "\n";
    inventory = sendToServerOne(str);
    for (const auto &e : inventory) {
      std::cout << e << std::endl;
    }
    for (auto &e : inventory) {
      stack += e;
    }
    if (inventory[0] == "pin") {
      if (inventory[1][1] == '1') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _pikachuInventory.setString(tmp);
      } else if (inventory[1][1] == '2') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _luguiaInventory.setString(tmp);
      } else if (inventory[1][1] == '3') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _mewtwoInventory.setString(tmp);
      } else if (inventory[1][1] == '4') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _dracaufeuInventory.setString(tmp);
      } else if (inventory[1][1] == '5') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _RaichuInventory.setString(tmp);
      } else if (inventory[1][1] == '6') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _pyroliInventory.setString(tmp);
      } else if (inventory[1][1] == '7') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _mentalyInventory.setString(tmp);
      } else if (inventory[1][1] == '8') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _TenefixInventory.setString(tmp);
      } else if (inventory[1][1] == '9') {
        std::string tmp;
        size_t i = 7;
        while (i < 14) {
          tmp += stack[i];
          tmp += ' ';
          i++;
        }
        _herbizarreInventory.setString(tmp);
      }
    }
    i++;
  }
}

void Client::mainloop() {
  int view = 1;
  std::vector<std::string> msz;
  std::vector<std::string> map;
  std::vector<std::string> pokemon;
  std::vector<std::string> inventory;

  msz = sendToServerOne("msz\n");
  initWindow(msz);
  display();
  map = sendToServerMultiple("mct\n");
  updateMap(map);
  while (_window.isOpen()) {
    int i = 1;
    while (i <= 9) {
      std::string str;
      str = "ppo #";
      str += std::to_string(i);
      str += "\n";
      pokemon = sendToServerOne(str);
      updatePokemons(pokemon);
      display();
      i++;
    }
    sf::Event event;
    display();
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        _window.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        view = 1;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        view = 2;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        view = 3;
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        view = 4;
      }
    }
    switch (view) {
    case 1:
      getInventory();
      _window.draw(_spriteInventory);
      _window.draw(_pikachuInventory);
      _window.draw(_luguiaInventory);
      _window.draw(_mewtwoInventory);
      _window.draw(_dracaufeuInventory);
      _window.draw(_RaichuInventory);
      _window.draw(_pyroliInventory);
      _window.draw(_mentalyInventory);
      _window.draw(_TenefixInventory);
      _window.draw(_herbizarreInventory);
      break;
    case 2:
      getLvl();
      _window.draw(_spriteInventory);
      _window.draw(_pikachuInventory);
      _window.draw(_luguiaInventory);
      _window.draw(_mewtwoInventory);
      _window.draw(_dracaufeuInventory);
      _window.draw(_RaichuInventory);
      _window.draw(_pyroliInventory);
      _window.draw(_mentalyInventory);
      _window.draw(_TenefixInventory);
      _window.draw(_herbizarreInventory);
      break;
    case 3:
      _window.draw(_spriteRessources);
      break;
    case 4:
      coutNbOfElems();
      _nbOfRessources.setString(std::to_string(nbOfRessourcesValue));
      _nbOfPokText.setString(std::to_string(nbOfpokValue));
      _window.draw(_spriteNbOfPok);
      _window.draw(_nbOfRessources);
      _window.draw(_nbOfPokText);
      break;
    }
    _window.display();
  }
}

Client::~Client() {}

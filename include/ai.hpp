/*
** defines.h for dsq in /home/galpin_a/PSU_2016_zappy/include
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Fri Jun  9 00:51:02 2017 Antoine Galpin
** Last update Thu Jun 22 17:14:27 2017 Daniel Dessaux
*/

#ifndef __AI_H__
#define __AI_H__

#include "Map.hpp"
#include "Socket.hpp"
#include "my_getline.h"
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

typedef struct		s_food
{
  int			food;
  int			linemate;
  int			derau;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			    t_food;

typedef struct		s_player
{
    unsigned int	x;
    unsigned int	y;
    std::vector<std::string>   orientation;
    unsigned int	id;
    unsigned int	level;
    std::string   teamName;
    t_food		    invent;
}			            t_player;

class AI {
public:
  AI(int fd);
  ~AI();
  int getFd() const;
  const std::vector<std::string> sendToServer(const std::string &message);
  void mainloop();
  const std::vector<std::string> getMap() const;
  void setMap(const std::vector<std::string> &map);
  std::string getInfos() const;
  void setInfos(std::string str);
  void initWindow(char *infos);
  const std::vector<std::string> getParse(char *buff) const;
  //EVENTS
  void connection();
  void move();
  char checkelem(std::string);

  //protocole
  const std::vector<std::string> sendTna(const std::string&,
    std::vector<std::string>);
  void mct(std::vector<std::string>);
  void receivePnw(const std::vector<std::string>);

private:
  std::vector<std::string> _map;
  int                      timeT;
  std::vector<std::string> Team;
  std::string              _recv;
  int                      _fd;
  t_player                 _player;
  int                      _team;
};

#endif /* !__AI_H__ */

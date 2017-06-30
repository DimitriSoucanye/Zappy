#ifndef __NEWAI_H__
# define __NEWAI_H__

#include "Map.hpp"
#include "Socket.hpp"
#include "my_getline.h"
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>
#include <map>
#include <functional>
#include <unistd.h>

enum s_case
{
  EMPTY,
  FOOD,
  LINEMATE,
  DERAU,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THISTAME,
};

typedef struct		s_food
{
  int			food;
  int			linemate;
  int			derau;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			            t_food;

typedef struct    s_incantation
{
  int     nb_player;
  int			linemate;
  int			derau;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}                 t_incantation;

typedef struct    s_arg
{
  int             port;
  char            *name;
  char            *host;
}                 t_arg;

// Messages envoyés au serveur
# define FORWARD        "Forward\n"
# define RIGHT          "Right\n"
# define LEFT           "Left\n"
# define LOOK           "Look\n"
# define INVENTORY      "Inventory\n"
# define BROADCAST      "Broadcast text\n"
# define CONNECT        "Connect_nbr\n"
# define FORK           "Fork\n"
# define EJECT          "Eject\n"
# define TAKE           "Take %s\n"
# define SET            "Set %s\n"
# define INCANTATION    "Incantation\n"

// Reponse du serveur
# define KO              "ko\n"
# define OK              "ok\n"
# define DEAD            "dead\n"

class NewAI
{
public:
  NewAI(int);
  ~NewAI();

  void mainloop();

  //command
  std::vector<std::string> forward();
  std::vector<std::string> right();
  std::vector<std::string> left();
  std::vector<std::string> look();
  void inventory();
  std::vector<std::string> broadcast(std::vector<std::string> datas);
  std::vector<std::string> connect(std::vector<std::string> datas);
  std::vector<std::string> fork(std::vector<std::string> datas);
  std::vector<std::string> eject(std::vector<std::string> datas);
  std::vector<std::string> take(int i);
  std::vector<std::string> set(std::vector<std::string> datas);
  void incantation();

  //Map Initialization
  void                     initMap();


  void                     goAhead();

  int                      checkFood();
  int                      checkItem();

  void                     lookParser(std::vector<std::string>);

  const std::vector<std::string> getParse(char *) const;
  const std::vector<std::string> sendToServer(const std::string &);
private:

  //Move FUnction
  void                     case0(int);
  void                     case1(int);
  void                     case2(int);
  void                     case3(int);
  void                     case4(int);
  void                     case5(int);
  void                     case6(int);
  void                     case7(int);
  void                     case8(int);
  void                     case9(int);
  void                     case10(int);
  void                     case11(int);
  void                     case12(int);
  void                     case13(int);
  void                     case14(int);
  void                     case15(int);

  //incantation pour lvl up
  void                     check_lvlup();
  t_incantation            lvlUp_Tab[7];

  //parser
  void                     parseLook();

  //variable
  std::map<int, std::function<void(int)>> mapMove;
  int                 _fd;
  std::vector<std::string> _parseStr;
  std::string         _team;
  t_food              _food;
  unsigned int        _lvl;
};

#endif

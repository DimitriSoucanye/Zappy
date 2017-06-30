#include "../../include/NewAI.hpp"

void        NewAI::check_lvlup()
{
    std::vector<std::string> datas;

    std::cout << "Est ce que je peux lvl up ? " << _food.linemate << std::endl;
    if (lvlUp_Tab[_lvl - 1].linemate <= _food.linemate &&
        lvlUp_Tab[_lvl - 1].derau <= _food.derau       &&
        lvlUp_Tab[_lvl - 1].sibur <= _food.sibur       &&
        lvlUp_Tab[_lvl - 1].mendiane <= _food.mendiane &&
        lvlUp_Tab[_lvl - 1].phiras <= _food.phiras     &&
        lvlUp_Tab[_lvl - 1].thystame <= _food.thystame)
      {
        std::cout << "Tu peux lvl up frr" << std::endl;
        dprintf(_fd, SET, "linemate");
        datas = sendToServer(INCANTATION);
        if (datas[0].compare("ko\n") == 0)
          return;
        else
          _lvl = std::stoi(datas[0]);
      }
}

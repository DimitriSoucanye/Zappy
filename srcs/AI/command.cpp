#include "../../include/NewAI.hpp"

std::vector<std::string> NewAI::forward()
{
  std::vector<std::string> datas;

  datas = sendToServer(FORWARD);
  return (datas);
}

std::vector<std::string> NewAI::right()
{
  std::vector<std::string> datas;

  datas = sendToServer(RIGHT);
  return (datas);
}

std::vector<std::string> NewAI::left()
{
  std::vector<std::string> datas;

  datas = sendToServer(LEFT);
  return (datas);
}

std::vector<std::string> NewAI::look()
{
  std::vector<std::string> datas;

  datas = sendToServer(LOOK);
  if (datas[0].compare("[") == 0)
    exit(0);
  lookParser(datas);
  parseLook();
  return (datas);
}

void NewAI::inventory()
{
  std::vector<std::string> datas;

  datas = sendToServer(INVENTORY);
  sleep(1);
  std::cout << datas[0] << std::endl;
  if (datas.size() == 1)
    return ;
  /*_food.food = (datas[0][1] - 48);
  _food.linemate = (datas[1][0] - 48);
  _food.derau = (datas[2][0] - 48);
  _food.sibur = (datas[3][0] - 48);
  _food.mendiane = (datas[4][0] - 48);
  _food.phiras = (datas[5][0] - 48);
  _food.thystame = (datas[6][0] - 48);
  _food.food = (datas[7][0] - 48);*/
  datas.clear();
}

std::vector<std::string> NewAI::broadcast(std::vector<std::string> datas)
{
    return (datas);
}

std::vector<std::string> NewAI::connect(std::vector<std::string> datas)
{
  return (datas);
}

std::vector<std::string> NewAI::fork(std::vector<std::string> datas)
{
  return (datas);
}

std::vector<std::string> NewAI::eject(std::vector<std::string> datas)
{
  return (datas);
}

std::vector<std::string> NewAI::take(int i)
{
  char *buff;
  std::vector<std::string> datas;

  std::cout << "I TAKE " << _parseStr[i].c_str() << std::endl;
  dprintf(_fd, TAKE, _parseStr[i].c_str());
  if ((buff = my_getline(_fd)) == NULL)
    exit(84);
  datas = getParse(buff);
  free(buff);
  return (datas);
}

std::vector<std::string> NewAI::set(std::vector<std::string> datas)
{
  return (datas);
}

void NewAI::incantation()
{
  std::vector<std::string> datas;

  datas = sendToServer(INCANTATION);
  if ((datas[0].compare("ko\n")) == 0)
    return ;
  else
    _lvl = std::stoi(datas[0]);
  datas.clear();
}

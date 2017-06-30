#include "../../include/NewAI.hpp"

#include <string.h>
#include <stdlib.h>

NewAI::NewAI(int fd): _fd(fd)
{

}

NewAI::~NewAI()
{

}

const std::vector<std::string> NewAI::getParse(char *buff) const {
  std::istringstream f(buff);
  std::vector<std::string> elems;
  std::string tmp;
  while (std::getline(f, tmp, ' ')) {
    elems.push_back(tmp);
  }
  return elems;
}

const std::vector<std::string> NewAI::sendToServer(const std::string &message)
{
  char *buff;
  std::vector<std::string> datas;

  write(_fd, message.c_str(), message.size());
  buff = my_getline(_fd);
  datas = getParse(buff);
  return datas;
}

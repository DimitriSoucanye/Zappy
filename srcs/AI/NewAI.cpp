#include "../../include/NewAI.hpp"

#include <stdlib.h>
#include <string.h>

NewAI::NewAI(int fd) : _fd(fd) {
  mapMove[0] = [&] (int i) {return NewAI::case0(i);};
  mapMove[1] = [&] (int i) {return NewAI::case1(i);};
  mapMove[2] = [&] (int i) {return NewAI::case2(i);};
  mapMove[3] = [&] (int i) {return NewAI::case3(i);};
  mapMove[4] = [&] (int i) {return NewAI::case4(i);};
  mapMove[5] = [&] (int i) {return NewAI::case5(i);};
  mapMove[6] = [&] (int i) {return NewAI::case6(i);};
  mapMove[7] = [&] (int i) {return NewAI::case7(i);};
  mapMove[8] = [&] (int i) {return NewAI::case8(i);};
  mapMove[9] = [&] (int i) {return NewAI::case9(i);};
  mapMove[10] = [&] (int i) {return NewAI::case10(i);};
  mapMove[11] = [&] (int i) {return NewAI::case11(i);};
  mapMove[12] = [&] (int i) {return NewAI::case12(i);};
  mapMove[13] = [&] (int i) {return NewAI::case13(i);};
  mapMove[14] = [&] (int i) {return NewAI::case14(i);};
  mapMove[15] = [&] (int i) {return NewAI::case15(i);};

  lvlUp_Tab[0] = {1, 1, 0, 0, 0, 0, 0};
  lvlUp_Tab[1] = {2, 1, 1, 1, 0, 0, 0};
  lvlUp_Tab[2] = {2, 2, 0, 1, 0, 2, 0};
  lvlUp_Tab[3] = {4, 1, 1, 2, 0, 1, 0};
  lvlUp_Tab[4] = {4, 1, 2, 1, 3, 0, 0};
  lvlUp_Tab[5] = {6, 1, 2, 3, 0, 1, 0};
  lvlUp_Tab[6] = {6, 2, 2, 2, 2, 2, 1};

  _lvl = 1;
}

NewAI::~NewAI() {}

const std::vector<std::string> NewAI::getParse(char *buff) const {
  std::vector<std::string> elems;
  std::string tmp;
  auto i = 0;
  while (buff[i] != 0) {
    while (buff[i] != ' ' && buff[i] != 0) {
      tmp += buff[i];
      i += 1;
    }
    i += 1;
    elems.push_back(tmp);
    tmp = "";
  }
  return elems;
}

const std::vector<std::string> NewAI::sendToServer(const std::string &message) {
  char *buff;
  std::vector<std::string> datas;

  std::cout << message << std::endl;
  write(_fd, message.c_str(), message.size());
  sleep(1);
  if ((buff = my_getline(_fd)) == NULL)
    exit(0);
  datas = getParse(buff);
  std::cout << buff << std::endl;
  free(buff);
  return datas;
}

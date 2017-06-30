#include "../../include/NewAI.hpp"

void			NewAI::lookParser(std::vector<std::string> datas)
{
  auto			i = 1;
  std::string		tmp;

  while (datas[0][i] != 0)
  {
    while (datas[0][i] != ',' && datas[0][i] != ']' && datas[0][i] != '\0')
    {
      tmp += datas[0][i];
      i++;
    }
    if (tmp == "")
      tmp = "0";
    if (tmp.compare("player") != 0)
      _parseStr.push_back(tmp);
    tmp.clear();
    i++;
  }
}

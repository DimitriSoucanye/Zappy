#include "../../include/NewAI.hpp"

void  NewAI::mainloop()
{
  int                      val = 0;
  int                      stockValue = 0;

  look();
  while (1)
  {
    val = checkFood();
    if (val != -1)
       mapMove[val] (val);
    else if ((stockValue = checkItem()) != -1)
    {
      mapMove[stockValue] (stockValue);
      inventory();
      check_lvlup();
    }
    else
      goAhead();
    std::cout << "Je suis niveau " << _lvl << " mon negro" << std::endl;
    _parseStr.clear();
    look();
  }
}

void  NewAI::goAhead()
{
    static int          tmp = 0;
    unsigned int        tmp2 = 0;

    if (tmp >= 3)
      {
        right();
        tmp = 0;
      }
    while (tmp2 < _lvl)
    {
      forward();
      tmp2 += 1;
    }
    tmp += 1;
}

int NewAI::checkFood()
{
  unsigned int idx = 0;

    while (idx < _parseStr.size())
    {
      if (_parseStr[idx].compare("food") == 0)
        return (idx);
      idx += 1;
    }
  return (-1);
}

int NewAI::checkItem()
{
  unsigned int idx = 0;

  while (idx < _parseStr.size())
  {
    std::cout << _parseStr[idx] << std::endl;
    if (_parseStr[idx].compare("0") != 0)
      return (idx);
    idx += 1;
  }
  return (-1);
}

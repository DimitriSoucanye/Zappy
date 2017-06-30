#include "../../include/NewAI.hpp"

void      NewAI::parseLook()
{
  unsigned int idx = 0;

  while (_parseStr[idx].size() > idx)
  {
    if (_parseStr[idx].compare("food")      != 0 &&
        _parseStr[idx].compare("linemate")  != 0 &&
        _parseStr[idx].compare("deraumere") != 0 &&
        _parseStr[idx].compare("sibur")     != 0 &&
        _parseStr[idx].compare("mendiane")  != 0 &&
        _parseStr[idx].compare("phiras")    != 0 &&
        _parseStr[idx].compare("thystame")  != 0)
        {
          _parseStr[idx] = "0";
        }
    idx += 1;
  }
}

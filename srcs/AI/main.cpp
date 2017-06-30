#include "../../include/NewAI.hpp"
#include "../../include/my_getline.h"
#include <string.h>

bool isNum(char *str) {
  int idx = 0;

  while (str[idx]) {
    if (str[idx] >= '0' && str[idx] <= '9')
      idx += 1;
    else
      return (false);
  }
  return (true);
}

t_arg *initArg() {
  t_arg *arg;

  if ((arg = (t_arg *)malloc(sizeof(t_arg))) == NULL)
    return (NULL);
  arg->name = NULL;
  arg->port = -1;
  arg->host = strdup("localhost");
  return (arg);
}

int main(int ac, char **av) {
  char *buff;

  int idx = 1;
  t_arg *arg;

  if (ac == 1) {
    std::cerr << "USAGE: ./zappy_ai -p [port] -n [team] -h [machine]" << std::endl;
    return (-1);
  }
  if ((arg = initArg()) == NULL)
    return (-1);
  while (av[idx] != NULL) {
    if ((strcmp(av[idx], "-p") == 0) && (av[idx + 1] != NULL)) {
      if (isNum(av[idx + 1]) == false)
        return (-1);
      arg->port = atoi(av[idx + 1]);
    } else if ((strcmp(av[idx], "-n") == 0) && (av[idx + 1] != NULL))
      arg->name = strdup(av[idx + 1]);
    else if ((strcmp(av[idx], "-h") == 0) && (av[idx + 1] != NULL)) {
      free(arg->host);
      arg->host = strdup(av[idx + 1]);
    }
    idx += 1;
  }

  if (arg->port == -1 || arg->name == NULL) {
    std::cerr << "USAGE: ./zappy_ai -p [port] -n [team] -h [machine]" << std::endl;
    return (-1);
  }
  Socket sock(arg->port);
  std::string nameTmp(arg->name);
  nameTmp += '\n';

  if ((buff = my_getline(sock.getFd())) == NULL)
    exit(0);
  std::cout << buff << std::endl;
  write(sock.getFd(), nameTmp.c_str(), nameTmp.size());
  if ((buff = my_getline(sock.getFd())) == NULL)
    exit(0);
  std::cout << buff << std::endl;
  if (!strcmp(buff, "ko")) {
    std::cerr << "Invalid team name" << std::endl;
    return (-1);
  }
  if ((buff = my_getline(sock.getFd())) == NULL)
    exit(0);
  NewAI client(sock.getFd());
  client.mainloop();
  return (0);
}

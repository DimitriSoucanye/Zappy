//
// client.cpp for dqs in /home/galpin_a/PSU_2016_zappy/srcs/client
//
// Made by Antoine Galpin
// Login   <galpin_a@epitech.net>
//
// Started on  Tue Jun 13 21:53:24 2017 Antoine Galpin
// Last update Thu Jun 29 17:19:28 2017 Antoine Galpin
//

#include "../../include/client.hpp"

int main(int ac, char **av) {
  char *buff;

  if (ac < 2) {
    std::cerr << "USAGE: ./client port" << std::endl;
    return (-1);
  }
  Socket sock(atoi(av[1]));
  Client client(sock.getFd());
  if ((buff = my_getline(sock.getFd())) == NULL)
    return (-1);
  client.mainloop();
  sock.closeSocket();
  return (0);
}

//
// Socket.cpp for  in /Users/antoinegalpin/PSU_2016_zappy/srcs/client/
//
// Made by Antoine Galpin
// Login   <antoine.galpin@epitech.eu>
//
// Started on  Tue Jun 13 22:12:51 2017 Antoine Galpin
// Last update Sat Jun 24 18:59:58 2017 Antoine Galpin
//

#include "../../include/Socket.hpp"
#include <sys/fcntl.h>

Socket::Socket(int port) {
  if ((_pe = getprotobyname("TCP")) == NULL)
    return;
  if ((_fd = socket(AF_INET, SOCK_STREAM, _pe->p_proto)) == -1)
    return;
  _sin.sin_family = AF_INET;
  _sin.sin_port = htons(port);
  _sin.sin_addr.s_addr = INADDR_ANY;
  if ((connect(_fd, (struct sockaddr *)&_sin, sizeof(_sin))) < 0)
    return;
}

Socket::Socket(int port, const std::string &type) {
  if ((_pe = getprotobyname(type.c_str())) == NULL)
    return;
  if ((_fd = socket(AF_INET, SOCK_STREAM, _pe->p_proto)) == -1)
    return;
  _sin.sin_family = AF_INET;
  _sin.sin_port = htons(port);
  _sin.sin_addr.s_addr = INADDR_ANY;
  if ((connect(_fd, (struct sockaddr *)&_sin, sizeof(_sin))) < 0)
    return;
}

void Socket::closeSocket() const {
  if (close(_fd) == -1)
    return;
}

int Socket::getFd() const { return _fd; }

Socket::~Socket() {}

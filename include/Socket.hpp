//
// Socket.hpp for  in /Users/antoinegalpin/PSU_2016_zappy/include/
//
// Made by Antoine Galpin
// Login   <antoine.galpin@epitech.eu>
//
// Started on  Tue Jun 13 22:18:50 2017 Antoine Galpin
// Last update Tue Jun 13 22:35:12 2017 Antoine Galpin
//

#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

#include "ISocket.hpp"

class Socket {
public:
  Socket(int port);
  ~Socket();
  Socket(int port, const std::string &type);
  virtual void closeSocket() const;
  virtual int getFd() const;

private:
  int _fd;
  struct sockaddr_in _sin;
  struct protoent *_pe;
};

#endif

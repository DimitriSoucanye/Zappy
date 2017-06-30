//
// ISocket.hpp for  in /Users/antoinegalpin/PSU_2016_zappy/include/
//
// Made by Antoine Galpin
// Login   <antoine.galpin@epitech.eu>
//
// Started on  Tue Jun 13 22:13:03 2017 Antoine Galpin
// Last update Tue Jun 13 22:31:32 2017 Antoine Galpin
//

#ifndef __ISOCKET_HPP__
#define __ISOCKET_HPP__

#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

class ISocket {
public:
  virtual void closeSocket() const = 0;
  virtual int getFd() const = 0;
};

#endif

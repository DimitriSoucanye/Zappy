/*
** xfunctions.c for dsq in /home/galpin_a/PSU_2016_myirc/srcs
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue May 23 12:17:41 2017 Antoine Galpin
** Last update Mon May 29 01:29:25 2017 Antoine Galpin
*/

#include "server.h"

int                     xclose(int fd)
{
  if (close(fd) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

struct protoent         *xgetprotobyname(char *type)
{
  struct protoent       *pe;

  if ((pe = getprotobyname(type)) == NULL)
    {
      fprintf(stderr, "ERROR: getprotobyname failed\n");
      return (NULL);
    }
  return (pe);
}

int                     xsocket(struct protoent *pe)
{
  int                   fd;

  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      fprintf(stderr, "ERROR: socket failed\n");
      return (ERROR);
    }
  return (fd);
}

int                     xbind(int fd, struct sockaddr_in s_in)
{
  if ((bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in))) == -1)
    {
      fprintf(stderr, "ERROR: bind failed\n");
      xclose(fd);
      return (ERROR);
    }
  return (SUCCESS);
}

int                     xlisten(int fd)
{
  if (listen(fd, SOMAXCONN) == ERROR)
    {
      xclose(fd);
      return (ERROR);
    }
  return (SUCCESS);
}

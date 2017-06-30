/*
** direction.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Thu Jun 22 23:30:09 2017 Antoine Galpin
** Last update Thu Jun 22 23:47:43 2017 Antoine Galpin
*/

#include "server.h"

void		forward_dir(t_env *e)
{
  if (e->current->player.dir == 1)
    e->current->player.y -= 1;
  else if (e->current->player.dir == 5)
    e->current->player.y += 1;
  else if (e->current->player.dir == 3)
    e->current->player.x += 1;
  else if (e->current->player.dir == 7)
    e->current->player.x -= 1;
}

int                    dir_left(t_env *e)
{
  int			dir;

  dir = 0;
  if (e->current->player.dir == 1)
    dir = 7;
  else if (e->current->player.dir == 5)
    dir = 3;
  else if (e->current->player.dir == 3)
    dir = 1;
  else if (e->current->player.dir == 7)
    dir = 5;
  return (dir);
}

int                    dir_right(t_env *e)
{
  int			dir;

  dir = 0;
  if (e->current->player.dir == 1)
    dir = 3;
  else if (e->current->player.dir == 5)
    dir = 7;
  else if (e->current->player.dir == 3)
    dir = 5;
  else if (e->current->player.dir == 7)
    dir = 1;
  return (dir);
}

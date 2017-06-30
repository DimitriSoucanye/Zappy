/*
** player.c for dsq in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:26:21 2017 Antoine Galpin
** Last update Wed Jun 28 15:15:34 2017 Antoine Galpin
*/

#include "server.h"

static int curr_team = 0;

t_player		init_player(t_infos *infos, int id, int fd)
{
  t_player	player;
  t_team	*tmp;
  int		idx;

  tmp = infos->teams;
  idx = 0;
  player.x = rand() % (infos->width - 1);
  player.y = rand() % (infos->height - 1);
  player.dir = 1;
  player.level = 1;
  player.id = id;
  player.invent = init_food();
  player.fd = fd;
  while (idx < curr_team)
    {
      if (tmp)
	tmp = tmp->next;
      idx++;
    }
  if (tmp == NULL)
    {
      fprintf(stderr, "ERROR: Too much players for number of team.\n");
      exit(-1);
    }
  player.team = strdup(tmp->name);
  curr_team++;
  return (player);
}

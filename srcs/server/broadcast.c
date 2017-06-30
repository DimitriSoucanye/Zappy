/*
** broadcast.c for dsq in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:23:07 2017 Antoine Galpin
** Last update Tue Jun 27 20:23:14 2017 Antoine Galpin
*/

#include "server.h"

int		broad_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_player_list	*tmp;

  (void)infos;
  tmp = e->head;
  while (tmp)
    {
      if (tmp->player.fd == fd)
	dprintf(fd, "ok\n");
      else
	dprintf(tmp->player.fd, "message K, %s\n", cmds[1]);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

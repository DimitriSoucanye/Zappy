/*
** choose_cmds3.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Thu Jun 22 15:51:30 2017 Antoine Galpin
** Last update Fri Jun 23 11:14:34 2017 Antoine Galpin
*/

#include "server.h"

int             forward_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  (void)cmds;
  (void)infos;
  (void)e;
  update_forward(e, fd);
  dprintf(fd, "ok\n");
  return (SUCCESS);
}

int             left_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  (void)infos;
  (void)e;
  (void)cmds;
  update_dir(e, fd, 1);
  dprintf(fd, "ok\n");
  return (SUCCESS);
}

int             right_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  (void)infos;
  (void)e;
  (void)cmds;
  update_dir(e, fd, 0);
  dprintf(fd, "ok\n");
  return (SUCCESS);
}

int             inventory_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_player_list	*tmp;

  (void)infos;
  (void)e;
  (void)cmds;
  tmp = e->head;
  while (tmp != NULL)
    {
      if (tmp->player.fd == fd)
	dprintf(fd, REQUEST_INVENTORY, tmp->player.invent.food,
		tmp->player.invent.linemate,
		tmp->player.invent.derau, tmp->player.invent.sibur,
		tmp->player.invent.mendiane,
		tmp->player.invent.phiras, tmp->player.invent.thystame);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

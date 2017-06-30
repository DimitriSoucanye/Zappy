/*
** take_obj_cmd.c for dsq in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:25:45 2017 Antoine Galpin
** Last update Wed Jun 28 05:22:48 2017 Antoine Galpin
*/

#include "server.h"

char		check_which_ressources(char *cmd, t_player *player)
{
  char		c;

  if (!strcmp(cmd, "linemate"))
    {
      player->invent.linemate += 1;
      c = 'L';
    }
  else if (!strcmp(cmd, "deraumere"))
    {
      player->invent.derau += 1;
      c = 'D';
    }
  else if (!strcmp(cmd, "food"))
    {
      player->invent.food += 1;
      c = 'F';
    }
  else if (!strcmp(cmd, "sibur"))
    {
      player->invent.sibur += 1;
      c = 'S';
    }
  else if (!strcmp(cmd, "mendiane"))
    {
      player->invent.mendiane += 1;
      c = 'M';
    }
  else if (!strcmp(cmd, "phiras"))
    {
      player->invent.phiras += 1;
      c = 'P';
    }
  else if (!strcmp(cmd, "thystame"))
    {
      player->invent.thystame += 1;
      c = 'T';
    }
  else
    c = 'Z';
  return (c);
}

int		check_map_and_ressources(t_env *e, char *cmd,
					 t_infos *infos)
{
  int		i;
  int		j;
  char		c;

  if ((c = check_which_ressources(cmd, &e->current->player)) == 'Z')
    return (ERROR);
  i = 0;
  while (i < infos->height)
    {
      j = 0;
      while (j < infos->width)
	{
	  if (e->current->player.y == i && e->current->player.x == j &&
	      e->map_r[i][j] == c)
	    {
	      e->map_r[i][j] = 'x';
	      return (SUCCESS);
	    }
	  j++;
	}
      i++;
    }
  return (ERROR);
}

int             take_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  if (strlen_cmds(cmds) < 2)
    return (wrong_cmd(fd));
  if (e->head == NULL)
    return (ERROR);
  e->current = e->head;
  while (e->current != NULL)
    {
      if (e->current->player.fd == fd)
	{
	  if (check_map_and_ressources(e, cmds[1], infos) == SUCCESS)
	    {
	      dprintf(e->fd_graphic, "pgt #%d\n", e->current->player.id);
	      dprintf(fd, "ok\n");
	      generate_nb(1, infos, e, "FL");
        generate_nb(1, infos, e, "LDSMPT");
	    }
	  else
	    dprintf(fd, "ko\n");
	}
      e->current = e->current->next;
    }
  return (SUCCESS);
}

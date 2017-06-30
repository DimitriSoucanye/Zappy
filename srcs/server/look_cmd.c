/*
** look_cmd.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Fri Jun 23 11:14:46 2017 Antoine Galpin
** Last update Thu Jun 29 14:43:35 2017 Daniel Dessaux
*/

#include "server.h"

char		*check_elems(char c)
{
  if (c >= '0' && c <= '9')
    return ("player");
  else if (c == 'F')
    return ("food");
  else if (c == 'L')
    return ("linemate");
  else if (c == 'D')
    return ("deraumere");
  else if (c == 'S')
    return ("sibur");
  else if (c == 'M')
    return ("mendiane");
  else if (c == 'P')
    return ("phiras");
  else if (c == 'T')
    return ("thystame");
  return ("");
}

char		**init_view()
{
  char		**tmp;
  int		i;

  i = 0;
  if ((tmp = malloc(sizeof(char *) * 16)) == NULL)
    return (NULL);
  while (i <= 15)
    {
      if ((tmp[i] = malloc(sizeof(char) * 20)) == NULL)
	return (NULL);
      i++;
    }
  return (tmp);
}

int             look_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_player_list	*tmp;

  (void)infos;
  (void)cmds;
  (void)fd;
  tmp = e->head;
  while (tmp != NULL)
    {
      if (tmp->player.fd == fd)
        set_view(e, tmp);
      tmp = tmp->next;
    }
  dprintf(fd, REQUEST_LOOK, e->view[0], e->view[1], e->view[2],
	  e->view[3], e->view[4], e->view[5], e->view[6], e->view[7],
	  e->view[8], e->view[9], e->view[10], e->view[11], e->view[12], e->view[13],
	  e->view[14], e->view[15]);
  return (SUCCESS);
}

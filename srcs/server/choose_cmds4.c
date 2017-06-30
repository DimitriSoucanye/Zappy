/*
** choose_cmds4.c for dsq in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:23:34 2017 Antoine Galpin
** Last update Tue Jun 27 20:23:35 2017 Antoine Galpin
*/

#include "server.h"

int			strlen_cmds(char **cmds)
{
  int           i;

  i = 0;
  while (cmds[i] != NULL)
    i++;
  return (i);
}

char			*check_dir(int dir)
{
  char			*tmp;

  if ((tmp = malloc(sizeof(char) * 50)) == NULL)
    return (NULL);
  if (dir == 1)
    tmp = "(N:1, E:7, S:5, O:3)";
  else if (dir == 5)
    tmp = "(N:5, E:3, S:1, O:7)";
  else if (dir == 7)
    tmp = "(N:7, E:5, S:3, O:1)";
  else if (dir == 3)
    tmp = "(N:3, E:1, S:7, O:5)";
  return (tmp);
}

int			wrong_cmd(int fd)
{
    dprintf(fd, REQUEST_SBP);
    return (ERROR);
}

int                     ppo_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_player_list		*tmp;
  char			*dir;

  if (strlen_cmds(cmds) < 2)
    return (wrong_cmd(fd));
  (void)infos;
  if (cmds[1][0] == '#')
    memmove(cmds[1], cmds[1] + 1, strlen(cmds[1] + 1) + 1);
  tmp = e->head;
  while (tmp != NULL)
    {
      if ((int)tmp->player.id == atoi(cmds[1]))
	{
	  dir = check_dir(tmp->player.dir);
	  dprintf(fd, REQUEST_PPO, tmp->player.id ,tmp->player.x,
		  tmp->player.y, dir);
	}
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int			plv_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_player_list		*tmp;

  if (strlen_cmds(cmds) < 2)
    return (wrong_cmd(fd));
  (void)infos;
  if (cmds[1][0] == '#')
    memmove(cmds[1], cmds[1] + 1, strlen(cmds[1] + 1) + 1);
  tmp = e->head;
  while (tmp != NULL)
    {
      if ((int)tmp->player.id == atoi(cmds[1]))
	dprintf(fd, REQUEST_PLV, tmp->player.id, tmp->player.level);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int			pin_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_player_list		*tmp;

  if (strlen_cmds(cmds) < 2)
    return (wrong_cmd(fd));
  (void)infos;
  if (cmds[1][0] == '#')
    memmove(cmds[1], cmds[1] + 1, strlen(cmds[1] + 1) + 1);
  tmp = e->head;
  while (tmp != NULL)
    {
      if ((int)tmp->player.id == atoi(cmds[1]))
	dprintf(fd, REQUEST_PIN, tmp->player.id, tmp->player.x,
		tmp->player.y, tmp->player.invent.food,
		tmp->player.invent.linemate, tmp->player.invent.derau,
		tmp->player.invent.sibur, tmp->player.invent.mendiane,
		tmp->player.invent.phiras, tmp->player.invent.thystame);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

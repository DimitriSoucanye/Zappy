/*
** choose_cmds2.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Thu Jun 22 15:50:32 2017 Antoine Galpin
** Last update Tue Jun 27 12:26:39 2017 Antoine Galpin
*/

#include "server.h"

t_food		init_food()
{
  t_food	tmp;

  tmp.food = 0;
  tmp.linemate = 0;
  tmp.derau = 0;
  tmp.sibur = 0;
  tmp.mendiane = 0;
  tmp.phiras = 0;
  tmp.thystame = 0;
  return (tmp);
}

t_food		check_ressources(char c)
{
  t_food	tmp;

  tmp = init_food();
  if (c == 'F')
    tmp.food += 1;
  else if (c == 'L')
    tmp.linemate += 1;
  else if (c == 'D')
    tmp.derau += 1;
  else if (c == 'S')
    tmp.sibur += 1;
  else if (c == 'M')
    tmp.mendiane += 1;
  else if (c == 'P')
    tmp.phiras += 1;
  else if (c == 'T')
    tmp.thystame += 1;
  return (tmp);
}

int             bct_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_food	food;

  (void)infos;
  if (!is_number(cmds[1]) || !is_number(cmds[1]))
    {
      dprintf(fd, REQUEST_SBP);
      return (ERROR);
    }
  if (strlen_cmds(cmds) < 3 || atoi(cmds[1]) >= infos->width ||
      atoi(cmds[1]) < 0 || atoi(cmds[2]) >= infos->height ||
      atoi(cmds[2]) < 0)
    {
      dprintf(fd, REQUEST_SBP);
      return (ERROR);
    }
  food = check_ressources(e->map_r[atoi(cmds[2])][atoi(cmds[1])]);
  dprintf(fd, REQUEST_BCT, atoi(cmds[1]),
	  atoi(cmds[2]), food.food, food.linemate, food.derau,
	  food.sibur, food.mendiane,
	  food.phiras, food.thystame);
  return (SUCCESS);
}

int		mct_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  int		i;
  int		j;
  t_food	food;

  i = 0;
  (void)cmds;
  while (i < infos->height)
    {
      j = 0;
      while (j < infos->width)
        {
	  food = check_ressources(e->map_r[i][j]);
	  dprintf(fd, REQUEST_BCT, (int)j, (int)i,
		  food.food, food.linemate, food.derau,
		  food.sibur, food.mendiane, food.phiras, food.thystame);
	  j++;
        }
      i += 1;
    }
  return (SUCCESS);
}

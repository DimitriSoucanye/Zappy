/*
** args_others.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sun Jun 11 16:15:24 2017 Antoine Galpin
** Last update Tue Jun 27 12:13:39 2017 Antoine Galpin
*/

#include "server.h"
#include "defines.h"

int             client_args(t_infos *infos, int i, char **av)
{
  if (av[i + 1] == NULL)
    return (help_print());
  if (!is_number(av[i + 1]))
    {
      fprintf(stderr, ERROR_CLIENT);
      return (help_print());
    }
  if (atoi(av[i + 1]) < 1 || atoi(av[i + 1]) > 9)
    {
      fprintf(stderr, ERROR_CLIENT_SIZE);
      return (help_print());
    }
  infos->clients = atoi(av[i + 1]);
  infos->arg_access[0] = true;
  return (SUCCESS);
}

bool		check_is_team(char *av)
{
  int		i;

  i = 0;
  while (av[i] != '\0')
    {
      if (av[i] == '-')
	return (false);
      i++;
    }
  return (true);
}

int             names_args(t_infos *infos, int i, char **av)
{
  int		j;
  int		id;

  j = i + 1;
  if (av[i + 1] == NULL)
    return (help_print());
  id = 1;
  while (av[j] != NULL)
    {
      if (!check_is_team(av[j]))
	break;
      if (id > 9)
	{
	  fprintf(stderr, ERROR_TEAM_SIZE);
	  return (help_print());
	}
      infos->teams = add_team(infos->teams, av[j], id);
      id++;
      j++;
      i++;
    }
  if (infos->teams == NULL)
    return (help_print());
  infos->arg_access[3] = true;
  return (SUCCESS);
}

int             time_args(t_infos *infos, int i, char **av)
{
  if (av[i + 1] == NULL)
    return (help_print());
  if (!is_number(av[i + 1]))
    {
      fprintf(stderr, ERROR_TIME);
      return (help_print());
    }
  if (atoi(av[i + 1]) < 1 || atoi(av[i + 1]) > 10000)
    {
      fprintf(stderr, ERROR_TIME_SIZE);
      return (help_print());
    }
    infos->time = atoi(av[i + 1]);
  infos->arg_access[4] = true;
  return (SUCCESS);
}

int             port_args(t_infos *infos, int i, char **av)
{
  if (av[i + 1] == NULL)
    return (help_print());
  if (!is_number(av[i + 1]))
  {
    fprintf(stderr, ERROR_PORT);
    return (help_print());
  }
  infos->port = atoi(av[i + 1]);
  infos->arg_access[5] = true;
  return (SUCCESS);
}

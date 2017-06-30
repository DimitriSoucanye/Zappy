/*
** args_map.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sun Jun 11 16:16:36 2017 Antoine Galpin
** Last update Wed Jun 28 19:58:37 2017 Antoine Galpin
*/

#include "server.h"
#include "defines.h"

int             width_args(t_infos *infos, int i, char **av)
{
  if (av[i + 1] == NULL)
    return (help_print());
  if (!is_number(av[i + 1]))
    {
      fprintf(stderr, ERROR_WIDTH);
      return (help_print());
    }
  if (atoi(av[i + 1]) < 10 || atoi(av[i + 1]) > 30)
    {
      fprintf(stderr, ERROR_WIDTH_SIZE);
      return (help_print());
    }
  infos->width = atoi(av[i + 1]);
  infos->arg_access[1] = true;
  return (SUCCESS);
}

int             height_args(t_infos *infos, int i, char **av)
{
  if (av[i + 1] == NULL)
    return (help_print());
  if (!is_number(av[i + 1]))
    {
      fprintf(stderr, ERROR_HEIGHT);
      return (ERROR);
    }
  if (atoi(av[i + 1]) < 10 || atoi(av[i + 1]) > 30)
    {
      fprintf(stderr, ERROR_HEIGHT_SIZE);
      return (help_print());
    }
  infos->height = atoi(av[i + 1]);
  infos->arg_access[2] = true;
  return (SUCCESS);
}

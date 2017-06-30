/*
** check_and_free.c for dqs in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sun Jun 11 16:13:19 2017 Antoine Galpin
** Last update Thu Jun 22 15:24:58 2017 Antoine Galpin
*/

#include "server.h"
#include "defines.h"

bool            is_number(char *str)
{
  int           i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!isdigit(str[i]))
	return (false);
      i++;
    }
  return (true);
}

bool		has_space(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	return (true);
      i++;
    }
  return (false);
}

bool            check_infos(t_infos *infos)
{
  int           i;

  i = 0;
  while (i < 5)
    {
      if (infos->arg_access[i] == false)
	return (false);
      i++;
    }
  return (true);
}

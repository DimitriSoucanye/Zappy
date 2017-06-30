/*
** init.c for dqs in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:22:51 2017 Antoine Galpin
** Last update Tue Jun 27 20:22:52 2017 Antoine Galpin
*/

#include "server.h"

char		**init_map(t_infos *infos)
{
  char		**tmp;
  int		i;
  int		j;

  if ((tmp = malloc(sizeof(char *) * infos->height)) == NULL)
    return (NULL);
  i = 0;
  while (i < infos->height)
    {
      j = 0;
      if ((tmp[i] = malloc(sizeof(char) * infos->width)) == NULL)
	return (NULL);
      while (j < infos->width)
	{
	  tmp[i][j] = 'x';
	  j++;
	}
      i++;
    }
  return (tmp);
}

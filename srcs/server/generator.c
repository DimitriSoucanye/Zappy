/*
** generator.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 13:25:17 2017 Antoine Galpin
** Last update Tue Jun 27 16:02:07 2017 Antoine Galpin
*/

#include "server.h"

void		generator_r(t_infos *infos, t_env *e, char *str)
{
  char		*ressources;
  int		x;
  int		y;
  int		nb;

  if ((ressources = malloc(sizeof(char) * strlen(str) + 1)) == NULL)
    return ;
  ressources = str;
  x = rand() % (infos->width - 1);
  y = rand() % (infos->height - 1);
  nb = rand() % strlen(str);
  e->map_r[y][x] = ressources[nb];
}

void		generate_nb(int nb, t_infos *infos, t_env *e, char *str)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      generator_r(infos, e, str);
      i++;
    }
}

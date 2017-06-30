/*
** dump_infos.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sun Jun 11 16:14:27 2017 Antoine Galpin
** Last update Sun Jun 25 00:10:32 2017 Antoine Galpin
*/

#include "server.h"
#include "defines.h"

int             help_print()
{
  printf("%s%s", FIRST_LINE_ONE, FIRST_LINE_TWO);
  printf("%s%s", SPACE_START, SECOND_LINE);
  printf("%s%s", SPACE_START, THIRD_LINE);
  printf("%s%s", SPACE_START, FOUR_LINE);
  printf("%s%s", SPACE_START, FIVE_LINE);
  printf("%s%s", SPACE_START, SIX_LINE);
  printf("%s%s", SPACE_START, SEV_LINE);
  printf("%s%s", SPACE_START, EIGHT_LINE);
  return (ERROR);
}

void            dump_datas(t_infos *infos)
{
  t_team	*tmp;

  tmp = infos->teams;
  printf("------- DEBUG -------\n");
  printf("PORT -> %d\n", infos->port);
  printf("WIDTH -> %d\n", infos->width);
  printf("HEIGHT -> %d\n", infos->height);
  while (tmp != NULL)
    {
      printf("TEAMS -> %s : %d\n", tmp->name, tmp->id);
      tmp = tmp->next;
    }
  printf("CLIENTS -> %d\n", infos->clients);
  printf("TIME -> %d\n", infos->time);
}

void		dump_map_r(t_infos *infos, t_env *e)
{
  int		i;
  int		j;

  i = 0;
  printf("------- DEBUG -------\n");
  while (i < infos->height)
    {
      j = 0;
      while (j < infos->width)
	{
	  printf("%c", e->map_r[i][j]);
	  j++;
	}
      printf("\n");
      i++;
    }
}

void		dump_map_p(t_infos *infos, t_env *e)
{
  int		i;
  int		j;

  i = 0;
  printf("------- DEBUG -------\n");
  while (i < infos->height)
    {
      j = 0;
      while (j < infos->width)
	{
	  printf("%c", e->map_p[i][j]);
	  j++;
	}
      printf("\n");
      i++;
    }
}

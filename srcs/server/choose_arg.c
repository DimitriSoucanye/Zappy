/*
** choose_arg.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sun Jun 11 16:17:41 2017 Antoine Galpin
** Last update Tue Jun 27 12:10:18 2017 Antoine Galpin
*/

#include "server.h"
#include "defines.h"

static  t_args  g_tab[] =
  {
    {&client_args, "-c"},
    {&height_args, "-y"},
    {&width_args, "-x"},
    {&names_args, "-n"},
    {&port_args, "-p"},
    {&time_args, "-f"},
    {NULL, NULL},
  };

int             get_args(t_infos *infos, char **av)
{
  int           i;
  int           j;

  if (!strcmp("--help", av[1]))
    return (help_print());
  i = 0;
  while (av[i] != '\0')
    {
      j = 0;
      while (g_tab[j].key != '\0')
	{
	  if (!strcmp(g_tab[j].key, av[i]))
	    {
	      if (g_tab[j].ptrfunc(infos, i, av) == ERROR)
		return (ERROR);
	    }
	  j++;
	}
      i++;
    }
  return (SUCCESS);
}

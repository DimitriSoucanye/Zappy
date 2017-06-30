/*
** server.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Fri Jun  9 00:46:49 2017 Antoine Galpin
** Last update Tue Jun 27 13:43:03 2017 Antoine Galpin
*/

#include "defines.h"
#include "server.h"

static void	init_infos(t_infos *infos)
{
  int		i;

  i = 0;
  while (i < 5)
    {
      infos->arg_access[i] = false;
      i++;
    }
  infos->teams = NULL;
}

static t_norme init_normes()
{
  t_norme n;

  n.fd_max =  0;
  n.i = 0;
  n.error = 0;
  return (n);
}

int		main(int ac, char **av)
{
  t_infos	infos;
  t_env		e;
  t_norme	n;

  (void)ac;
  srand(time(NULL));
  init_infos(&infos);
  memset(e.fd_type, FD_FREE, MAX_FD);
  if (get_args(&infos, av) == ERROR)
    return (ERROR);
  if (check_infos(&infos) == false)
    {
      fprintf(stderr, ERROR_NB_INFOS);
      return (ERROR);
    }
  if (DEBUG_MODE == 1)
    dump_datas(&infos);
  if (add_server(&infos, &e) == ERROR)
    return (ERROR);
  n = init_normes();
  mainloop(&infos, e, n);
  return (0);
}

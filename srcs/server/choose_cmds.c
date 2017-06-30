/*
** choose_cmds.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 13 01:06:17 2017 Antoine Galpin
** Last update	Thu Jun 29 19:34:04 2017 Full Name
*/

#include "server.h"

int             msz_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  (void)e;
  (void)cmds;
  dprintf(fd, REQUEST_MSZ, infos->width, infos->height);
  return (SUCCESS);
}

int		sgt_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  (void)e;
  (void)cmds;
  dprintf(fd, REQUEST_SGT, infos->time);
  return (SUCCESS);
}

int		sst_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  (void)e;
  if (strlen_cmds(cmds) < 2)
    {
      dprintf(fd, REQUEST_SBP);
      return (ERROR);
    }

  infos->time = atoi(cmds[1]);
  dprintf(fd, REQUEST_SGT, infos->time);
  return (SUCCESS);
}

int		tna_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_team	*tmp;

  tmp = infos->teams;
  (void)e;
  (void)cmds;
  while (tmp != NULL)
    {
      dprintf(fd, REQUEST_TNA, tmp->name);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static t_cmds	g_tab[] =
{
  {&incantation, "Incantation"},
  {&inventory_cmd, "Inventory"},
  {&forward_cmd, "Forward"},
  {&broad_cmd, "Broadcast"},
  {&right_cmd, "Right"},
  {&left_cmd, "Left"},
  {&look_cmd, "Look"},
  {&take_cmd, "Take"},
  {&set_cmd, "Set"},
  {&pin_cmd, "pin"},
  {&plv_cmd, "plv"},
  {&ppo_cmd, "ppo"},
  {&tna_cmd, "tna"},
  {&sst_cmd, "sst"},
  {&sgt_cmd, "sgt"},
  {&mct_cmd, "mct"},
  {&bct_cmd, "bct"},
  {&msz_cmd, "msz"},
  {NULL, NULL},
};

int             get_cmds(t_infos *infos, t_env *e, char **cmds, int fd)
{
  int           j;

  j = 0;
  while (g_tab[j].key != '\0')
    {
      if (!strcmp(g_tab[j].key, cmds[0]))
	{
	  if (g_tab[j].ptrfunc(infos, e, cmds, fd) == ERROR)
	    return (ERROR);
	}
      j++;
    }
  return (SUCCESS);
}

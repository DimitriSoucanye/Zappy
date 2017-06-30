/*
** add_list.c for dsq in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:21:40 2017 Antoine Galpin
** Last update Wed Jun 28 05:22:31 2017 Antoine Galpin
*/

#include "../../include/server.h"

t_team		*add_team(t_team *teams, char *team_name, int id)
{
  t_team	*tmp;

  if ((tmp = malloc(sizeof(t_team))) == NULL)
    return (NULL);
  if ((tmp->name = malloc(sizeof(char) * strlen(team_name) + 1)) == NULL)
    return (NULL);
  strcpy(tmp->name, team_name);
  tmp->id = id;
  tmp->next = teams;
  return (tmp);
}

void            insert(t_env *e, int id, t_infos *infos, int fd)
{
  t_player_list *link;

  if ((link = malloc(sizeof(t_player_list))) == NULL)
    return ;
  link->player = init_player(infos, id, fd);
  dprintf(e->fd_graphic, REQUEST_PNW,
	  link->player.id, link->player.x, link->player.y,
          link->player.dir, link->player.level, link->player.team);
  link->next = NULL;
  if (e->head == NULL)
    {
      e->head = link;
      return;
    }
  e->current = e->head;
  while (e->current->next != NULL)
    e->current = e->current->next;
  e->current->next = link;
}

void            update_forward(t_env *e, int fd)
{
  if (e->head == NULL)
    return;
  e->current = e->head;
  while (e->current != NULL)
    {
      if (e->current->player.fd == fd)
	{
	  e->map_p[e->current->player.y][e->current->player.x] = 'x';
	  forward_dir(e);
	  return;
	}
      e->current = e->current->next;
    }
}

void            update_dir(t_env *e, int fd, int task)
{
  if (e->head == NULL)
    return;
  e->current = e->head;
  while (e->current != NULL)
    {
      if (e->current->player.fd == fd)
	{
	  if (task == 1)
	    e->current->player.dir = dir_left(e);
	  else
	    e->current->player.dir = dir_right(e);
	  return;
	}
      e->current = e->current->next;
    }
}

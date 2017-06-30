#include "server.h"

void				level_up(t_env *e, t_player_list *list)
{
  t_player_list		*tmp;

  tmp = list;
  if (e->head == NULL)
    return ;
  e->current = e->head;
  while (tmp)
    {
      while (e->current && e->current->player.id != tmp->player.id)
	e->current = e->current->next;
      if (e->current == NULL)
	return ;
      e->current->player.level += 1;
      tmp = tmp->next;
      e->current = e->head;
    }
}

int				incantation_2(t_player_list *player_list,
					      t_env *e,
					      t_player_list *tmp,
					      int nb_player_required)
{
    int			idx;

    idx = 0;
  if (count_nb_elem(player_list) >= nb_player_required)
    {
      dprintf(e->fd_graphic, "pic %d %d %d", tmp->player.y, tmp->player.x,
	      tmp->player.level);
      level_up(e, player_list);
      while (idx++ < nb_player_required)
        {
	  dprintf(e->fd_graphic, " %d", player_list->player.id);
	  dprintf(e->current->player.fd, "%d\n", e->current->player.level);
	  player_list = player_list->next;
        }
      dprintf(e->fd_graphic, "\n");
      return (SUCCESS);
    }
  dprintf(player_list->player.fd, "ko\n");
  return (ERROR);
}

t_player_list			*incantation_3(t_player_list *tmp2,
					      t_player_list *tmp,
					      t_player_list *player_list,
					      t_env *e)
{
  if (tmp2->player.x == tmp->player.x && tmp2->player.y == tmp->player.y
      && tmp->player.level == tmp2->player.level)
    {
      player_list = push_elem(player_list, &tmp2->player);
      if (player_list->player.id == tmp->player.id)
	{
	  if (comp_main_ressources(&player_list->player, e) == ERROR)
	    player_list = pop_elem(player_list, &player_list->player);
	}
      else if (comp_ressources(&player_list->player, e) == ERROR)
	player_list = pop_elem(player_list, &player_list->player);
    }
  return (player_list);
}

int				incantation(t_infos *infos, t_env *e, char **cmds, int fd)
{
  t_player_list			*tmp;
  t_player_list			*tmp2;
  t_player_list			*player_list;
  int				nb_player_required;

  (void)infos;
  (void)cmds;
  tmp = e->head;
  tmp2 = e->head;
  if ((player_list = malloc(sizeof(t_player_list))) == NULL)
    return (ERROR);
  player_list = NULL;
  while (tmp && tmp->player.fd != fd)
    tmp = tmp->next;
  tmp->player.level % 2 == 0 ? (nb_player_required = tmp->player.level)
    : (nb_player_required = tmp->player.level - 1);
  if (nb_player_required == 0)
    nb_player_required += 1;
  while (tmp2)
    {
      player_list = incantation_3(tmp2, tmp, player_list, e);
      tmp2 = tmp2->next;
    }
  return (incantation_2(player_list, e, tmp, nb_player_required));
}

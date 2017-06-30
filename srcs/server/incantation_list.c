#include "server.h"

int			count_nb_elem(t_player_list *list)
{
  t_player_list		*tmp;
  int			nb_players;

  tmp = list;
  nb_players = 0;
  while (tmp)
    {
      nb_players++;
      tmp = tmp->next;
    }
  free(tmp);
  return (nb_players);
}

t_player_list			*pop_elem(t_player_list *list, t_player *player)
{
  int				idx;
  int				idx2;
  t_player_list			*tmp;
  t_player_list			*tmp2;

  tmp = list;
  tmp2 = list;
  idx = 0;
  while (tmp && tmp->player.id != player->id)
    {
      tmp = tmp->next;
      idx++;
    }
  if (idx == count_nb_elem(list))
    tmp = NULL;
  else if (idx == 0)
    return (tmp->next);
  else
    {
      idx2 = 1;
      while (idx2++ != idx)
        tmp2 = tmp2->next;
      tmp2->next = tmp->next;
    }
  return (list);
}

t_player_list			*push_elem(t_player_list *list, t_player *elem)
{
  t_player_list			*new;

  if ((new = malloc(sizeof(t_player_list))) == NULL)
    return (NULL);
  new->player = *elem;
  new->next = list;
  return (new);
}

#include "server.h"

void				remove_ressources_2(t_env *e, t_player *player, int tab[7][6])
{
  if (e->current->player.invent.mendiane >= tab[player->level - 1][3]
      && tab[player->level - 1][3] > 0)
    e->current->player.invent.mendiane -= 1;
  if (e->current->player.invent.phiras >= tab[player->level - 1][4]
      && tab[player->level - 1][4] > 0)
    e->current->player.invent.phiras -= 1;
  if (e->current->player.invent.thystame >= tab[player->level - 1][5]
      && tab[player->level - 1][5] > 0)
    e->current->player.invent.thystame -= 1;
}

void				remove_ressources(t_env *e, t_player *player, int tab[7][6])
{
  if (e->head == NULL)
    return ;
  e->current = e->head;
  while (e->current != NULL)
    {
      if (e->current->player.fd == player->fd)
        {
          if (e->current->player.invent.linemate >= tab[player->level - 1][0]
              && tab[player->level - 1][0] > 0)
            e->current->player.invent.linemate -= 1;
          if (e->current->player.invent.derau >= tab[player->level - 1][1]
              && tab[player->level - 1][1] > 0)
            e->current->player.invent.derau -= 1;
          if (e->current->player.invent.sibur >= tab[player->level - 1][2]
              && tab[player->level - 1][2] > 0)
            e->current->player.invent.sibur -= 1;
          remove_ressources_2(e, player, tab);
       }
      e->current = e->current->next;
    }
}

int				comp_ressources(t_player *player, t_env *e)
{
  int				tab[7][6] = {{1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0},
                                             {2, 0, 1, 0, 2, 0}, {1, 1, 2, 0, 1, 0},
                                             {1, 2, 1, 3, 0, 0}, {1, 2, 3, 0, 1, 0},
                                             {2, 2, 2, 2, 2, 1}};

  if (tab[(player->level) - 1][0] <= player->invent.linemate &&
      tab[(player->level) - 1][1] <= player->invent.derau &&
      tab[(player->level) - 1][2] <= player->invent.sibur &&
      tab[(player->level) - 1][3] <= player->invent.mendiane &&
      tab[(player->level) - 1][4] <= player->invent.phiras &&
      tab[(player->level) - 1][5] <= player->invent.thystame)
    {
      remove_ressources(e, player, tab);
      return (SUCCESS);
    }
  return (ERROR);
}

int				comp_main_ressources(t_player *player, t_env *e)
{
  int				tab[7][6] = {{0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0},
					     {1, 0, 1, 0, 2, 0}, {0, 1, 2, 0, 1, 0},
					     {0, 2, 1, 3, 0, 0}, {0, 2, 3, 0, 1, 0},
					     {1, 2, 2, 2, 2, 1}};

  if (tab[(player->level) - 1][0] <= player->invent.linemate &&
      tab[(player->level) - 1][1] <= player->invent.derau &&
      tab[(player->level) - 1][2] <= player->invent.sibur &&
      tab[(player->level) - 1][3] <= player->invent.mendiane &&
      tab[(player->level) - 1][4] <= player->invent.phiras &&
      tab[(player->level) - 1][5] <= player->invent.thystame &&
      e->map_r[player->y][player->x] == 'L')
    {
      remove_ressources(e, player, tab);
      e->map_r[player->y][player->x] = 'x';
      return (SUCCESS);
    }
  return (ERROR);
}

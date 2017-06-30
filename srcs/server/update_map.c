/*
** update_map.c for dqs in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Thu Jun 22 22:42:58 2017 Antoine Galpin
** Last update Sun Jun 25 00:07:09 2017 Antoine Galpin
*/

#include "server.h"

void		update_map(t_infos *infos, t_env *e)
{
  t_player_list         *head;

  (void)infos;
  head = e->head;
  while (head != NULL)
    {
      if (head->player.y < 0)
	head->player.y = infos->height - 1;
      else if (head->player.y > infos->height - 1)
	head->player.y = 0;
      else if (head->player.x < 0)
	head->player.x = infos->width - 1;
      else if (head->player.x > infos->width - 1)
	head->player.x = 0;
      e->map_p[head->player.y][head->player.x] = head->player.id + '0';
      head = head->next;
    }
}

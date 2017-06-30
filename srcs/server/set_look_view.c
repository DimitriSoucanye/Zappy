/*
** set_look_view.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Fri Jun 23 12:11:11 2017 Antoine Galpin
** Last update Wed Jun 28 06:11:11 2017 Antoine Galpin
*/

#include "server.h"

static void	set_top_view(t_env *e, t_player_list *tmp)
{
  if (tmp->player.y  >= 10 || tmp->player.y  <= 0 ||
      tmp->player.x  <= 0 || tmp->player.x >= 10)
    e->view[0] = "";
  else
    e->view[0] = check_elems(e->map_r[tmp->player.y][tmp->player.x]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[1] = "";
  else
    e->view[1] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x - 1]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x <= 0 || tmp->player.x >= 10)
    e->view[2] = "";
  else
    e->view[2] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[3] = "";
  else
    e->view[3] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x + 1]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[4] = "";
  else
    e->view[4] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x - 2]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[5] = "";
  else
    e->view[5] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x - 1]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x <= 0 || tmp->player.x >= 10)
    e->view[6] = "";
  else
    e->view[6] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[7] = "";
  else
    e->view[7] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x + 1]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[8] = "";
  else
    e->view[8] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x + 2]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[9] = "";
  else
    e->view[9] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x - 3]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[10] = "";
  else
    e->view[10] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x - 2]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[11] = "";
  else
    e->view[11] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x - 1]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x <= 0 || tmp->player.x >= 10)
    e->view[12] = "";
  else
    e->view[12] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[13] = "";
  else
    e->view[13] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x + 1]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[14] = "";
  else
    e->view[14] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x + 2]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[15] = "";
  else
    e->view[15] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x + 3]);
}

static void	set_bot_view(t_env *e, t_player_list *tmp)
{
  if (tmp->player.y  >= 10 || tmp->player.y  <= 0 ||
      tmp->player.x  <= 0 || tmp->player.x >= 10)
    e->view[0] = "";
  else
    e->view[0] = check_elems(e->map_r[tmp->player.y][tmp->player.x]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[1] = "";
  else
    e->view[1] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x + 1]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x <= 0 || tmp->player.x >= 10)
    e->view[2] = "";
  else
    e->view[2] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[3] = "";
  else
    e->view[3] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x - 1]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[4] = "";
  else
    e->view[4] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x + 2]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[5] = "";
  else
    e->view[5] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x + 1]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x <= 0 || tmp->player.x >= 10)
    e->view[6] = "";
  else
    e->view[6] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[7] = "";
  else
    e->view[7] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x - 1]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[8] = "";
  else
    e->view[8] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x - 2]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[9] = "";
  else
    e->view[9] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x + 3]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[10] = "";
  else
    e->view[10] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x + 2]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[11] = "";
  else
    e->view[11] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x + 1]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x <= 0 || tmp->player.x >= 10)
    e->view[12] = "";
  else
    e->view[12] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[13] = "";
  else
    e->view[13] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x - 1]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[14] = "";
  else
    e->view[14] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x - 2]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[15] = "";
  else
    e->view[15] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x - 3]);
}

static void	set_right_view(t_env *e, t_player_list *tmp)
{
  if (tmp->player.y  >= 10 || tmp->player.y  <= 0 ||
      tmp->player.x  <= 0 || tmp->player.x >= 10)
    e->view[0] = "";
  else
    e->view[0] = check_elems(e->map_r[tmp->player.y][tmp->player.x]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[1] = "";
  else
    e->view[1] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x + 1]);
  if (tmp->player.y >= 10 || tmp->player.y <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[2] = "";
  else
    e->view[2] = check_elems(e->map_r[tmp->player.y][tmp->player.x + 1]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x + 1 <= 0 || tmp->player.x + 1 >= 10)
    e->view[3] = "";
  else
    e->view[3] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x + 1]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[4] = "";
  else
    e->view[4] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x + 2]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[5] = "";
  else
    e->view[5] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x + 2]);
  if (tmp->player.y >= 10 || tmp->player.y <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[6] = "";
  else
    e->view[6] = check_elems(e->map_r[tmp->player.y][tmp->player.x + 2]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[7] = "";
  else
    e->view[7] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x + 2]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x + 2 <= 0 || tmp->player.x + 2 >= 10)
    e->view[8] = "";
  else
    e->view[8] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x + 2]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[9] = "";
  else
    e->view[9] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x + 3]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[10] = "";
  else
    e->view[10] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x + 3]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[11] = "";
  else
    e->view[11] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x + 3]);
  if (tmp->player.y >= 10 || tmp->player.y <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[12] = "";
  else
    e->view[12] = check_elems(e->map_r[tmp->player.y][tmp->player.x + 3]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[13] = "";
  else
    e->view[13] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x + 3]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[14] = "";
  else
    e->view[14] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x + 3]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x + 3 <= 0 || tmp->player.x + 3 >= 10)
    e->view[15] = "";
  else
    e->view[15] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x + 3]);
}

static void	set_left_view(t_env *e, t_player_list *tmp)
{
  if (tmp->player.y  >= 10 || tmp->player.y  <= 0 ||
      tmp->player.x  <= 0 || tmp->player.x >= 10)
    e->view[0] = "";
  else
    e->view[0] = check_elems(e->map_r[tmp->player.y][tmp->player.x]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[1] = "";
  else
    e->view[1] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x - 1]);
  if (tmp->player.y >= 10 || tmp->player.y <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[2] = "";
  else
    e->view[2] = check_elems(e->map_r[tmp->player.y][tmp->player.x - 1]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x - 1 <= 0 || tmp->player.x - 1 >= 10)
    e->view[3] = "";
  else
    e->view[3] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x - 1]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[4] = "";
  else
    e->view[4] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x - 2]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[5] = "";
  else
    e->view[5] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x - 2]);
  if (tmp->player.y >= 10 || tmp->player.y <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[6] = "";
  else
    e->view[6] = check_elems(e->map_r[tmp->player.y][tmp->player.x - 2]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[7] = "";
  else
    e->view[7] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x - 2]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x - 2 <= 0 || tmp->player.x - 2 >= 10)
    e->view[8] = "";
  else
    e->view[8] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x - 2]);
  if (tmp->player.y + 3 >= 10 || tmp->player.y + 3 <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[9] = "";
  else
    e->view[9] = check_elems(e->map_r[tmp->player.y + 3][tmp->player.x - 3]);
  if (tmp->player.y + 2 >= 10 || tmp->player.y + 2 <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[10] = "";
  else
    e->view[10] = check_elems(e->map_r[tmp->player.y + 2][tmp->player.x - 3]);
  if (tmp->player.y + 1 >= 10 || tmp->player.y + 1 <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[11] = "";
  else
    e->view[11] = check_elems(e->map_r[tmp->player.y + 1][tmp->player.x - 3]);
  if (tmp->player.y >= 10 || tmp->player.y <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[12] = "";
  else
    e->view[12] = check_elems(e->map_r[tmp->player.y][tmp->player.x - 3]);
  if (tmp->player.y - 1 >= 10 || tmp->player.y - 1 <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[13] = "";
  else
    e->view[13] = check_elems(e->map_r[tmp->player.y - 1][tmp->player.x - 3]);
  if (tmp->player.y - 2 >= 10 || tmp->player.y - 2 <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[14] = "";
  else
    e->view[14] = check_elems(e->map_r[tmp->player.y - 2][tmp->player.x - 3]);
  if (tmp->player.y - 3 >= 10 || tmp->player.y - 3 <= 0 ||
      tmp->player.x - 3 <= 0 || tmp->player.x - 3 >= 10)
    e->view[15] = "";
  else
    e->view[15] = check_elems(e->map_r[tmp->player.y - 3][tmp->player.x - 3]);
}

void		set_lvl(t_env *e, t_player_list *tmp)
{
  int		i;

  if (tmp->player.level == 1)
    {
      i = 4;
      while (i <= 15)
	{
	  e->view[i] = "";
	  i++;
	}
    }
  else if (tmp->player.level == 2)
    {
      i = 9;
      while (i <= 15)
	{
	  e->view[i] = "";
	  i++;
	}
    }
}

void            set_view(t_env *e, t_player_list *tmp)
{
  e->view = init_view();
  if (tmp->player.dir == 1)
    set_top_view(e, tmp);
  else if (tmp->player.dir == 5)
    set_bot_view(e, tmp);
  else if (tmp->player.dir == 3)
    set_right_view(e, tmp);
  else if (tmp->player.dir == 7)
    set_left_view(e, tmp);
  set_lvl(e, tmp);
}

/*
** server.h for ds in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:20:10 2017 Antoine Galpin
** Last update Wed Jun 28 05:19:49 2017 Antoine Galpin
*/

#ifndef __SERVER_H__
# define __SERVER_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "my_getline.h"
#include "defines.h"

typedef void(*fct)();

typedef struct          s_team
{
  char                  *name;
  unsigned int		id;
  struct s_team         *next;
}                       t_team;

typedef	struct		s_infos
{
  unsigned int		port;
  int			width;
  int			height;
  t_team		*teams;
  unsigned int		clients;
  int			time;
  bool			arg_access[6];
}			t_infos;

typedef struct		s_food
{
  int			food;
  int			linemate;
  int			derau;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_food;

typedef struct		s_player
{
  int			x;
  int			y;
  unsigned int		dir;
  unsigned int		id;
  int			fd;
  unsigned int		level;
  char			*team;
  t_food		invent;
}			t_player;

typedef struct          s_player_list
{
  t_player		player;
  struct s_player_list  *next;
}                       t_player_list;

typedef struct          s_env
{
  char                  fd_type[MAX_FD];
  fct                   fct_read[MAX_FD];
  fct                   fct_write[MAX_FD];
  int                   fd;
  int			fd_graphic;
  char			**map_r;
  char			**map_p;
  t_player_list		*player_list;
  t_player_list		*head;
  t_player_list		*current;
  char			**view;
}                       t_env;

typedef struct          s_norme
{
  int                   fd_max;
  fd_set                fd_read;
  int                   i;
  int                   error;
  struct timeval        tv;
}                       t_norme;

typedef struct          s_args
{
  int (*ptrfunc)(t_infos *info, int index, char **av);
  char                  *key;
}                       t_args;

typedef struct          s_cmds
{
  int (*ptrfunc)(t_infos *info, t_env *e, char **cmds, int fd);
  char                  *key;
}                       t_cmds;

struct protoent         *xgetprotobyname(char *type);
int                     xsocket(struct protoent *pe);
int                     xbind(int fd, struct sockaddr_in s_in);
int                     xlisten(int fd);
int                     xclose(int fd);
int			get_args(t_infos *infos, char **av);
bool			check_infos(t_infos *infos);
void			dump_datas(t_infos *infos);
void			free_datas(t_infos *infos);
bool			is_number(char *str);
int		        width_args(t_infos *infos, int i, char **av);
int			height_args(t_infos *infos, int i, char **av);
int			port_args(t_infos *infos, int i, char **av);
int			client_args(t_infos *infos, int i, char **av);
int			names_args(t_infos *infos, int i, char **av);
int			time_args(t_infos *infos, int i, char **av);
int			help_print();
int			add_server(t_infos *infos, t_env *e);
int			mainloop(t_infos *infos, t_env e, t_norme n);
void			server_read(t_env *e, int fd, t_infos *infos);
char			**init_map(t_infos *infos);
void			dump_map_r(t_infos *infos, t_env *e);
void			dump_map_p(t_infos *infos, t_env *e);
int			get_cmds(t_infos *infos, t_env *e, char **cmds, int fd);
char			**my_str_to_wordtab(char *clean_str);
bool			has_space(char *str);
t_food			init_food();
t_food			check_ressources(char);
int			wrong_cmd(int);
int			bct_cmd(t_infos *, t_env *, char **, int);
int			mct_cmd(t_infos *, t_env *, char **, int);
int			ppo_cmd(t_infos *, t_env *, char **, int);
t_team			*add_team(t_team *teams, char *team_name, int id);
t_player                init_player(t_infos *infos, int id, int fd);
t_player_list		*add_player(t_player_list *list, int id, t_infos *infos,
				    int fd);
int			forward_cmd(t_infos *infos, t_env *e, char **cmds, int fd);
int			left_cmd(t_infos *infos, t_env *e, char **cmds, int fd);
int			inventory_cmd(t_infos *infos, t_env *e, char **cmds, int fd);
int			right_cmd(t_infos *infos, t_env *e, char **cmds, int fd);
void			insert(t_env *e, int id, t_infos *infos, int fd);
void			update_forward(t_env *e, int fd);
void			update_dir(t_env *e, int fd, int task);
void			update_map(t_infos *infos, t_env *e);
void			forward_dir(t_env *e);
int			dir_left(t_env *e);
int			dir_right(t_env *e);
int			look_cmd(t_infos *infos, t_env *e, char **cmds, int fd);
void			set_view(t_env *e, t_player_list *tmp);
char			**init_view();
int			plv_cmd(t_infos *, t_env *, char **, int);
int			pin_cmd(t_infos *, t_env *, char **, int);
int			take_cmd(t_infos *infos, t_env *e, char **cmds, int fd);
int			broad_cmd(t_infos *infos, t_env *e, char **cmds, int fd);
int                     strlen_cmds(char **cmds);
char			*check_elems(char c);
char			*check_lol(char c, int y, int x);
void			generator_r(t_infos *infos, t_env *e, char *str);
void			generate_nb(int nb, t_infos *infos, t_env *e, char *str);
int			incantation(t_infos *, t_env *, char **, int);
int			set_cmd(t_infos *, t_env *, char **, int);
int			count_nb_elem(t_player_list *);
t_player_list		*pop_elem(t_player_list *, t_player *);
t_player_list		*push_elem(t_player_list *, t_player *);
void			remove_ressources(t_env *, t_player *, int tab[7][6]);
void			remove_ressources_2(t_env *, t_player *, int tab[7][6]);
int			comp_ressources(t_player *, t_env *);
int			comp_main_ressources(t_player *, t_env *);

#endif /* !__SERVER_H__ */

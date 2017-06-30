/*
** init.c for dsq in /home/galpin_a/PSU_2016_zappy/srcs/server
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sun Jun 11 16:34:38 2017 Antoine Galpin
** Last update Thu Jun 29 19:26:12 2017 Daniel Dessaux
*/

#include "server.h"
#include "defines.h"

static int id = 1;

void			client_read(t_env *e, int fd, t_infos *infos)
{
  char			*buff;
  char			**cmds;

  CAST_VOID(infos);
  CAST_VOID(e);
  buff = my_getline(fd);
  if (buff != NULL)
    {
      printf("[+] %d: %s\n", fd, buff);
      cmds = my_str_to_wordtab(buff);
      get_cmds(infos, e, cmds, fd);
      update_map(infos, e);
      dump_map_r(infos, e);
      dump_map_p(infos, e);
    }
  else
    {
      printf("[-] %d: Connection closed\n", fd);
      xclose(fd);
      e->fd_type[fd] = FD_FREE;
    }
  free(buff);
}

int                     check_team(t_infos *infos, char *str)
{
  t_team                *tmp;

  tmp = infos->teams;
  while (tmp != NULL)
    {
      if (!strcmp(tmp->name, str))
        return (SUCCESS);
      tmp = tmp->next;
    }
  return (ERROR);
}

void                    add_client(t_env *e, int s, t_infos *infos)
{
  t_player_list		*tmp;
  int                   cs;
  struct sockaddr_in    client_sin;
  socklen_t             client_sin_len;
  char                  *str;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  e->fd = cs;
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = NULL;
  dprintf(cs, "WELCOME\n");
  if ((str = my_getline(cs)) == NULL)
    exit(ERROR);
  //write(cs, "WELCOME\n", 8);
  if (!strcmp(str, "GRAPHIC"))
    e->fd_graphic = cs;
  else
    {
      if (check_team(infos, str) == ERROR)
        write(cs, "ko\n", 3);
      else
        {
          insert(e, id, infos, cs);
          id++;
          dprintf(cs, "%d\n", id);
          dprintf(cs, "%d %d\n", infos->height, infos->width);
        }
    }
  tmp = e->head;
  while (tmp != NULL)
    {
      printf("id: %d ------ fd: %d\n", tmp->player.id, tmp->player.fd);
      tmp = tmp->next;
    }
  printf("[+] New client\n");
}

int                     add_server(t_infos *infos, t_env *e)
{
  int                   s;
  struct sockaddr_in    sin;
  struct protoent       *pe;

  if ((pe = xgetprotobyname("TCP")) == NULL)
    return (ERROR);
  if ((s = xsocket(pe)) == ERROR)
    return (ERROR);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(infos->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (xbind(s, sin) == ERROR)
    return (ERROR);
  if (xlisten(s) == ERROR)
    return (ERROR);
  e->map_r = init_map(infos);
  e->map_p = init_map(infos);
  generate_nb(5, infos, e, "FL");
  generate_nb(5, infos, e, "FLDSMPT");
  dump_map_r(infos, e);
  dump_map_p(infos, e);
  e->head = NULL;
  e->current = NULL;
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = server_read;
  e->fct_write[s] = NULL;
  printf("[+] Server created\n");
  return (SUCCESS);
}

void                    server_read(t_env *e, int fd, t_infos *infos)
{
  add_client(e, fd, infos);
}

int                     mainloop(t_infos *infos, t_env e, t_norme n)
{
  while (1)
    {
      FD_ZERO(&n.fd_read);
      n.i = 0;
      while (n.i < MAX_FD)
	{
	  if (e.fd_type[n.i] != FD_FREE)
	    {
	      FD_SET(n.i, &n.fd_read);
	      n.fd_max = n.i;
	    }
	  n.i++;
	}
      if ((n.error = select(n.fd_max + 1, &n.fd_read, NULL, NULL, NULL)) == -1)
	perror("select");
      n.i = 0;
      while (n.i < MAX_FD)
	{
	  if (FD_ISSET(n.i, &n.fd_read))
	    e.fct_read[n.i](&e, n.i, infos);
	  n.i++;
	}
    }
}

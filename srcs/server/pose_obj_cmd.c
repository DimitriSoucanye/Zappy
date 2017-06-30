/*
** pose_obj_cmd.c for pose in /home/elyes/rendu/Projets/C/Unix/PSU_2016_zappy/srcs/server/
**
** Made by Elyes Ghalaza
** Login   <elyes.ghalaza@epitech.eu>
**
** Started on  Mon Jun 26 17:48:51 2017 Elyes Ghalaza
** Last update	Thu Jun 29 16:16:44 2017 Full Name
*/

#include "server.h"

char	check_enough_ressource(char *cmd, t_player *player)
{
    if (strcmp(cmd, "linemate") == 0 && player->invent.linemate > 0)
    {
        player->invent.linemate -= 1;
        return ('L');
    }
    else if (strcmp(cmd, "deraumere") == 0 && player->invent.derau > 0)
    {
        player->invent.derau -= 1;
        return ('D');
    }
    else if (strcmp(cmd, "food") == 0 && player->invent.food > 0)
    {
        player->invent.food -= 1;
        return ('F');
    }
    else if (strcmp(cmd, "sibur") == 0 && player->invent.sibur > 0)
    {
        player->invent.sibur -= 1;
        return ('S');
    }
    else if (strcmp(cmd, "mendiane") == 0 && player->invent.mendiane > 0)
    {
        player->invent.mendiane -= 1;
        return ('M');
    }
    else if (strcmp(cmd, "phiras") == 0 && player->invent.phiras > 0)
    {
        player->invent.phiras -= 1;
        return ('P');
    }
    else if (strcmp(cmd, "thystame") == 0 && player->invent.thystame > 0)
    {
        player->invent.thystame -= 1;
        return ('T');
    }
    else
        return ('Z');
}

int		check_ressource(t_env *e, char *cmd, t_infos *infos)
{
    int	i;
    int	j;
    int	c;

    if ((c = check_enough_ressource(cmd, &e->current->player)) == 'Z')
        return (ERROR);
    i = 0;
    while (i < infos->height)
    {
        j = 0;
        while (j < infos->width)
        {
            if (e->current->player.y == i && e->current->player.x == j &&
            e->map_r[i][j] != c)
            {
                e->map_r[i][j] = c;
                return (SUCCESS);
            }
            j++;
        }
        i++;
    }
    return (ERROR);
}

int		set_cmd(t_infos *infos, t_env *e, char **cmds, int fd)
{
    (void)infos;
    if (strlen_cmds(cmds) < 2)
      return (wrong_cmd(fd));
    if (e->head == NULL)
      return (ERROR);
    e->current = e->head;
    while (e->current != NULL)
    {
        if (e->current->player.fd == fd)
        {
            if (check_ressource(e, cmds[1], infos) == SUCCESS)
            {
                dprintf(fd, "ok\n");
                dprintf(e->fd_graphic, REQUEST_PDR, e->current->player.id, 1);
            }
            else
                dprintf(fd, "ko\n");
        }
        e->current = e->current->next;
    }
    return (SUCCESS);
}

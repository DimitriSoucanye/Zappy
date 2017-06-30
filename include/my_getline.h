/*
** get_next_line.h for dq in /home/galpin_a/PSU_2016_myftp/srcs
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Thu May 18 21:58:09 2017 Antoine Galpin
** Last update Tue Jun 13 23:18:26 2017 Antoine Galpin
*/

#ifndef		_GET_NEXT_LINE_H_
# define	_GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define	TRUE 1
# define	FALSE 0
# define	READ_SIZE (42)

typedef struct	s_gnl
{
  int		i;
  int		j;
  int		k;
  int		r;
  int		a;
  char		buf[READ_SIZE];
  char		*line;
}		t_gnl;

char		*my_getline(const int fd);

#endif		/* !GET_NEXT_LINE_ */

/*
** get_next_line.c for ds in /home/galpin_a/PSU_2016_myirc/srcs
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Thu Jun  1 11:05:12 2017 Antoine Galpin
** Last update Sun Jun 11 08:30:08 2017 Antoine Galpin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_getline.h"

static char	*duplol(const char *src)
{
  int		xd;
  char		*new_str;

  xd = 0;
  while (src != NULL && src[xd])
    xd += 1;
  if ((new_str = malloc(sizeof(char) * xd + 1)) == NULL)
    return (NULL);
  xd = 0;
  while (src[xd] != '\0')
    {
      new_str[xd] = src[xd];
      xd += 1;
    }
  new_str[xd] = '\0';
  return (new_str);
}

static char	*copy(char *dest,
		      const char *src,
		      unsigned int nbr,
		      int conc)
{
  unsigned int	xd;
  unsigned int	xd_src;

  xd = 0;
  if (conc == TRUE)
    {
      while (dest != NULL && dest[xd])
	xd += 1;
      xd_src = 0;
      while (src[xd_src] && xd_src < nbr)
	{
	  dest[xd] = src[xd_src];
	  xd += 1;
	  xd_src += 1;
	}
      dest[xd] = '\0';
      return (dest);
    }
  while (src[xd] && xd < nbr)
   {
      dest[xd] = src[xd];
      xd += 1;
    }
  dest[xd] = '\0';
  return (dest);
}

static char	*_auto_alloc(char *ptr, size_t mem)
{
  char		*new_ptr;
  int		ptr_len;

  ptr_len = 0;
  while (ptr != NULL && ptr[ptr_len])
    ptr_len += 1;
  if (ptr == NULL)
    {
      if ((new_ptr = malloc(sizeof(char) * mem)) == NULL)
	return (NULL);
      if (mem > 0)
	new_ptr[0] = '\0';
      return (new_ptr);
    }
  if ((new_ptr = malloc(sizeof(char) * (ptr_len + 1 + mem))) == NULL)
    return (NULL);
  new_ptr = copy(new_ptr, ptr, ptr_len, FALSE);
  free(ptr);
  return (new_ptr);
}

static char	*_get_new_buffer(char *buf,
				 char *buf_full,
				 const int fd,
				 int eols)
{
  int		tmp;

  while (TRUE)
    {
      eols = 0;
      tmp = 0;
      while (buf_full != NULL && buf_full[tmp] && (tmp = tmp + 1))
      	{
      	  if (buf_full[tmp - 1] == '\n')
	    eols += 1;
      	}
      if (eols != 0)
	return (buf_full);
      if ((tmp = read(fd, buf, READ_SIZE)) <= 0 || (buf[tmp] = '\0')
	  || (buf_full = _auto_alloc(buf_full, READ_SIZE + 1)) == NULL)
      	{
	  if (buf_full != NULL && buf_full[0] != '\0')
	    return (buf_full);
	  free(buf);
	  free(buf_full);
      	  return (NULL);
      	}
      buf_full = copy(buf_full, buf, READ_SIZE, TRUE);
    }
  return (NULL);
}

char		*my_getline(const int fd)
{
  static char	*buffer;
  char		*buf;
  int		xd_buf;
  int		xd;
  char		*line;

  xd_buf = 0;
  if (READ_SIZE <= 0 || (buf = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL
      || (buffer = _get_new_buffer(buf, buffer, fd, 0)) == NULL)
    return (NULL);
  free(buf);
  xd = 0;
  while (buffer[xd_buf + xd] && buffer[xd_buf + xd] != '\n')
    xd += 1;
  while (buffer[xd_buf + xd] && buffer[xd_buf + xd] != '\n')
    xd += 1;
  buf = buffer;
  if ((line = _auto_alloc((line = NULL), xd + 2)) == NULL ||
      (buffer = buf[xd_buf + xd] == '\0' ? duplol("\0")
       : duplol(buf + xd_buf + xd + 1)) == NULL)
    return (NULL);
  line = copy(line, buf + xd_buf, xd + 1, FALSE);
  line[xd] = '\0';
  free(buf);
  return (line);
}

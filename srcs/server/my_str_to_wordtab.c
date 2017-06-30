/*
** my_str_to_wordtab.c for dsq in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Sun Jun  4 17:55:50 2017 Antoine Galpin
** Last update Sun Jun 11 08:28:19 2017 Antoine Galpin
*/

#include <stdlib.h>
#include "server.h"

static unsigned int	strlen_word(char *str)
{
  unsigned int	index;

  index = 0;
  while (str[index] && str[index] != ' ' && str[index] != '\t')
    index += 1;
  return (index);
}

static unsigned int	nb_of_words(char *str)
{
  unsigned int	idx;
  unsigned int	words;

  words = 0;
  idx = 0;
  while (str[idx])
    {
      if (str[idx] == ' ' || str[idx] == '\t')
	words += 1;
      while (str[idx] == ' ' || str[idx] == '\t')
	idx += 1;
      idx += 1;
    }
  return (words + 1);
}

static char	*fill_in_map(char *clean_str, unsigned int *idx_str)
{
  unsigned int	idx;
  unsigned int	index;
  char		*column;

  index = strlen_word(clean_str + *idx_str);
  if ((column = malloc(sizeof(char) * (index + 1))) == NULL)
    exit(EXIT_FAILURE);
  idx = 0;
  while (idx < index && clean_str[*idx_str])
    {
      column[idx] = clean_str[*idx_str];
      *idx_str += 1;
      idx += 1;
    }
  column[idx] = '\0';
  *idx_str += 1;
  return (column);
}

char		**my_str_to_wordtab(char *clean_str)
{
  unsigned int	idx_line;
  unsigned int	idx_str;
  unsigned int	words;
  char		**tab;

  if (clean_str == NULL)
    return (NULL);
  words = nb_of_words(clean_str);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    exit(EXIT_FAILURE);
  idx_str = 0;
  idx_line = 0;
  while (idx_line < words)
    {
      tab[idx_line] = fill_in_map(clean_str, &idx_str);
      idx_line += 1;
    }
  tab[idx_line] = NULL;
  return (tab);
}

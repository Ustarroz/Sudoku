/*
** init_grid.c for sudoku in /home/voyevoda/rendu/prog_elem/sudoki-bi/src
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Fri Feb 26 21:37:53 2016 Voyevoda
** Last update Sat Feb 27 00:12:42 2016 Voyevoda
*/

#include "././include/sudoki.h"

int	my_check_line(char *str)
{
  int	i;
  int	space_true;

  i = 0;
  space_true = 1;
  if (str[0] != '|' || str[LINE] != '|')
    return (-1);
  while (++i != LINE)
    {
      if (space_true == 1 && str[i] != ' ')
	return (-1);
      else if (space_true == 0 && str[i] <= '0' && str[i] >'9')
	return (-1);
      space_true = 1 - space_true;
      i++;
    }
  return (0);
}

int	*my_get_line(int fd)
{
  char	*s;
  int	i;
  int	*line;

  i = 0;
  if ((s = get_next_line(0)) == NULL)
    {
      fprintf(stderr, READ_ERR_MSG);
      return (NULL);
    }
  if ((line = malloc(sizeof(int *) * (SIZE))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
    if ((my_check_line(s)) == -1)
      return (NULL);
    while (++i < SIZE)
      {
	line[i] == s[i] - 48;
	i++;
      }
    return (0);
}

int	**my_init_grid(char *av)
{
  int	fd;
  int	**tab;
  int	i;

  i = -1;
  fd = open(av, O_RDONLY);
  if ((tab = malloc(sizeof(int *) * (SIZE))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  while (++i < SIZE)
    if ((tab[i] = my_get_line(fd) == NULL))
      return (NULL);
  check_grid(tab);
}

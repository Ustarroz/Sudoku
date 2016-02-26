/*
** init_grid.c for sudoku in /home/voyevoda/rendu/prog_elem/sudoki-bi/src
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Fri Feb 26 21:37:53 2016 Voyevoda
** Last update Sat Feb 27 00:46:16 2016 edouard puillandre
*/

#include "sudoki.h"

int	check_border(int fd)
{
  char	*str;

  if ((str = get_next_line(fd)) == NULL)
    {
      fprintf(stderr, READ_ERR_MSG);
      return (- 1);
    }
  if (strcmp(str, BORDER) != 0)
    {
      fprintf(stderr, MAP_ERR_MSG);
      return (- 1);
    }
  return (0);
}

int	my_check_line(char *str)
{
  int	i;
  int	space_true;

  i = 0;
  space_true = 1;
  if (str[0] != '|' || str[LINE] != '|')
    {
      fprintf(stderr, MAP_ERR_MSG);
      return (-1);
    }
  while (++i != LINE)
    {
      if (space_true == 1 && str[i] != ' ')
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      else if (space_true == 0 && str[i] <= '0' && str[i] >'9')
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      space_true = 1 - space_true;
    }
  return (0);
}

int	*my_get_line(int fd)
{
  char	*s;
  int	i;
  int	*line;

  i = 0;
  if ((s = get_next_line(fd)) == NULL)
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
      line[i] = s[i] - 48;
      i++;
    }
  return (line);
}

int	**my_init_grid(int fd)
{
  int	**tab;
  int	i;

  i = -1;
  if ((tab = malloc(sizeof(int *) * (SIZE))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  while (++i < SIZE)
    if ((tab[i] = my_get_line(fd)) == NULL)
      return (NULL);
  if (check_border(fd) == - 1)
    return (NULL);
  return (tab);
}

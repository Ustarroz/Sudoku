/*
** init_grid.c for sudoku in /home/voyevoda/rendu/prog_elem/sudoki-bi/src
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Fri Feb 26 21:37:53 2016 Voyevoda
** Last update Sun Feb 28 16:18:44 2016 Voyevoda
*/

#include "sudoki.h"


 int	check_char(char *str, t_variant *alphabet, int i)
 {
  }

int	my_check_line(char *str, t_variant *alphabet)
{
  int	i;
  int	space;

  i = 0;
  space = 1;
  if (str[0] != '|' || str[alphabet->line] != '|')
    {
      fprintf(stderr, MAP_ERR_MSG);
      return (-1);
    }
  while (++i != alphabet->size)
    {
      if (space == 1 && str[i] != ' ')
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      else if (space == 0 && (str_to_int(str, alphabet, i) == -1))
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      space = 1 - space;
    }
  return (0);
}

int	str_to_int(char *s, int *line, t_variant *alphabet)
{
  int	i;
  int	j;
  int	k;

  j = -1;
  i = 2;
  k = -1;
  while (alphabet->base[++k] != '\0')
    {
      if (alphabet->base[k] == str[i])
	while (++j != alphabet->size)
	  {
	    if (s[i] == ' ')
	      line[j] = 0;
	    else
	      {
		line[j] = k + 1;
		return (0);
	      }
	    i = i + 2;
	  }
    }
  return (-1);
}

int	*my_get_line(int fd, t_variant *alphabet)
{
  char	*s;
  int	*line;

  if ((s = get_next_line(fd)) == NULL)
    {
      fprintf(stderr, READ_ERR_MSG);
      return (NULL);
    }
  if ((line = malloc(sizeof(int) * (alphabet->size))) == NULL)
    {
      free(s);
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  if ((my_check_line(s, alphabet)) == -1)
    {
      free(s);
      return (NULL);
    }
  free(s);
  return (line);
}

int	**my_init_grid(int fd, t_variant *alphabet)
{
  int	**tab;
  int	i;
  int	check;

  i = -1;
  if ((tab = malloc(sizeof(int *) * (alphabet->size))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  while (++i < SIZE)
    if ((tab[i] = my_get_line(fd, alphabet)) == NULL)
      return (NULL);
  if ((check = check_border(fd, alphabet)) == - 1)
    {
      fprintf(stderr, READ_ERR_MSG);
      return (NULL);
    }
  else if (check == - 2)
    return (NULL);
  return (tab);
}

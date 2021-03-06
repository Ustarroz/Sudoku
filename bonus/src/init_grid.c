/*
** init_grid.c for sudoku in /home/voyevoda/rendu/prog_elem/sudoki-bi/src
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Fri Feb 26 21:37:53 2016 Voyevoda
** Last update Sun Feb 28 20:39:32 2016 Voyevoda
*/

#include "sudoki.h"

int	str_to_int(char *s, int *line, t_variant *alphabet, int i)
{
  int	k;

  k = -1;
  if (s[i] == ' ')
    {
      line[i / 2 - 1] = 0;
      return (0);
    }
  while (alphabet->base[++k] != '\0')
    {
      if (alphabet->base[k] == s[i])
	{
	  line[i / 2 - 1] = - k - 1;
	  return (0);
	}
    }
  return (-1);
}

int	my_check_line(char *str, t_variant *alphabet, int *line)
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
  while (++i != alphabet->line)
    {
      if (space == 1 && str[i] != ' ')
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      else if (space == 0 && (str_to_int(str, line,  alphabet, i) == -1))
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      space = 1 - space;
    }
  return (0);
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
  if ((my_check_line(s, alphabet, line)) == -1)
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
  while (++i < alphabet->size)
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

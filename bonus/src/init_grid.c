/*
** init_grid.c for sudoku in /home/voyevoda/rendu/prog_elem/sudoki-bi/src
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Fri Feb 26 21:37:53 2016 Voyevoda
** Last update Sun Feb 28 15:17:23 2016 Voyevoda
*/

#include "sudoki.h"


 int	check_char(char *str, t_variant *alphabet, int i)
 {
   int	j;

   j = -1;
   while (alphabet->base[++j] != '\0')
     {
       if (alphabet->base[j] == str[i])
	 return (0);
     }
   fprintf(stderr, MAP_ERR_MSG);
   return (-1);
 }

int	my_check_line(char *str)
{
  int	i;
  int	space;

  i = 0;
  space = 1;
  if (str[0] != '|' || str[LINE] != '|')
    {
      fprintf(stderr, MAP_ERR_MSG);
      return (-1);
    }
  while (++i != LINE)
    {
      if (space == 1 && str[i] != ' ')
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      else if (space == 0 && (check_char == -1))
	{
	  fprintf(stderr, MAP_ERR_MSG);
	  return (-1);
	}
      space = 1 - space;
    }
  return (0);
}

void	str_to_int(char *s, int *line)
{
  int	i;
  int	j;

  j = -1;
  i = 2;
  while (++j != SIZE)
    {
      if (s[i] == ' ')
	line[j] = 0;
      else
	line[j] =  48 - s[i];
      i = i + 2;
    }
}

int	*my_get_line(int fd)
{
  char	*s;
  int	*line;

  if ((s = get_next_line(fd)) == NULL)
    {
      fprintf(stderr, READ_ERR_MSG);
      return (NULL);
    }
  if ((line = malloc(sizeof(int) * (SIZE))) == NULL)
    {
      free(s);
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  if ((my_check_line(s)) == -1)
    {
      free(s);
      return (NULL);
    }
  str_to_int(s, line);
  free(s);
  return (line);
}

int	**my_init_grid(int fd, t_variant *alphabet)
{
  int	**tab;
  int	i;
  int	check;

  i = -1;
  if ((tab = malloc(sizeof(int *) * (SIZE))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  while (++i < SIZE)
    if ((tab[i] = my_get_line(fd)) == NULL)
      return (NULL);
  if ((check = check_border(fd)) == - 1)
    {
      fprintf(stderr, READ_ERR_MSG);
      return (NULL);
    }
  else if (check == - 2)
    return (NULL);
  return (tab);
}

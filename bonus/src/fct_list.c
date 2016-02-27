/*
** fct_list.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 21:10:32 2016 edouard puillandre
** Last update Sat Feb 27 22:34:49 2016 edouard puillandre
*/

#include "sudoki.h"

int		add_elem(t_sudo *sudo, int fd)
{
  t_grid	*grid;

  if ((grid = malloc(sizeof(t_grid))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (- 1);
    }
  if ((grid->tab = my_init_grid(fd)) == NULL)
    return (- 1);
  if (check_grid(grid->tab) == - 1)
    fill_minus_one(grid->tab);
  grid->next = NULL;
  if (sudo->first == NULL)
    {
      sudo->first = grid;
      sudo->last = grid;
    }
  else
    {
      sudo->last->next = grid;
      sudo->last = grid;
    }
  return (0);
}

t_sudo		*my_init_sudo()
{
  t_sudo	*sudo;
  int		check;

  if ((sudo = malloc(sizeof(t_sudo))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  sudo->first = NULL;
  sudo->last = NULL;
  while ((check = check_border(0)) == 0)
    if (add_elem(sudo, 0) == - 1)
      return (NULL);
  if (check == - 2)
    return (NULL);
  return (sudo->first == NULL ? NULL : sudo);
}

void		free_sudo(t_sudo *sudo)
{
  t_grid	*tmp;
  t_grid	*elem;
  int		i;

  tmp = sudo->first;
  while (tmp != NULL)
    {
      i = - 1;
      while (++i < SIZE)
	free(tmp->tab[i]);
      free(tmp->tab);
      elem = tmp;
      tmp = tmp->next;
      free(elem);
    }
  free(sudo);
}

void	my_print_grid(int **grid)
{
  int	i;
  int	j;

  i = - 1;
  printf(BORDER);
  printf("\n");
  while (++i < SIZE)
    {
      j = - 1;
      printf("|");
      while (++j < SIZE)
	if (grid[i][j] == 10)
	  printf(" X");
	else
	  printf(" %d", ABS(grid[i][j]));
      printf("|\n");
    }
  printf(BORDER);
  printf("\n");
}

void		my_print_sudo(t_sudo *sudo)
{
  t_grid	*tmp;

  tmp = sudo->first;
  while (tmp != NULL)
    {
      my_print_grid(tmp->tab);
      tmp = tmp->next;
      if (tmp != NULL)
	printf(SEPARATOR);
    }
}

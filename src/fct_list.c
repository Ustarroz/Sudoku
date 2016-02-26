/*
** fct_list.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Feb 26 21:10:32 2016 edouard puillandre
** Last update Fri Feb 26 23:44:43 2016 edouard puillandre
*/

#include "sudoki.h"

int		add_elem(t_sudo *sudo, int fd)
{
  s_grid	*grid;

  if ((grid = malloc(sizeof(s_grid))) == NULL)
    {
      fprintf(stderr, MALLOC_ERR_MSG);
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
    sudo->last->next = grid;
  return (0);
}

s_sudo		*my_create_sudo(char *str)
{
  s_sudo	*sudo;
  int		fd;

  if ((fd = open(str, O_RDONLY)) == - 1)
    {
      fprintf(stderr, OPEN_ERR_MSG);
      return (NULL);
    }
  if ((sudo = malloc(sizeof(s_sudo))) == NULL)
    {
      fprintf(stderr, OPEN_ERR_MSG);
      return (NULL);
    }
  sudo->first = NULL;
  sudo->last = NULL;
  while (my_check_border(fd) == 0)
    if (add_elem(sudo, fd) == - 1)
      return (NULL);
  return (sudo.first == NULL ? NULL : sudo);
}

void		free_sudo(s_sudo *sudo)
{
  s_grid	*tmp;
  s_grid	*elem;
  int		i;

  tmp = sudo->first;
  while (tmp != NULL)
    {
      i = - 1;
      while (++i < SIZE)
	free(grid->tab[i]);
      free(grid->tab);
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
  while (i < SIZE)
    {
      j = - 1;
      printf("|");
      while (j < SIZE)
	if (tab[i][j] == - 1)
	  printf(" X");
	else
	  printf(" %d", tab[i][j]);
      printf("|");
    }
  printf(BORDER);
}

void		my_print_sudo(s_sudo *sudo)
{
  s_grid	*tmp;

  tmp = sudo->first;
  while (tmp != NULL)
    {
      my_print_grid(tmp->tab);
      tmp = tmp->next;
      if (tmp != NULL)
	printf(LINE_SEPARATOR);
    }
}

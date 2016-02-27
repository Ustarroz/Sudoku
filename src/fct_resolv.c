/*
** fct_resolv.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 23:49:08 2016 edouard puillandre
** Last update Sat Feb 27 17:02:13 2016 edouard puillandre
*/

#include "sudoki.h"

int	resolve_line(int **tab, int *i, int dir)
{
  int	j;

  j = (dir == 1) ? 0 : 8;
  while (j < SIZE)
    {
      if (tab[*i][j] >= 0)
	{
	  tab[*i][j] = tab[*i][j] + 1;
	  if (tab[*i][j] == 10)
	    {
	      tab[*i][j] = 0;
	      dir = - 1;
	    }
	  else if (check_column(tab, *i, LINE_TRUE) == - 1 ||
		   check_column(tab, *i, COL_TRUE) == - 1 ||
		   check_square(tab, *i / SQUARE, j / SQUARE) == - 1)
	    {
	      if (tab[*i][j] == 9)
		{
		  tab[*i][j] = 0;
		  dir = - 1;
		}
	      else
		dir = 0;
	    }
	  else
	    dir = 1;
	}
      j = j + dir;
      if (j < 0)
	{
	  *i = *i - 2;
	  return (- 1);
	}
    }
  return (1);
}

int	my_resolve_brute(int **tab)
{
  int	i;
  int	dir;

  i = - 1;
  dir = 1;
  while (++i < SIZE)
    {
      dir = resolve_line(tab, &i, dir);
      printf("i = %d\tdir = %d\n", i, dir);
      my_print_grid(tab);
      if (i < - 1)
	{
	  fill_minus_one(tab);
	  return (0);
	}
    }
  return (0);
}

void		my_resolve_all(t_sudo *sudo)
{
  t_grid	*tmp;

  tmp = sudo->first;
  while (tmp != NULL)
    {
      my_resolve_brute(tmp->tab);
      tmp = tmp->next;
    }
}

/*
** fct_resolv.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Feb 26 23:49:08 2016 edouard puillandre
** Last update Sat Feb 27 15:50:52 2016 edouard puillandre
*/

#include "sudoki.h"

int	resolve_line(int **tab, int *i)
{
  int	j;

  j = - 1;
  while (++j < SIZE)
    {
      tab[*i][j] = tab[*i][j] + 1;
      if (check_column(tab, *i, LINE_TRUE) == - 1 ||
	  check_column(tab, *i, COL_TRUE) == - 1 ||
	  check_square(tab, *i / SQUARE, j / SQUARE) == - 1)
	{
	  check = 1;
	  if (tab[*i][j] == 9)
	    {
	      tab[*i][j] = 0;
	      j = j - 2;
	    }
	  else
	    j = j - 1;
	}
      if (j < - 1)
	{
	  *i = *i - 2;
	  return (1);
	}
    }
  return (0);
}

int	my_resolve_brute(int **tab)
{
  int	i;
  int	check;

  i = - 1;
  while (++i < SIZE)
    {
      resolve_line(tab, &i);
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

/*
** fct_resolv.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 23:49:08 2016 edouard puillandre
** Last update Sat Feb 27 18:24:16 2016 edouard puillandre
*/

#include "sudoki.h"

int	next_digit(int **tab, int i, int j)
{
  int	check;
  int	k;
  int	l;

  check = 0;
  k = - 1;
  while (++k < SIZE)
    if (tab[i][k] != 0)
      check = check | 1 << (ABS(tab[i][k]) - 1);
  k = - 1;
  while (++k < SIZE)
    if (tab[k][j] != 0 && k != i)
      check = check | 1 << (ABS(tab[k][j]) - 1);
  k = i / SQUARE * SQUARE- 1;
  while (++k < (i / SQUARE + 1) * SQUARE)
    {
      l = (k == i) ? (j / SQUARE + 1) * SQUARE : j / SQUARE * SQUARE- 1;
      while (++l < (j / SQUARE + 1) * SQUARE)
	if (tab[k][l] != 0 && l != j)
	  check = check | 1 << (ABS(tab[k][l]) - 1);
    }
  k = - 1;
  while(++k < SIZE)
    {
      if ((check & 1) == 0)
	return (k + 1);
      check = check >> 1;
    }
  return (0);
}

int	resolve_line(int **tab, int *i, int dir)
{
  int	j;

  j = (dir == 1) ? 0 : 8;
  while (j < SIZE)
    {
      if (tab[*i][j] >= 0)
	{
	  tab[*i][j] = next_digit(tab, *i, j);
	  if (tab[*i][j] == 0)
	    dir = - 1;
	  else
	    dir = 1;
	}
      j = j + dir;
      if (j < 0)
	return (- 1);
      /* printf("j = %d\tdir = %d\n", j, dir); */
      /* my_print_grid(tab); */
    }
  return (1);
}

int	my_resolve_brute(int **tab)
{
  int	i;
  int	dir;

  i = 0;
  dir = 1;
  while (i < SIZE)
    {
      dir = resolve_line(tab, &i, dir);
      printf("i = %d\tdir = %d\n", i, dir);
      my_print_grid(tab);
      i = i + dir;
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

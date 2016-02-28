/*
** fct_resolv.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 23:49:08 2016 edouard puillandre
** Last update Sun Feb 28 15:23:45 2016 edouard puillandre
*/

#include "sudoki.h"

int	check_line_col(int **tab, int i, t_variant *alph)
{
  int	k;
  int	check;

  k = - 1;
  check = 0;
  while (++k < alph->size)
    if (tab[i][k] != 0)
      check = check | 1 << (ABS(tab[i][k]) - 1);
  return (check);
}

int	check_in_col(int **tab, int j, t_variant *alph, int check)
{
  int	k;

  k = - 1;
  while (++k < alph->size)
    if (tab[k][j] != 0)
      check = check | 1 << (ABS(tab[k][j]) - 1);
  return (check);
}

int	next_digit(int **tab, int i, int j, t_variant *alph)
{
  int	check;
  int	k;
  int	l;

  check = check_in_line(tab, i, alph);
  check = check_in_col(tab, j, alph, check);
  k = i / alph->square * alph->square - 1;
  while (++k < (i / alph->square + 1) * alph->square)
    {
      if (k == i)
	l = (j / alph->square + 1) * alph->square;
      else
	l = j / alph->square * alph->square - 1;
      while (++l < (j / alph->square + 1) * alph->square)
	if (tab[k][l] != 0 && l != j)
	  check = check | 1 << (ABS(tab[k][l]) - 1);
    }
  k = - 1;
  while (++k < alph->size)
    {
      if ((check & 1) == 0 && (k + 1) > tab[i][j])
	return (k + 1);
      check = check >> 1;
    }
  return (0);
}

int	resolve_line(int **tab, int *i, int dir, t_variant *alph)
{
  int	j;

  j = (dir == 1) ? 0 : alph->size - 1;
  while (j < alph->size)
    {
      if (tab[*i][j] >= 0)
	{
	  tab[*i][j] = next_digit(tab, *i, j, alph);
	  if (tab[*i][j] == 0)
	    dir = - 1;
	  else
	    dir = 1;
	}
      j = j + dir;
      if (j < 0)
	return (- 1);
    }
  return (1);
}

void		my_resolve_all(t_sudo *sudo)
{
  t_grid	*tmp;
  int		i;
  int		dir;

  tmp = sudo->first;
  while (tmp != NULL)
    {
      i = 0;
      dir = 1;
      while (i < sudo->alph->size)
	{
	  dir = resolve_line(tmp->tab, &i, dir, sudo->alph);
	  i = i + dir;
	  if (i < 0)
	    {
	      i = sudo->alph->size;
	      fill_minus_one(tmp->tab, alph);
	    }
	}
      tmp = tmp->next;
    }
}

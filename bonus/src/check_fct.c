/*
** check_fct.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 22:33:33 2016 edouard puillandre
** Last update Sun Feb 28 16:24:31 2016 Voyevoda
*/

#include "sudoki.h"

void	fill_minus_one(int **tab, t_variant *alph)
{
  int	i;
  int	j;

  i = - 1;
  while (++i < alph->size)
    {
      j = - 1;
      while (++j < alph->size)
	tab[i][j] = alph->size + 1;
    }
}

int	check_digit(int nb, int *check)
{
  int	a;

  if (nb == 0)
    return (0);
  a = 1 << (ABS(nb) - 1);
  if ((a & *check) == 0)
    *check = *check | a;
  else
    return (- 1);
  return (0);
}

int	check_column(int **tab, int i, int line_true, t_variant *alph)
{
  int	j;
  int	check;

  j = - 1;
  check = 0;
  while (++j < alph->size)
    {
      if (line_true == 0)
	{
	  if (check_digit(tab[j][i], &check) == - 1)
	    return (- 1);
	}
      else
	if (check_digit(tab[i][j], &check) == - 1)
	  return (- 1);
    }
  return (0);
}

int	check_square(int **tab, int i_beg, int j_beg, t_variant *alph)
{
  int	check;
  int	i;
  int	j;

  check = 0;
  i = i_beg * alph->square;
  while (i < alph->square * (1 + i_beg))
    {
      j = j_beg * alph->square;
      while (j < alph->square * (1 + j_beg))
	{
	  if (check_digit(tab[i][j], &check) == - 1)
	    return (- 1);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

int	check_grid(int **tab, t_variant *alph)
{
  int	i;
  int	j;

  i = - 1;
  while (++i < alph->size)
    if (check_column(tab, i, COL_TRUE, alph) == - 1)
      return (- 1);
  i = - 1;
  while (++i < alph->size)
    if (check_column(tab, i, LINE_TRUE, alph) == - 1)
      return (- 1);
  i = - 1;
  while (++i < alph->square)
    {
      j = - 1;
      while (++j < alph->square)
	if (check_square(tab, i, j, alph) == - 1)
	  return (- 1);
    }
  return (0);
}

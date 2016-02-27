/*
** check_fct.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Feb 26 22:33:33 2016 edouard puillandre
** Last update Sat Feb 27 15:21:30 2016 edouard puillandre
*/

#include "sudoki.h"

void	fill_minus_one(int **tab)
{
  int	i;
  int	j;

  i = - 1;
  while (++i < SIZE)
    {
      j = - 1;
      while (++j < SIZE)
	tab[i][j] = - 1;
    }
}

int	check_digit(int nb, int *check)
{
  int	a;

  if (nb == 0)
    return (0);
  a = 1 << (nb - 1);
  if ((a & *check) == 0)
    *check = *check | a;
  else
    return (- 1);
  return (0);
}

int	check_column(int **tab, int i, int line_true)
{
  int	j;
  int	check;

  j = - 1;
  check = 0;
  while (++j < SIZE)
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

int	check_square(int **tab, int i_beg, int j_beg)
{
  int	check;
  int	i;
  int	j;

  check = 0;
  i = i_beg * SQUARE;
  while (i < SQUARE * (1 + i_beg))
    {
      j = j_beg * SQUARE;
      while (j < SQUARE * (1 + j_beg))
	{
	  if (check_digit(tab[i][j], &check) == - 1)
	    return (- 1);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

int	check_grid(int **tab)
{
  int	i;
  int	j;

  i = - 1;
  while (++i < SIZE)
    if (check_column(tab, i, COL_TRUE) == - 1)
      return (- 1);
  i = - 1;
  while (++i < SIZE)
    if (check_column(tab, i, LINE_TRUE) == - 1)
      return (- 1);
  i = - 1;
  while (++i < SQUARE)
    {
      j = - 1;
      while (++j < SQUARE)
	if (check_square(tab, i, j) == - 1)
	  return (- 1);
    }
  return (0);
}

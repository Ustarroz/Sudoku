/*
** fct_list.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 21:10:32 2016 edouard puillandre
** Last update Sun Feb 28 14:41:30 2016 edouard puillandre
*/

#include "sudoki.h"

void	my_print_border(t_variant *alph)
{
  int	i;

  i = 0;
  printf("|");
  while (++i < alph->line)
    printf("-");
  printf("|\n");
}

void	my_print_grid(int **grid, t_variant *alph)
{
  int	i;
  int	j;

  i = - 1;
  my_print_border(alph);
  while (++i < alph-<size)
    {
      j = - 1;
      printf("|");
      while (++j < alph->size)
	if (grid[i][j] >= alph->size || grid[i][j] <= 0)
	  printf(" ?");
	else
	  printf(" %d", alph->base[ABS(grid[i][j]) - 1]);
      printf("|\n");
    }
  my_print_border(alph);
}

void		my_print_sudo(t_sudo *sudo)
{
  t_grid	*tmp;
  int		i;

  tmp = sudo->first;
  while (tmp != NULL)
    {
      my_print_grid(tmp->tab, sudo->alph);
      tmp = tmp->next;
      if (tmp != NULL)
	{
	  i = - 1;
	  while (++i < alph->line)
	    printf("#");
	  printf("#\n");
	}
    }
}

/*
** main.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/rendu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 18:57:29 2016 edouard puillandre
** Last update Fri Feb 26 21:25:47 2016 Voyevoda
*/

#include "sudoki.h"

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if ((my_init_grid(av[1]) == NULL);
	  return (1);
    }
  else
    fprintf(stderr, "%s\n", ARG_ERG_MSG);
  return (0);
}

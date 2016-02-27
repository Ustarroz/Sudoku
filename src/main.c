/*
** main.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/rendu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 18:57:29 2016 edouard puillandre
** Last update Sat Feb 27 14:18:20 2016 edouard puillandre
*/

#include "sudoki.h"

int		main(int ac, char **av)
{
  t_sudo	*sudo;

  if (ac != 2)
    {
      fprintf(stderr, "%s\n", ARG_ERR_MSG);
      return (1);
    }
  if ((sudo = my_init_sudo(av[1])) == NULL)
    return (1);
  my_print_sudo(sudo);
  free_sudo(sudo);
  return (0);
}

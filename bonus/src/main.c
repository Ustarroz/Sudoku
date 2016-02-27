/*
** main.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/rendu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 18:57:29 2016 edouard puillandre
** Last update Sat Feb 27 18:54:38 2016 Voyevoda
*/

#include "sudoki.h"

int	check_av(char *av)
{
  if (opendir(av) != NULL)
    {
      fprintf(stderr, OPEN_ERR_MSG);
      return (-1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_sudo	*sudo;

  if (ac != 2)
    {
      fprintf(stderr, "%s", ARG_ERR_MSG);
      return (1);
    }
  if ((check_av(av[1])) == -1)
    return (-1);
  if ((sudo = my_init_sudo(av[1])) == NULL)
    return (1);
  my_resolve_all(sudo);
  my_print_sudo(sudo);
  free_sudo(sudo);
  return (0);
}
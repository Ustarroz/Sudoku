/*
** main.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/rendu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 18:57:29 2016 edouard puillandre
<<<<<<< HEAD
** Last update Sat Feb 27 14:36:36 2016 Voyevoda
=======
** Last update Sat Feb 27 14:18:20 2016 edouard puillandre
>>>>>>> bd894e6bba5c7218c006f4690185890e24203417
*/

#include "sudoki.h"

int		main(int ac, char **av)
{
  t_sudo	*sudo;

  write(1, "a", 1);
  if (ac != 2)
    {
      fprintf(stderr, "%s\n", ARG_ERR_MSG);
      return (1);
    }
  if ((sudo = my_init_sudo(av[1])) == NULL)
    return (1);
  write(1, "sortie initsudo\n", 16);
  my_print_sudo(sudo);
  write(1, "sorti printsudo\n", 16);
  free_sudo(sudo);
  return (0);
}

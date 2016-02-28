/*
** main.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/rendu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 18:57:29 2016 edouard puillandre
** Last update Sun Feb 28 15:32:57 2016 Voyevoda
*/

#include "sudoki.h"

int	check_av(char *str)
{
  int	len;
  int	i;
  int	k;

  len = strlen(str);
  if (len != SIZE_DOUBLE || len != SIZE_TRIPLE ||
      len != SIZE_QUADRA || len != SIZE_PENTA)
    return (1);
  i = - 1;
  while (str[++i] != '\0')
    {
      k = i;
      while (str[++k] != '\0')
	if (str[k] == str[i])
	  {
	    fprintf(stderr, DOUBLE_ERR_MSG);
	    return (1);
	  }
    }
  k = - 1;
  return (0);
}

t_variant	*init_variant()
{
  t_variant	*alpha;

  if ((alpha = malloc(sizeof(t_variant))) == NULL)
    return (NULL);
  return (alpha);
}

int		main(int ac, char **av)
{
  t_sudo	*sudo;
  t_variant	*alphabet;

  if ((alphabet = init_variant()) == NULL)
    return (1);
  if (ac != 2 || check_av(av[1]) == 1)
    {
      fprintf(stderr, ARG_ERR_MSG);
      return (1);
    }
  if ((sudo = my_init_sudo(alphabet)) == NULL)
    return (1);
  my_resolve_all(sudo);
  my_print_sudo(sudo);
  free_sudo(sudo);
  return (0);
}

/*
** main.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/rendu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 18:57:29 2016 edouard puillandre
** Last update Sun Feb 28 16:38:00 2016 edouard puillandre
*/

#include "sudoki.h"

int	check_av(char *str)
{
  int	len;
  int	i;
  int	k;

  len = strlen(str);
  if (len != SIZE_DOUBLE && len != SIZE_TRIPLE &&
      len != SIZE_QUADRA && len != SIZE_PENTA)
    return (2);
  i = - 1;
  while (str[++i] != '\0')
    if (str[i] == ' ' || str[i] == '?')
      return (3);
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
  return (0);
}

t_variant	*init_variant(char *str)
{
  t_variant	*alpha;
  int		i;

  if ((alpha = malloc(sizeof(t_variant))) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  alpha->size = strlen(str);
  if ((alpha->base = strdup(str)) == NULL)
    {
      fprintf(stderr, MAL_ERR_MSG);
      return (NULL);
    }
  alpha->line = alpha->size * 2 + 1;
  i = 2;
  while (i * i < alpha->size)
    i = i + 1;
  alpha->square = i;
  return (alpha);
}

int		main(int ac, char **av)
{
  t_sudo	*sudo;
  t_variant	*alphabet;
  int		check;

  if (ac != 2)
    {
      fprintf(stderr, ARG_ERR_MSG);
      return (1);
    }
  if ((check = check_av(av[1])) >= 1)
    {
      if (check == 3)
	fprintf(stderr, INC_ERR_MSG);
      else if (check == 2)
	fprintf(stderr, LEN_ERR_MSG);
      return (1);
    }
  if ((alphabet = init_variant(av[1])) == NULL)
    return (1);
  if ((sudo = my_init_sudo(alphabet)) == NULL)
    return (1);
  my_resolve_all(sudo);
  my_print_sudo(sudo);
  free_sudo(sudo);
  return (0);
}

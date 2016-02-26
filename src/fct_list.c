/*
** fct_list.c for sudoki-bi in /home/puilla_e/Semestre2/progelem/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Feb 26 21:10:32 2016 edouard puillandre
** Last update Fri Feb 26 21:29:00 2016 edouard puillandre
*/

#include "sudoki.h"

s_sudo		*my_create_sudo(char *str)
{
  s_sudo	*sudo;
  int		fd;

  if ((fd = open(str, O_RDONLY)) == - 1)
    {
      fprintf(stderr, OPEN_ERR_MSG);
      return (NULL);
    }
  if ((sudo = malloc(sizeof(s_sudo))) == NULL)
    {
      fprintf(stderr, OPEN_ERR_MSG);
      return (NULL);
    }
  while (add_new_elem(
}

/*
** sudoki.h for sudoki-bi in /home/puilla_e/Semestre2/progelem/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Feb 26 18:56:22 2016 edouard puillandre
** Last update Fri Feb 26 20:35:42 2016 edouard puillandre
*/

#ifndef		SUDOKI_H_
# define	SUDOKI_H_

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct	s_sudo
{
  int		*tab;
  struct s_sudo	*next;
}		t_sudo;

#endif /* !SUDOKI_H_ */
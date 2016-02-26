/*
** sudoki.h for sudoki-bi in /home/puilla_e/Semestre2/progelem/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Feb 26 18:56:22 2016 edouard puillandre
** Last update Fri Feb 26 21:09:10 2016 edouard puillandre
*/

#ifndef		SUDOKI_H_
# define	SUDOKI_H_

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

# define SIZE (9)

typedef struct	s_grid
{
  int		**tab;
  struct s_sudo	*next;
}		t_grid;

typedef struct	s_sudo
{
  t_sudo	*first;
  t_sudo	*last;
}		t_sudo;

s_sudo	*my_init_sudo(char *str);
int	**my_init_grid(int fd);
int	*my_get_line(int fd);
int	my_check_line(char *str);
int	check_grid(int **tab);
void	my_print_grid(int **tab);
void	my_print_sudo(s_sudo *sudo);
int	my_resolve_grid(int **tab);

#endif /* !SUDOKI_H_ */

/*
** sudoki.h for sudoki-bi in /home/puilla_e/Semestre2/progelem/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Feb 26 18:56:22 2016 edouard puillandre
** Last update Sun Feb 28 15:28:38 2016 edouard puillandre
*/

#ifndef		SUDOKI_H_
# define	SUDOKI_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

# define COL_TRUE (1)
# define LINE_TRUE (0)
# define MAL_ERR_MSG "Malloc error\n"
# define ARG_ERR_MSG "Incorrect number of argument\n"
# define MAP_ERR_MSG "MAP ERROR\n"
# define OPEN_ERR_MSG "Open file error\n"
# define READ_ERR_MSG "Read error\n"
# define DOUBLE_ERR_MSG "Error: char two times in your base!\n"
# define ABS(x) ((x) < 0 ? - (x) : (x))
# define SIZE_DOUBLE (4)
# define SIZE_TRIPLE (9)
# define SIZE_QUADRA (16)
# define SIZE_PENTA (25)
# define SQUARE_DOUBLE (2)
# define SQUARE_TRIPLE (3)
# define SQUARE_QUADRA (4)
# define SQUARE_PENTA (5)
# define LINE_DOUBLE (9)
# define LINE_TRIPLE (19)
# define LINE_QUADRA (33)
# define LINE_PENTA (51)
# define SEPARATOR "####################\n"
# define BORDER "|------------------|"

typedef struct	s_grid
{
  int		**tab;
  struct s_grid	*next;
}		t_grid;

typedef struct	s_variant
{
  int		size;
  int		square;
  int		line;
  char		*base;
}		t_variant;

typedef struct	s_sudo
{
  t_grid	*first;
  t_grid	*last;
  t_variant	*alph;
}		t_sudo;

t_sudo	*my_init_sudo(t_variant *alph);
int	**my_init_grid(int fd, t_variant *alph);
int	*my_get_line(int fd);
int	my_check_line(char *str);
int	check_border(int fd);
int	check_grid(int **tab);
int	check_digit(int nb, int *check);
int	check_column(int **tab, int i, int line_true);
int	check_square(int **tab, int i, int j);
void	my_print_grid(int **tab, t_variant *alph);
void	my_print_sudo(t_sudo *sudo);
int	my_resolve_grid(int **tab, t_variant *alph);
int	my_check_border(int fd);
void	fill_minus_one(int **tab);
int	my_resolve_softer(int **tab);
int	my_resolve_brute(int **tab);
void	my_resolve_all(t_sudo *sudo);
void	free_sudo(t_sudo *sudo);

#endif /* !SUDOKI_H_ */

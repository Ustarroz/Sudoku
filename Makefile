##
## Makefile for Makefile in /home/puilla_e/
## 
## Made by edouard puillandre
## Login   <puilla_e@epitech.net>
## 
## Started on  Mon Oct 12 20:34:36 2015 edouard puillandre
## Last update Thu Feb 18 10:40:34 2016 edouard puillandre
##

DEBUG	=	yes

CC	=	gcc

CFLAGS	=	-Iinclude	\
		-Wall		\
		-Wextra		\
		-Werror		\
		-std=c99

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g		\
		-D DEBUG	
endif

LDFLAGS	=	-lmy	\
		-L./lib/

SRC	=	main.c

RM	=	rm -f

NAME	=	nom

OBJ	=	$(SRC:.c=.o)

$(NAME): $(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 2; tput bold
	@echo
	@echo Debug mode
	@echo
	@tput sgr0
endif
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

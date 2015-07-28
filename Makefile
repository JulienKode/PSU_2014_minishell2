##
## Makefile for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell1
## 
## Made by Julien Karst
## Login   <karst_j@epitech.net>
## 
## Started on  Sat Jan 24 13:37:32 2015 Julien Karst
## Last update Sun Mar  8 14:20:44 2015 Julien Karst
##

NAME	= mysh

CC 	= gcc

CFLAGS	= -I./include  -g

LDFLAGS	= -L./lib -lmy

SCR	= src/main.c \
	  src/parse_env.c \
	  src/minishell.c \
	  src/minishell2.c \
	  src/my_events.c \
	  src/check_error.c \
	  src/my_cd.c \
	  src/my_cd2.c \
	  src/my_exec.c \
	  src/my_env.c \
	  src/my_pipe.c \
	  src/parse_arg.c \
	  src/cpy_arg.c \
	  src/my_redir.c \
	  src/my_redir_left.c \
	  src/my_command.c

OBJ	= $(SCR:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

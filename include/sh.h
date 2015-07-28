/*
** sh.h for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell1
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Sat Jan 24 13:48:03 2015 Julien Karst
** Last update Sun Mar  8 15:00:38 2015 Julien Karst
*/

#ifndef SH_H_
# define SH_H_

#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <signal.h>
#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "my_str_to_wordtab.h"

#define PROMPT "\033[32m[%s@localhost ~]$> \033[0m"

typedef struct	s_pipe
{
  char		**pos1;
  char		*op;
  char		**pos2;
  int		pipefd[2];
  int		fd;
}		t_pipe;

typedef struct	s_env
{
  char		**env;
  char		*term;
  char		*shell;
  char		*user;
  char		*path_long;
  char		**path;
  char		*home;
  char		*old_pwd;
  char		*pwd;  
  char		*buff;
  char		*file;
  char		**arg;
  t_pipe	*a;
  int		mode;
}		t_env;

extern t_env	*e;

char		*detect(char **env, char *d);
char		*s_detect(char *env, int c);
int		i_detect(char *d, char *env);
void		add_to_struct(t_env *e);
int		minishell(t_env *e);
void		exec_fonc(t_env *e);
int		recode_command(t_env *e, t_pipe *a);
void		exec_command(t_env *e, t_pipe *a);
int		detect_cmd(char *str, char *cmd);
void		signal_sig();
void		my_shell_exit(t_env *e, t_pipe *a);
void		my_clear(t_env *e);
void		my_echo(t_env *e);
void		check_fail(t_env *e);
int		good_path(t_env *e, t_pipe *a);
void		my_cd(t_env *e, t_pipe *a);
char		*my_tilt(t_env *e, t_pipe *a);
int		check_access(char *path);
void		signal_sig2();
int		just_shit(char *str);
void		my_exec_dot(t_env *e, t_pipe *a);
void		my_unsetenv(t_env *e, t_pipe *a);
void		my_print_env(t_env *e);
int		size_env(t_env *e);
void		my_setenv(t_env *e, t_pipe *a);
void		cpy_pos(t_env *e, int i, int nb);
void		cpy_arg2(t_env *e, int i, int nb);
void		cpy_arg(t_env *e, int i, int nb);
int		check_ac(char *str);
void		parse_arg(t_env *e);
int		nb_ac(char **arg);
void		my_pipe(t_env *e, t_pipe *a, int t);
void		my_parse(t_env *e);
void		my_exec(t_env *e, t_pipe *a);
void		minishell2(t_env *e, t_pipe *a);
void		father_pipe(t_env *e, t_pipe *a, pid_t pid);
void		soon_pipe(t_env *e, t_pipe *a, int t);
void		my_redir_right(t_env *e, t_pipe *a, int t, int mode);
void		soon_redir_right(t_env *e, t_pipe *a, int t, int mode);
void		father_redir_right(t_env *e, t_pipe *a, pid_t pid);
void		my_redir_left_double(t_env *e, t_pipe *a, int t);
void		my_separe(t_env *e, t_pipe *a);
void		my_minishell2(t_env *e, t_pipe *a, int *i);

#endif /* SH_H_ */

/*
** minishell.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell1
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Sat Jan 24 18:24:36 2015 Julien Karst
** Last update Sun Mar  8 15:00:18 2015 Julien Karst
*/

#include "sh.h"

int	minishell(t_env *e)
{
  my_clear(e);
  while (e->buff = get_next_line(0))
    {
      check_fail(e);
      if (e->buff[0] == 0 || just_shit(e->buff) == 0)
	my_printf(PROMPT, e->user);
      else
	exec_fonc(e);
    }
}

void	exec_fonc(t_env *e)
{
  e->arg = my_str_to_wordtab(e->buff, ' ');
  parse_arg(e);
  minishell2(e, e->a);
  my_printf("\033[32m[%s@localhost ~]$> \033[0m", e->user);
}

void	exec_command(t_env *e, t_pipe *a)
{
  pid_t	pid;
  int	status;

  e->mode = 1;
  if (recode_command(e, a) != 0)
    {
      my_printf(PROMPT, e->user);
      return ;
    }
  if ((pid = fork()) == -1)
    my_exit2("Error -> Fork Failed :(");
  if (pid == 0)
    my_exec(e, a);
  else
    {
      waitpid(pid, &status, WSTOPPED);
      e->mode = 2;
    }
}

int	recode_command(t_env *e, t_pipe *a)
{
  if (detect_cmd("cd", a->pos1[0]) == 1)
    my_cd(e, a);
  else if (detect_cmd("exit", a->pos1[0]) == 1)
    my_shell_exit(e, a);
  else if (detect_cmd("echo", a->pos1[0]) == 1)
    my_echo(e);
  else if (detect_cmd("unsetenv", a->pos1[0]) == 1)
    my_unsetenv(e, a);
  else if (detect_cmd("setenv", a->pos1[0]) == 1)
    my_setenv(e, a);
  else if (detect_cmd("env", a->pos1[0]) == 1)
    my_print_env(e);
  else
    return (0);
  add_to_struct(e);
  return (1);
}

int     detect_cmd(char *str, char *cmd)
{
  int   i;

  i = 0;
  if (cmd == NULL)
    return (0);
  while (str[i])
    {
      if (str[i] != cmd[i])
	return (0);
      i++;
    }
  return (1);
}

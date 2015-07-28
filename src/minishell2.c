/*
** minishell2.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Thu Mar  5 18:08:15 2015 Julien Karst
** Last update Sun Mar  8 15:00:41 2015 Julien Karst
*/

#include "sh.h"

void	minishell2(t_env *e, t_pipe *a)
{
  int	i;

  i = 0;
  if (a->op == NULL)
    exec_command(e, a);
  else if (detect_cmd(">>", a->op))
    my_redir_right(e, a, i, 1);
  else if (detect_cmd(">", a->op))
    my_redir_right(e, a, i, 0);
  else if (detect_cmd("<<", a->op))
    my_redir_left_double(e, a, i);
  else if (detect_cmd(";", a->op))
    my_separe(e, a);
  else
    my_minishell2(e, a, &i);
}

void	my_minishell2(t_env *e, t_pipe *a, int *i)
{
  while (a->op != NULL)
    {
      if (detect_cmd("|", a->op))
	{
	  while (detect_cmd("|", a->op))
	    my_pipe(e, a++, *i++);
	  my_pipe(e, a, *i);
	}
      a++;
      *i++;
    }
}

void	my_separe(t_env *e, t_pipe *a)
{
  while (detect_cmd(";", a->op))
    exec_command(e, a++);
  exec_command(e, a);
}

void	my_exec(t_env *e, t_pipe *a)
{
  int	i;

  i = 0;
  my_exec_dot(e, a);
  while (e->path[i])
    {
      if (good_path(e, a))
	execve(a->pos1[0], a->pos1, e->env);
      e->file = my_strcat_separe(e->path[i], a->pos1[0], '/');
      execve(e->file, a->pos1, e->env);
      i++;
    }
  my_printf("%e%e%e", "Bash ", a->pos1[0], ": unknown command...\n");
  exit(1);
}

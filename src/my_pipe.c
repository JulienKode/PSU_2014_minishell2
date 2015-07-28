/*
** my_pipe.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2/src
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Tue Feb  3 19:04:47 2015 Julien Karst
** Last update Sat Mar  7 20:53:07 2015 Julien Karst
*/

#include "sh.h"

void		my_pipe(t_env *e, t_pipe *a, int t)
{
  int		i;
  pid_t		pid;
  int		fail;

  if ((fail = pipe(a->pipefd)) == -1)
    my_printf("Error -> Pipe failed\n");
  if ((pid = fork()) == -1)
    my_printf("Error -> Fork failed\n");
  if (pid == 0)
    soon_pipe(e, a, t);
  else
    father_pipe(e, a, pid);
}

void		father_pipe(t_env *e, t_pipe *a, pid_t pid)
{
  t_pipe	*b;
  int		status;

  status = 0;
  e->mode = 2;
  b = a - 1;
  if (b->pipefd[0] != 0)
    close(b->pipefd[0]);
  if (a->pipefd[1] != 1)
    close(a->pipefd[1]);
  if (detect_cmd("|", a->op))
    waitpid(0, &status, WNOHANG);
  else
    waitpid(pid, &status, WSTOPPED);
}

void		soon_pipe(t_env *e, t_pipe *a, int t)
{
  t_pipe	*b;
  int		fail;

  if (t != 0)
    {
      b = a - 1;
      if ((fail = dup2(b->pipefd[0], 0)) == -1)
	my_printf("Error -> Dup2 failed\n");
    }
  if (detect_cmd("|", a->op))
    {
      if ((fail = dup2(a->pipefd[1], 1)) == -1)
	my_printf("Error -> Dup2 failed\n");
    }
  my_exec(e, a);
}

/*
** my_redir.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Sat Mar  7 11:19:18 2015 Julien Karst
** Last update Sun Mar  8 13:58:44 2015 Julien Karst
*/

#include "sh.h"

void		my_redir_right(t_env *e, t_pipe *a, int t, int mode)
{
  int		i;
  pid_t		pid;
  int		fail;

  if ((fail = pipe(a->pipefd)) == -1)
    my_printf("Error -> Pipe failed\n");
  if ((pid = fork()) == -1)
    my_printf("Error -> Fork failed\n");
  if (pid == 0)
    soon_redir_right(e, a, t, mode);
  else
    father_pipe(e, a, pid);
}

void		soon_redir_right(t_env *e, t_pipe *a, int t, int mode)
{
  t_pipe        *b;
  int           fail;

  b = a + 1;
  if (mode == 0)
    {
      if ((a->fd = open(b->pos1[0], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	my_printf("Error -> Open failed\n");
    }
  else
    {
      if ((a->fd = open(b->pos1[0], O_CREAT | O_WRONLY | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	my_printf("Error -> Open failed\n");
    }
  if ((fail = dup2(a->fd, 1)) == -1)
    my_printf("Error -> Dup2 1 failed %d\n", t);
  my_exec(e, a);
}

void		father_redir_right(t_env *e, t_pipe *a, pid_t pid)
{
  int           status;

  status = 0;
  e->mode = 2;
  waitpid(pid, &status, WSTOPPED);
}

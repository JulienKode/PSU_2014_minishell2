/*
** my_redir_left.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Sun Mar  8 14:03:49 2015 Julien Karst
** Last update Sun Mar  8 14:24:40 2015 Julien Karst
*/

#include "sh.h"

void		my_redir_left_double(t_env *e, t_pipe *a, int t)
{
  char		*meme;
  pid_t		pid;
  t_pipe	*b;
  int		status;

  b = a + 1;
  my_printf(">> ");
  while ((meme = get_next_line(0)) && detect_cmd(b->pos1[0], meme) != 1)
    my_printf(">> ");
  if ((pid = fork()) == -1)
    my_exit2("Error -> fork failed\n");
  if (pid == 0)
    my_exec(e, a);
  else
    {
      waitpid(pid, &status, WSTOPPED);
      e->mode = 2;
    }
}

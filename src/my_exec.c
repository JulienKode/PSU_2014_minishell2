/*
** my_exec.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Tue Feb 10 08:45:29 2015 Julien Karst
** Last update Fri Mar  6 11:26:15 2015 Julien Karst
*/

#include "sh.h"

void	my_exec_dot(t_env *e, t_pipe *a)
{
  if (a->pos1[0][0] == '.' && a->pos1[0][1] == '/' )
    execve(a->pos1[0], a->pos1, e->env);
}

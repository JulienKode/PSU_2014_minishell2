/*
** my_env.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Tue Feb 10 08:45:15 2015 Julien Karst
** Last update Fri Mar  6 14:00:27 2015 Julien Karst
*/

#include "sh.h"

void	my_unsetenv(t_env *e, t_pipe *a)
{
  int	i;

  i = 0;
  while (e->env[i])
    {
      if (detect_cmd(a->pos1[1], e->env[i]))
	e->env[i][0] = 0;
      i++;
    }
}

void	my_print_env(t_env *e)
{
  int	i;

  i = 0;
  while (e->env[i])
    {
      if (e->env[i][0] == 0)
	i++;
      if (e->env[i] == 0)
	return ;
      my_printf("%s\n", e->env[i]);
      i++;
    }
}

int	size_env(t_env *e)
{
  int	i;

  i = 0;
  while (e->env[i])
    i++;
  return (i);
}

void	my_setenv(t_env *e, t_pipe *a)
{
  char	**env;
  int	i;

  i = size_env(e) + 2;
  env = malloc(i * sizeof(char *));
  i = 0;
  while (e->env[i])
    {
      env[i] = my_strdup(e->env[i]);
      i++;
    }
  env[i] = my_strcat_separe(a->pos1[1], a->pos1[2], '=');
  i++;
  env[i] = 0;
  e->env = env;
}

/*
** parse_arg.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Fri Feb  6 11:13:08 2015 Julien Karst
** Last update Sun Mar  8 14:23:43 2015 Julien Karst
*/

#include "sh.h"

int	check_ac(char *str)
{
  if (detect_cmd("|", str))
    return (1);
  if (detect_cmd(">", str))
    return (1);
  if (detect_cmd(">>", str))
    return (1);
  if (detect_cmd("<<", str))
    return (1);
  if (detect_cmd(";", str))
    return (1);
  return (0);
}

void	parse_arg(t_env *e)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  e->a = malloc((nb_ac(e->arg) + 3) * sizeof(t_pipe));
  if (nb_ac(e->arg) == 0)
    {
      e->a->pos1 = e->arg;
      e->a->op = NULL;
    }
  else
    my_parse(e);
}

void	my_parse(t_env *e)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (e->arg[i])
    {
      if (check_ac(e->arg[i]))
	{
	  cpy_arg(e, i, nb);
	  cpy_arg2(e, i, nb);
	  cpy_pos(e, i, nb);
	  nb++;
	}
      i++;
    }
  e->a[nb].pos1 = e->a[nb - 1].pos2;
  e->a[nb].op = NULL;
}

int	nb_ac(char **arg)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (arg[i])
    {
      if (detect_cmd("|", arg[i]))
	nb++;
      if (detect_cmd(">", arg[i]))
	nb++;
      if (detect_cmd(">>", arg[i]))
	nb++;
      if (detect_cmd("<<", arg[i]))
	nb++;
      if (detect_cmd(";", arg[i]))
	nb++;
      i++;
    }
  return (nb);
}

/*
** cpy_arg.c for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minishell2
** 
** Made by Julien Karst
** Login   <karst_j@epitech.net>
** 
** Started on  Sat Feb 21 10:18:39 2015 Julien Karst
** Last update Thu Mar  5 18:37:42 2015 Julien Karst
*/

#include "sh.h"

void	cpy_arg(t_env *e, int i, int nb) // Copie avant
{
  int	m;
  int	c;
  int	n;

  n = 0;
  c = i - 1;
  m = 0;

  while ((e->arg[c] != 0) && (check_ac(e->arg[c]) == 0) && c > 0)
    {
      c--;
      m++;
    }
  e->a[nb].pos1 = malloc((m + 1) * sizeof(char*));
  if (c != 0)
    c++;
  while (c < i)
    {
      e->a[nb].pos1[n] = my_strdup(e->arg[c]);
      n++;
      c++;
    }
  e->a[nb].pos1[n] = 0;
}

void    cpy_arg2(t_env *e, int i, int nb)
{
  int	m;
  int	c;
  int	n;

  n = 0;
  c = i + 1;
  m = 0;
  while ((e->arg[c] != 0) && (check_ac(e->arg[c]) == 0))
    {
      c++;
      m++;
    }
  e->a[nb].pos2 = malloc((m + 1) * sizeof(char*));
  i++;
  while (i < c)
    {
      e->a[nb].pos2[n] = my_strdup(e->arg[i]);
      n++;
      i++;
    }
  e->a[nb].pos2[n] = 0;
}

void	cpy_pos(t_env *e, int i, int nb)
{
  e->a[nb].op = my_strdup(e->arg[i]);
}

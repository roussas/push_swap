/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_args.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 15:31:14 by username         #+#    #+#              */
/*   Updated: 2026/11/14 15:33:42 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag	*flags_init(void)
{
	t_flag	*f;

	f = malloc(sizeof(t_flag));
	if (f == NULL)
		return (NULL);
	f->bench = 0;
	f->strategy = 0;
	return (f);
}

int	checkarg(const char *arg)
{
	if (!ft_strncmp(arg, "--", 2))
		return ('f');
	else
		return ('d');
}

int	parseargs(int count, char **args, t_node **a, t_flag *f)
{
	int	i;

	i = 1;
	while (i < count)
	{
		if (checkarg(args[i]) == 'f')
		{
			if (!parseflags(args[i], f))
				return (0);
		}
		else if (checkarg(args[i]) == 'd')
		{
			if (!parsedata(args[i], a))
				return (0);
		}
		i++;
	}
	return (1);
}

void	adaptive_sort(t_node *a, t_node *b)
{
	float	disorder;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		insertion(&a, &b);
	else if ((0.2 <= disorder) && (disorder < 0.5))
		rangebased_sort(&a, &b);
	else if (disorder >= 0.5)
		radix_sort(&a, &b);
}

void	sort(t_node *a, t_node *b, t_flag *f)
{
	if (f->strategy == 0 || f->strategy == 8)
		adaptive_sort(a, b);
	else if (f->strategy == 1)
		insertion(&a, &b);
	else if (f->strategy == 2)
		rangebased_sort(&a, &b);
	else if (f->strategy == 4)
		radix_sort(&a, &b);
}

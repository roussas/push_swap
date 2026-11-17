/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:45:30 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:45:34 by yaozhou          ###   ########.fr       */
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
	f->countsonly = 0;
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

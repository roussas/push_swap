/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:45:23 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:45:26 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsedata(const char *arg, t_node **a)
{
	t_node	*tmp;

	if (!is_valid_data((char *) arg))
		return (0);
	tmp = str_to_node((char *) arg);
	add_back(a, tmp);
	return (1);
}

int	parseflags(const char *arg, t_flag *f)
{
	int	strat;

	strat = 0;
	if (!ft_strncmp(arg, "--bench", 8))
		f->bench = 1;
	else if (!ft_strncmp(arg, "--simple", 9))
		strat = 1;
	else if (!ft_strncmp(arg, "--medium", 9))
		strat = 2;
	else if (!ft_strncmp(arg, "--complex", 10))
		strat = 4;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		strat = 8;
	else if (!ft_strncmp(arg, "--counts-only", 14))
		f->countsonly = 1;
	else
		return (0);
	strat = f->strategy | strat;
	if (!(strat == 0 || strat == 1 || strat == 2 || strat == 4 || strat == 8))
		return (0);
	f->strategy = strat;
	return (1);
}

int	is_valid_data(char *s)
{
	if (!is_valid_int(s))
		return (0);
	if (!is_int(s))
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > 0)
	{
		n--;
		while (n && *s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
			n--;
		}
		return (*(unsigned char *) s1 - *(unsigned char *) s2);
	}
	else
		return (0);
}

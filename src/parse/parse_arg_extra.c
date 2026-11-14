/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_arg_extra.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 15:32:21 by username         #+#    #+#              */
/*   Updated: 2026/11/14 15:32:54 by username        ###   ########.fr        */
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
	strat = f->strategy | strat;
	if (!(strat == 0 || strat == 1 || strat == 2 || strat == 4 || strat == 8))
		return (0);
	f->strategy = strat;
	return (1);
}

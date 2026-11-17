/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:22:57 by username         #+#    #+#              */
/*   Updated: 2026/11/17 11:24:32 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_node **a)
{
	t_node	*tmp;
	int		max;
	int		bits;
	int		num;

	max = 0;
	tmp = *a;
	while (tmp)
	{
		num = tmp->rank;
		bits = 0;
		while (num > 0)
		{
			bits++;
			num >>= 1;
		}
		if (bits > max)
			max = bits;
		tmp = tmp->next;
	}
	return (max);
}

void	radix_sort(t_node **a, t_node **b, t_bench **bench)
{
	int	bits;
	int	i;
	int	size;

	if (compute_disorder(*a) == 0.0)
		return ;
	rank_list(a);
	i = 0;
	bits = max_bits(a);
	while (i < bits)
	{
		size = stack_length(*a);
		while (size-- > 0)
		{
			if (((*a)->rank & (1 << i)) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}

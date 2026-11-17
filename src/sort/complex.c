/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:45:51 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:45:53 by yaozhou          ###   ########.fr       */
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

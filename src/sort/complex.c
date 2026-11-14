/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:22:57 by username         #+#    #+#              */
/*   Updated: 2026/11/14 13:20:37 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_set(t_node *node, t_node **a)
{
	int		rank;
	t_node	*tmp;

	rank = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (node->value > tmp->value)
			rank++;
		tmp = tmp->next;
	}
	return (rank);
}

void	rank_list(t_node **a)
{
	t_node	*tmp;

	if (a == NULL || *a == NULL)
		return ;
	tmp = *a;
	while (tmp != NULL)
	{
		tmp->rank = rank_set(tmp, a);
		tmp = tmp->next;
	}
}

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

void	radix_sort(t_node **a, t_node **b)
{
	int	bits;
	int	i;
	int	size;

	rank_list(a);
	i = 0;
	bits = max_bits(a);
	while (i < bits)
	{
		size = stack_length(*a);
		while (size-- > 0)
		{
			if (((*a)->rank & (1 << i)) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

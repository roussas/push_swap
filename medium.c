/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:23:20 by username         #+#    #+#              */
/*   Updated: 2026/11/14 13:09:29 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to(t_node **b, int pos, int reverse)
{
	int	j;

	j = 0;
	while (j < pos)
	{
		if (reverse)
			rrb(b);
		else
			rb(b);
		j++;
	}
}

void	sort_chunk(t_node **a, t_node **b, int n, int len)
{
	int	maxpos;
	int	i;

	i = 0;
	while (i < n)
	{
		maxpos = findmax_n(*b, n - i);
		if (maxpos < 0)
			return ;
		rotate_to(b, maxpos, 0);
		pa(a, b);
		if (n < len)
			rotate_to(b, maxpos, 1);
		i++;
	}
}

void	rangebased_insertion(t_node **a, t_node **b, int n)
{
	int	len;
	int	j;

	if (!a || !b || !(*b) || n <= 0)
		return ;
	len = stack_length(*b);
	sort_chunk(a, b, n, len);
	j = 0;
	while (j < n)
	{
		pb(a, b);
		j++;
	}
}

int	pushrange(t_node **a, t_node **b, int rtop)
{
	int	len;
	int	count_pushed;

	len = stack_length(*a);
	count_pushed = 0;
	while (len > 0)
	{
		if ((*a)->rank <= rtop)
		{
			pb(a, b);
			count_pushed++;
		}
		else
			ra(a);
		len--;
	}
	return (count_pushed);
}

void	rangebased_sort(t_node **a, t_node **b)
{
	int	length;
	int	countrange;
	int	pushcount;
	int	dist;
	int	i;

	if (!a || !(*a))
		return ;
	rank_list(a);
	length = stack_length(*a);
	dist = sqrt_approx(length);
	if (dist <= 0)
		return ;
	countrange = (length + dist - 1) / dist;
	i = 0;
	while (i < countrange)
	{
		pushcount = pushrange(a, b, dist * (i + 1) - 1);
		rangebased_insertion(a, b, pushcount);
		i++;
	}
	while (*b)
		pa(a, b);
}

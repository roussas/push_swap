/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:46:17 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:50:15 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_node **a, int count, int reverse, t_bench **bench)
{
	while (count-- > 0)
	{
		if (reverse)
			rra(a, bench);
		else
			ra(a, bench);
	}
}

static void	bring_to_top(t_node **a, t_chunk *t, t_bench **bench)
{
	t_node	*tmp;
	int		i;
	int		first;
	int		last;

	tmp = *a;
	i = 0;
	first = -1;
	last = -1;
	while (tmp)
	{
		if (tmp->rank >= t->lo && tmp->rank <= t->hi)
		{
			if (first < 0)
				first = i;
			last = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (first <= i - last)
		rotate_a(a, first, 0, bench);
	else
		rotate_a(a, i - last, 1, bench);
}

static void	push_chunk(t_node **a, t_node **b, t_chunk *t, t_bench **bench)
{
	int	mid;
	int	count;

	mid = (t->lo + t->hi) / 2;
	count = t->hi - t->lo + 1;
	while (count-- > 0)
	{
		bring_to_top(a, t, bench);
		pb(a, b, bench);
		if ((*b)->rank < mid)
			rb(b, bench);
	}
}

static void	pull_back(t_node **a, t_node **b, t_bench **bench)
{
	int	pos;
	int	len;

	while (*b)
	{
		len = stack_length(*b);
		pos = findmax_n(*b, len);
		if (pos > len / 2)
		{
			pos = len - pos;
			while (pos-- > 0)
				rrb(b, bench);
		}
		else
		{
			while (pos-- > 0)
				rb(b, bench);
		}
		pa(a, b, bench);
	}
}

void	rangebased_sort(t_node **a, t_node **b, t_bench **bench)
{
	int		n;
	int		k;
	int		size;
	t_chunk	t;

	if (!a || !(*a) || compute_disorder(*a) == 0.0)
		return ;
	rank_list(a);
	n = stack_length(*a);
	k = sqrt_approx(n) / 2;
	if (k < 1)
		k = 1;
	size = (n + k - 1) / k;
	t.lo = 0;
	while (t.lo < n)
	{
		t.hi = t.lo + size - 1;
		if (t.hi >= n)
			t.hi = n - 1;
		push_chunk(a, b, &t, bench);
		t.lo += size;
	}
	pull_back(a, b, bench);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:51:12 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:51:16 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, t_bench **bench)
{
	if (a && *a && (*a)->next)
	{
		rotate(a);
		write(1, "ra\n", 3);
		(*bench)->cntra++;
	}
}

void	rb(t_node **b, t_bench **bench)
{
	if (b && *b && (*b)->next)
	{
		rotate(b);
		write(1, "rb\n", 3);
		(*bench)->cntrb++;
	}
}

void	rr(t_node **a, t_node **b, t_bench **bench)
{
	if ((a && *a && (*a)->next) || (b && *b && (*b)->next))
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
		(*bench)->cntrr++;
	}
}

void	rra(t_node **a, t_bench **bench)
{
	if (a && *a && (*a)->next)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		(*bench)->cntrra++;
	}
}

void	rrb(t_node **b, t_bench **bench)
{
	if (b && *b && (*b)->next)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
		(*bench)->cntrrb++;
	}
}

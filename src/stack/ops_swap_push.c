/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:51:21 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:51:31 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, t_bench **bench)
{
	if (a && *a && (*a)->next)
	{
		swap(a);
		write(1, "sa\n", 3);
		(*bench)->cntsa++;
	}
}

void	sb(t_node **b, t_bench **bench)
{
	if (b && *b && (*b)->next)
	{
		swap(b);
		write(1, "sb\n", 3);
		(*bench)->cntsb++;
	}
}

void	ss(t_node **a, t_node **b, t_bench **bench)
{
	if ((a && *a && (*a)->next) || (b && *b && (*b)->next))
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
		(*bench)->cntss++;
	}
}

void	pa(t_node **a, t_node **b, t_bench **bench)
{
	if (b && *b)
	{
		push_to(b, a);
		write(1, "pa\n", 3);
		(*bench)->cntpa++;
	}
}

void	pb(t_node **a, t_node **b, t_bench **bench)
{
	if (a && *a)
	{
		push_to(a, b);
		write(1, "pb\n", 3);
		(*bench)->cntpb++;
	}
}

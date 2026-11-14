/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ops_swap_push.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/27 13:33:52 by username         #+#    #+#              */
/*   Updated: 2026/11/14 12:23:32 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	if (a && *a && (*a)->next)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_node **b)
{
	if (b && *b && (*b)->next)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_node **a, t_node **b)
{
	if ((a && *a && (*a)->next) || (b && *b && (*b)->next))
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}

void	pa(t_node **a, t_node **b)
{
	if (b && *b)
	{
		push_to(b, a);
		write(1, "pa\n", 3);
	}
}

void	pb(t_node **a, t_node **b)
{
	if (a && *a)
	{
		push_to(a, b);
		write(1, "pb\n", 3);
	}
}

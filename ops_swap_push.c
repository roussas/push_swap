/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:33:52 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/27 13:33:54 by kpagkalo         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:33:26 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/27 13:45:19 by kpagkalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	if (a && *a && (*a)->next)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_node **b)
{
	if (b && *b && (*b)->next)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_node **a, t_node **b)
{
	if ((a && *a && (*a)->next) || (b && *b && (*b)->next))
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}

void	rra(t_node **a)
{
	if (a && *a && (*a)->next)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_node **b)
{
	if (b && *b && (*b)->next)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

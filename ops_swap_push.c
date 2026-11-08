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
//THIS CALLS FUNCTION FROM OPS_LOGIC AND JUST WRITE WHAT IT DOES , AS THE SUBJECT SAID
//I WROTE IT LIKE THIS TO AVOID USING TWO OF THE SAME FUNCTION
// FOR EXAMPLE SA AND SB ARE DOING THE SAME THING SO I JUST CALL ONE FUNCTION AND PRINT WHAT I DID
//RRR IS IN THE OPS_LOGIC BECAUSE I HAD NO SPACE HERE  -NORMINETE-
#include "push_swap.h"

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
//IF NOT MOVED NOT PRINTED PA PB : I NEED TO FIX THIS !

void	pa(t_node **a, t_node **b)
{
	push_to(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push_to(a, b);
	write(1, "pb\n", 3);
}

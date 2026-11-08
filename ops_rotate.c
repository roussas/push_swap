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
//THIS CALLS FUNCTION FROM OPS_LOGIC AND JUST WRITE WHAT IT DOES , AS THE SUBJECT SAID
//I WROTE IT LIKE THIS TO AVOID USING TWO OF THE SAME FUNCTION
// FOR EXAMPLE SA AND SB ARE DOING THE SAME THING SO I JUST CALL ONE FUNCTION AND PRINT WHAT I DID
//RRR IS IN THE OPS_LOGIC BECAUSE I HAD NO SPACE HERE  -NORMINETE-
void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

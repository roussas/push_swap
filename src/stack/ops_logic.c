/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:33:18 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/27 13:43:04 by kpagkalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
THIS IS FOR HANDLING LINKED LISTS
*/
#include "push_swap.h"
//Take a node  from the top and put it to the the other list
void	push_to(t_node **from, t_node **to)
{
	t_node	*new;

	new = pop_top(from);
	push_top(to, new);
}
//wap the first two elements at the top of stack a.
//Do nothing if there is only one or no elements

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (stack_length(*stack) <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}
// The first element becomes the last one.

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (stack_length(*stack) <= 1)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	*stack = tmp2->next;
	tmp2->next = NULL;
}


//The last element becomes the first one.

void	reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (stack_length(*stack) <= 1)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	while (tmp2->next->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp->next = *stack;
	*stack = tmp;
	tmp2 -> next = NULL;
}
//Reverse rotate both a and b , and then write
void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

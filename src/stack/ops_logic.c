/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:51:08 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:51:09 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_node **from, t_node **to)
{
	t_node	*new;

	if (from == NULL || to == NULL || *from == NULL)
		return ;
	new = pop_top(from);
	push_top(to, new);
}

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	rotate(t_node **stack)
{
	t_node	*last;
	t_node	*first;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = first->next;
	first->next = NULL;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	while (tmp2->next->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp->next = *stack;
	*stack = tmp;
	tmp2->next = NULL;
}

void	rrr(t_node **a, t_node **b, t_bench **bench)
{
	int	i;

	i = 0;
	if (a && *a && (*a)->next)
		i = 1;
	if (b && *b && (*b)->next)
		i = 1;
	if (!i)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	(*bench)->cntrrr++;
}

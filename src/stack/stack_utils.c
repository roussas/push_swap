/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/27 13:34:35 by username         #+#    #+#              */
/*   Updated: 2026/11/14 12:23:52 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_t_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->rank = 0;
	new->next = NULL;
	return (new);
}

void	push_top(t_node **stack, t_node *new)
{
	if (new == NULL || stack == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

t_node	*pop_top(t_node **stack)
{
	t_node	*pop;

	if (*stack == NULL || stack == NULL)
		return (NULL);
	pop = *stack;
	*stack = (*stack)->next;
	pop->next = NULL;
	return (pop);
}

int	stack_length(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

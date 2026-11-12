/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:34:35 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/27 13:50:57 by kpagkalo         ###   ########.fr       */
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
	new -> rank = 0;
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
	t_node	*tmp;
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

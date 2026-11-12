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
//THIS IS STUFF FOR HANDLING THE LINKED LIST AS WELL 
//MAYBE THE FUNCTIONS FROM LIBFT ARE BETTER , BUT YEAH... WE WILL SEE

t_node	*new_t_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}
//TAKE A NODE AND PUT IT FIRST
void	push_top(t_node **stack, t_node *new)
{
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}
//REMOVE THE TOP OF THE LIST BUT DONT LOSE IT 
t_node	*pop_top(t_node **stack)
{
	t_node	*tmp;
	t_node	*pop;

	if (*stack == NULL)
		return (NULL);
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	pop = *stack;
	*stack = tmp;
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

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
// int is_sorted(t_node **a)
// {
// 	t_node *stack;

// 	stack = *a;
// 	while (stack->next != NULL)
// 	{
// 		if (stack->value > stack->next->value)
// 			return(0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

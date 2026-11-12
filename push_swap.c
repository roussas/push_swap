/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:34:03 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/27 13:46:02 by kpagkalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	append_arg(t_node **a, char *arg)
{
	t_node	*new;

	if (!is_valid_int(arg) || !is_int(arg))
		return (0);
	new = str_to_node(arg);
	if (new == NULL)
		return (0);
	add_back(a, new);
	return (1);
}

t_node	*list(char **s, int i)
{
	t_node	*a;

	a = NULL;
	while (s[i])
	{
		if (!append_arg(&a, s[i]))
		{
			free_stack(&a);
			return (NULL);
		}
		i++;
	}
	return (a);
}

static int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	print_error(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	return (1);
}
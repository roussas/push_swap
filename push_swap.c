/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:22:27 by username         #+#    #+#              */
/*   Updated: 2026/11/14 12:54:12 by username        ###   ########.fr        */
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

static t_node	*list(char **s, int i)
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

static int	print_error(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	return (1);
}
#include <stdio.h>

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%i\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	if (ft_strcmp(argv[1]) > 0)
		i = 2;
	a = list(argv, i);
	if (a == NULL || !no_doubles(a))
		return (print_error(&a));
	if (i == 2)
		a = str_sel(argv[1], &a, &b);
	else
		adaptive(&a, &b);
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

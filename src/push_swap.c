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

static int	print_error(t_node **a,	t_flag	*f)
{
	free_stack(a);
	free(f);
	write(2, "Error\n", 6);
	return (1);
}
// #include <stdio.h>

// void	print_stack(t_node *stack)
// {
// 	while (stack)
// 	{
// 		printf("%i\n", stack->value);
// 		stack = stack->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_flag	*f;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	f = flags_init();
	if (f == NULL)
		return (1);
	if (!parseargs(argc, argv, &a, f) || !no_doubles(a))
	{
		print_error(&a,f);
		return (0);
	}
	sort(&a, &b, f);
	free_stack(&a);
	free_stack(&b);
	free(f);
	return (0);
}

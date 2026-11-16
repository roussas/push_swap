/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/27 13:34:03 by username         #+#    #+#              */
/*   Updated: 2026/11/16 14:05:42 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_error(t_node **a, t_flag *f)
{
	free_stack(a);
	free(f);
	write(2, "Error\n", 6);
	return (1);
}

static void	free_all(t_node **a, t_node **b, t_flag *f, t_bench *bench)
{
	free_stack(a);
	free_stack(b);
	free(bench);
	free(f);
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
	t_bench	*bench;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	f = flags_init();
	bench = NULL;
	if (f == NULL)
		return (1);
	if (!parseargs(argc, argv, &a, f) || !no_doubles(a))
	{
		print_error(&a, f);
		return (0);
	}
	bench = bench_init(a);
	sort(&a, &b, &f, &bench);
	if (f->bench)
		write_bench(bench, f);
	free_all(&a, &b, f, bench);
	return (0);
}

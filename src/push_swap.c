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


static int	print_error(t_node **a)
{
	free_stack(a);
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

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;
    t_flag *f;

    if (argc < 2)
        return (0);
    a = NULL;
    b = NULL;
    f = flags_init();
    if (!parseargs(argc, argv, &a, f))
    {
		print_error(&a);
        return (0);
    }
    if (!no_doubles(a))
    {
		print_error(&a);
		return (0);
    }
    sort(a, b, f);
	free_stack(&a);
	free_stack(&b);
    return (0);
}

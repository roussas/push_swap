/*
THIS IS JUST FOR TESTING
*/
#include "push_swap.h"
//DONT FORGET TO CHECK PRINTF BEFORE SUBMIT

void	print_stack(t_node * stack)
{
	while (stack)
	{
		printf("%i\n", stack->value);
		stack = stack->next;
	}
}
//DONT FORGET TO CHECK PRINTF BEFOR SUMBIT ^
// #include "push_swap.h"
// #include <stdio.h>

// static t_node	*build(int *v, int n)
// {
// 	t_node * s = NULL;
// 	while (n-- > 0)
// 		push_top(&s, new_t_node(v[n]));
// 	return (s);
// }

// static void	line(char *name, t_node * s)
// {
// 	printf("%s:", name);
// 	while (s)
// 	{
// 		printf(" %d", s->value);
// 		s = s->next;
// 	}
// 	printf("\n");
// }

// static void	show(t_node * a, t_node * b)
// {
// 	line("a", a);
// 	line("b", b);
// 	printf("\n");
// 	fflush(stdout);
// }

// int	main(void)
// {
// 	int	v[] =
// 	{
// 		3, 1, 4, 2
// 	};
// 	t_node * a = build(v, 4);
// 	t_node * b = NULL;
// 	show(a, b);
// 	sa(&a);
// 	show(a, b);
// 	ra(&a);
// 	show(a, b);
// 	rra(&a);
// 	show(a, b);
// 	pb(&a, &b);
// 	show(a, b);
// 	pb(&a, &b);
// 	show(a, b);
// 	sb(&b);
// 	show(a, b);
// 	rb(&b);
// 	show(a, b);
// 	rrb(&b);
// 	show(a, b);
// 	ss(&a, &b);
// 	show(a, b);
// 	rr(&a, &b);
// 	show(a, b);
// 	rrr(&a, &b);
// 	show(a, b);
// 	pa(&a, &b);
// 	show(a, b);
// 	pa(&a, &b);
// 	show(a, b);
// 	pa(&a, &b);
// 	show(a, b);
// 	pa(&a, &b);
// 	show(a, b);
// 	free_stack(&a);
// 	free_stack(&b);
// 	return (0);
// }

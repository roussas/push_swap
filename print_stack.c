/*
THIS IS JUST FOR TESTING
*/
#include "push_swap.h"
//DONT FORGET TO CHECK PRINTF BEFORE SUBMIT

void	print_stack(t_node * stack)
{
	while (stack)
	{
		printf("%li\n", stack->value);
		stack = stack->next;
	}
}
#include "push_swap.h"

static int findmin(t_node *stack)
{
    int help;
    t_node *temp;
    int current_index;
    int min_index;

    help = stack->value;
    temp = stack->next;
    current_index = 1;
    min_index = 0;
    while(temp)
    {
        if (temp->value < help)
        {
            help = temp->value;
            min_index = current_index;
        }
        temp = temp->next;
        current_index++;
    }
    return (min_index);
}

static void rotatetotop(t_node **stack, int count)
{
    int len;

    len = stack_length(*stack);
    if (len < 2)
        return ;
    if (count <= len / 2)
    {
        while (count-- > 0)
            ra(stack);
    }
    else
    {
        while (count++ < len)
            rra(stack);
    }
}

void    insertion(t_node **a, t_node **b)
{
    int count;

	if (a == NULL || *a == NULL)
		return ;
    while ((*a)->next)
    {
        count = findmin(*a);
        rotatetotop(a, count);
        pb(a, b);
    }
    while (*b)
        pa(a, b);
}
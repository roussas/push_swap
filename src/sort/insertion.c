#include "push_swap.h"
#include <stdio.h>

// Find minimum in a
// Rotate minimum to top of a
// Push top of a to b
// Repeat as long as there are values in a
// Push sequentially from b to a

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

static void rotatetotop(t_node **stack, int count, t_bench **bench)
{
    int len;

    len = stack_length(*stack);
    if (len < 2)
        return ;
    if (count <= len / 2)
    {
        while (count > 0)
        {
            ra(stack, bench);
            count--;
        }
    }
    else
    {
        while (count < len)
        {
            rra(stack, bench);
            count++;
        }
    }
}

void    insertion(t_node **a, t_node **b, t_bench **bench)
{
    int count;

    if(!(*a) || !a)
        return ;
    while ((*a)->next)
    {
        count = findmin(*a);
        rotatetotop(a, count, bench);
        pb(a, b, bench);
    }
    while (*b)
        pa(a, b, bench);
}
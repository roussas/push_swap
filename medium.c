#include "push_swap.h"

static int findmax_n(t_node *stack, int n)
{
    int max_index;
    int current_index;
    t_node *max_node;

    if (!stack)
        return (0);
    max_index = 0;
    current_index = 0;
    max_node = stack;
    while (current_index < n)
    {
        if (stack->value > max_node->value)
        {
            max_node = stack;
            max_index = current_index;
        }
        stack = stack->next;
        current_index++;
    }
    return (max_index);
}

void    rangebased_insertion(t_node **tobesorted, t_node **otherone, int n)
{
    int len;
    int minpos;
    int maxpos;
    int i;
    int j;

    len = stack_length(*tobesorted);
    // printf("count_push: %d\n", n);
    if(!(*tobesorted) || !tobesorted)
        return ;
    i = 0;
    while (i < n)
    {
        // minpos = findmin_n(*tobesorted, n - i);
        maxpos = findmax_n(*tobesorted, n - i);
        j = 0;
        while (j < maxpos)
        {
            rb(tobesorted);
            j++;
        }
        pb(tobesorted, otherone);
        if (n < len)
        {
            j = 0;
            while (j < maxpos)
            {
                rrb(tobesorted);
                j++;
            }
        }
        i++;
        // stack contains sorted bits from previous ranges, rotate back, find new minimum, rotate, push, rotate back, repeat for size n
    }
    while (n > 0)
    {
        // printf("step: %d\n", n);
        pa(tobesorted, otherone);
        n--;
    }
}

static int	sqrt_approx(int nb)
{
	int	i;

	if (nb < 0)
		return (-1);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	while (i <= 46340 && i * i <= nb)
		i++;
	return (i - 1);
}

static int pushrange(t_node **a, t_node **b, int rtop)
{
    int len;
    int count_pushed;

    len = stack_length(*a);
    count_pushed = 0;
    while (len > 0)
    {
        if ((*a)->rank <= rtop)
        {
            pb(a, b);
            count_pushed++;
        }
        else
            ra(a);
        len--;
    }
    return (count_pushed);
}

void rangebased_sort(t_node **a, t_node **b)
{
    int length;
    int countrange;
    int pushcount;
    int dist;
    int i;

    rank_list(a);
    length = stack_length(*a);
    countrange = sqrt_approx(length);
    dist = countrange;
    if (length % countrange)
        countrange++;
    i = 0;
    while (i < countrange)
    {
        pushcount = pushrange(a, b, dist * (i + 1));
        rangebased_insertion(b, a, pushcount);
        i++;
    }
    while (*b)
        pa(a, b);
}
#include "push_swap.h"

static int findmax_n(t_node *stack, int n)
{
    int max_index;
    int current_index;
    t_node *max_node;
    t_node *current;

    if (!stack || n <= 0)
        return (-1);
    max_index = 0;
    current_index = 0;
    max_node = stack;
    current = stack;
    while (current && current_index < n)
    {
        if (current->value > max_node->value)
        {
            max_node = current;
            max_index = current_index;
        }
        current = current->next;
        current_index++;
    }
    return (max_index);
}

void    rangebased_insertion(t_node **a, t_node **b, int n)
{
    int len;
    int maxpos;
    int i;
    int j;

    if (!a || !b || !(*b) || n <= 0)
        return ;
    len = stack_length(*b);
    i = 0;
    while (i < n)
    {
        maxpos = findmax_n(*b, n - i);
        if (maxpos < 0)
            return ;
        j = 0;
        while (j < maxpos)
        {
            rb(b);
            j++;
        }
        pa(a, b);
        if (n < len)
        {
            j = 0;
            while (j < maxpos)
            {
                rrb(b);
                j++;
            }
        }
        i++;
    }
    j = 0;
    while (j < n)
    {
        pb(a, b);
        j++;
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

    if (!a || !(*a))
        return ;
    rank_list(a);
    length = stack_length(*a);
    dist = sqrt_approx(length);
    if (dist <= 0)
        return ;
    countrange = (length + dist - 1) / dist;
    i = 0;
    while (i < countrange)
    {
        pushcount = pushrange(a, b, dist * (i + 1) - 1);
        rangebased_insertion(a, b, pushcount);
        i++;
    }
    while (*b)
        pa(a, b);
}
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

// Changed the parameters to the stack names to be more easily read
//pa/pb
// printed the opposite of what really happened.
void    rangebased_insertion(t_node **a, t_node **b, int n)
{
    int len;
    int maxpos;
    int i;
    int j;
    //removed the unused variable minpos
    // Check before using the pointers 
    if (!a || !b || !(*b))
        return ;
    len = stack_length(*b);
    i = 0;
    while (i < n)
    {
        maxpos = findmax_n(*b, n - i);
        j = 0;
        while (j < maxpos)
        {
            rb(b);
            j++;
        }
        // this moves the top of b onto a, so the right name is pa
        // (before: pb(tobesorted, otherone) moved b->a but printed pb
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
    while (n > 0)
    {
        //this moves the top of a back onto b, so the right name is pb
        // before: pa(tobesorted, otherone) moved a->b but printed pa
        pb(a, b);
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

    //empty stack made sqrt_approx return 0 and "length % countrange"
    // divided by zero fails
    if (!a || !(*a))
        return ;
    rank_list(a);
    length = stack_length(*a);
    dist = countrange;
    // Before: "if (length % countrange) countrange++" added one extra pass,
    //  but length can be up to dist*dist + 2*dist, which needs
    // up to two extra passes . The ranks above
    // dist * countrange were never pushed, so they stayed unsorted in a.
    // length >= 1 here, so dist >= 1 and there is no division by zero.
    countrange = (length + dist - 1) / dist;
    i = 0;
    while (i < countrange)
    {
        pushcount = pushrange(a, b, dist * (i + 1));
        // pass the stacks in their real order (a, b)
        // before: rangebased_insertion(b, a, ...)
        rangebased_insertion(a, b, pushcount);
        i++;
    }
    while (*b)
        pa(a, b);
}
#include "push_swap.h"

static void	sort_three(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top > bot)
		ra(a);
	else if (mid > top && mid > bot)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static int	find_insert_pos(t_node *b, int value)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (b)
	{
		if (value > b->value)
			break ;
		b = b->next;
		i++;
	}
	return (i);
}

void	insertion(t_node **a, t_node **b)
{
	int	len;
	int	pos;
	int	b_len;

	len = stack_length(*a);
	if (len <= 1)
		return ;
	if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (len == 3)
	{
		sort_three(a);
		return ;
	}
	pb(a, b);
	pb(a, b);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	while (*a)
	{
		pb(a, b);
		pos = find_insert_pos(*b, (*b)->value);
		b_len = stack_length(*b);
		if (pos <= b_len / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			pos = b_len - pos;
			while (pos-- > 0)
				rrb(b);
		}
	}
	while (*b)
		pa(a, b);
}
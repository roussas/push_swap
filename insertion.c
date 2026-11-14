/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   insertion.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:23:15 by username         #+#    #+#              */
/*   Updated: 2026/11/14 13:17:19 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_rule(t_node **a, int len)
{
	if (len <= 1)
		return (0);
	if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return (0);
	}
	if (len == 3)
	{
		sort_three(a);
		return (0);
	}
	return (1);
}

static int	get_max_pos(t_node *b)
{
	int	max;
	int	max_pos;
	int	i;

	max = b->value;
	max_pos = 0;
	i = 0;
	while (b)
	{
		if (b->value > max)
		{
			max = b->value;
			max_pos = i;
		}
		b = b->next;
		i++;
	}
	return (max_pos);
}

static int	find_insert_pos(t_node *b, int val)
{
	t_node	*curr;
	t_node	*next;
	int		i;

	curr = b;
	i = 0;
	while (curr)
	{
		next = curr->next;
		if (!next)
			next = b;
		if (curr->value > val && val > next->value)
			return (i + 1);
		curr = curr->next;
		i++;
	}
	return (get_max_pos(b));
}

static void	stack_turn(int pos, int b_len, t_node **b)
{
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

void	insertion(t_node **a, t_node **b)
{
	int	pos;

	if (!three_rule(a, stack_length(*a)))
		return ;
	pb(a, b);
	pb(a, b);
	while (*a)
	{
		pos = find_insert_pos(*b, (*a)->value);
		stack_turn(pos, stack_length(*b), b);
		pb(a, b);
	}
	stack_turn(get_max_pos(*b), stack_length(*b), b);
	while (*b)
		pa(a, b);
}

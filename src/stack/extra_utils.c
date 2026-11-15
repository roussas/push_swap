/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   extra_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:26:23 by username         #+#    #+#              */
/*   Updated: 2026/11/14 13:16:56 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*str_to_node(char *s)
{
	char	**l;
	int		i;
	t_node	*a;
	t_node	*n;

	a = NULL;
	l = ft_split(s, ' ');
	if (l == NULL)
		return (NULL);
	i = count_numbers(l) - 1;
	while (i >= 0)
	{
		n = new_t_node(ft_atoi(l[i]));
		if (n == NULL)
		{
			free_stack(&a);
			free_list(l);
			return (NULL);
		}
		push_top(&a, n);
		i--;
	}
	free_list(l);
	return (a);
}

int	is_int(char *s)
{
	char	**l;
	long	n;
	int		i;

	l = ft_split(s, ' ');
	if (l == NULL)
		return (0);
	i = 0;
	while (l[i])
	{
		n = ft_atol(l[i]);
		if (n < -2147483648 || n > 2147483647)
		{
			free_list(l);
			return (0);
		}
		i++;
	}
	free_list(l);
	return (1);
}

int	sqrt_approx(int nb)
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

int    findmax_n(t_node *stack, int n)
{
    int     max_index;
    int     current_index;
    t_node  *max_node;
    t_node  *current;

    if (!stack || n <= 0)
        return (-1);
    max_index = 0;
    current_index = 0;
    max_node = stack;
    current = stack;
    while (current && current_index < n)
    {
        if (current->rank > max_node->rank)
        {
            max_node = current;
            max_index = current_index;
        }
        current = current->next;
        current_index++;
    }
    return (max_index);
}

void	sort_three(t_node **a)
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

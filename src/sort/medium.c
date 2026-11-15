/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:23:20 by username         #+#    #+#              */
/*   Updated: 2026/11/14 15:56:27 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_to(t_node **b, int pos, t_bench **bench)
{
    int len;
    int j;

    len = stack_length(*b);
    j = 0;
    if (pos <= len / 2)
    {
        while (j < pos)
        {
            rb(b, bench);
            j++;
        }
    }
    else
    {
        while (j < len - pos)
        {
            rrb(b, bench);
            j++;
        }
    }
}

void    sort_chunk(t_node **a, t_node **b, int n, t_bench **bench)
{
    int maxpos;
    int i;

    i = 0;
    while (i < n)
    {
        maxpos = findmax_n(*b, n - i);
        if (maxpos < 0)
            return ;
        rotate_to(b, maxpos, bench);
        pa(a, b, bench);
        i++;
    }
}

void    rangebased_insertion(t_node **a, t_node **b, int n, t_bench **bench)
{
    if (!a || !b || !(*b) || n <= 0)
        return ;
    sort_chunk(a, b, n, bench);
}

int	pushrange(t_node **a, t_node **b, int rtop, t_bench **bench)
{
	int	len;
	int	count_pushed;

	len = stack_length(*a);
	count_pushed = 0;
	while (len > 0)
	{
		if ((*a)->rank <= rtop)
		{
			pb(a, b, bench);
			count_pushed++;
		}
		else
			ra(a, bench);
		len--;
	}
	return (count_pushed);
}

void    rangebased_sort(t_node **a, t_node **b, t_bench **bench)
{
    int length;
    int countrange;
    int pushcount;
    int dist;
    int i;

    if (!a || !*a || !b || *b)
        return ;
    rank_list(a);
    length = stack_length(*a);
    countrange = sqrt_approx(length);
    dist = countrange;
    if (length % countrange)
        countrange++;
    i = 0;
    while (i < countrange)
    {
        pushcount = pushrange(a, b, dist * (i + 1), bench);
        rangebased_insertion(b, a, pushcount, bench);
        i++;
    }
    while (*b)
        pa(a, b, bench);
}

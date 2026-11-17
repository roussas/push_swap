/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:45:36 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:45:39 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_set(t_node *node, t_node **a)
{
	int		rank;
	t_node	*tmp;

	rank = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (node->value > tmp->value)
			rank++;
		tmp = tmp->next;
	}
	return (rank);
}

void	rank_list(t_node **a)
{
	t_node	*tmp;

	if (a == NULL || *a == NULL)
		return ;
	tmp = *a;
	while (tmp != NULL)
	{
		tmp->rank = rank_set(tmp, a);
		tmp = tmp->next;
	}
}

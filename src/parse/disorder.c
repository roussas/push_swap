/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:44:56 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:44:58 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *stack)
{
	double	mistakes;
	double	totalpairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	totalpairs = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			totalpairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (totalpairs == 0)
		return (totalpairs);
	return (mistakes / totalpairs);
}

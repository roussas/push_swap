/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adaptive.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:22:43 by username         #+#    #+#              */
/*   Updated: 2026/11/14 12:22:43 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_node **a, t_node **b)
{
	double	dis;

	dis = compute_disorder(*a);
	if (dis < 0.2)
		insertion(a, b);
	else if (dis >= 0.2 && dis < 0.5)
		rangebased_sort(a, b);
	else
		radix_sort(a, b);
}

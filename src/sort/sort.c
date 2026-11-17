/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:50:50 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:50:52 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **a, t_node **b, t_bench **bench)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		insertion(a, b, bench);
	else if ((0.2 <= disorder) && (disorder < 0.5))
		rangebased_sort(a, b, bench);
	else if (disorder >= 0.5)
		radix_sort(a, b, bench);
}

void	sort(t_node **a, t_node **b, t_flag **f, t_bench **bench)
{
	if ((*f)->strategy == 0 || (*f)->strategy == 8)
		adaptive_sort(a, b, bench);
	else if ((*f)->strategy == 1)
		insertion(a, b, bench);
	else if ((*f)->strategy == 2)
		rangebased_sort(a, b, bench);
	else if ((*f)->strategy == 4)
		radix_sort(a, b, bench);
}

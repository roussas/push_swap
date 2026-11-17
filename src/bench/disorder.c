/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:43:33 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:43:38 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ilovemalloc(char *str)
{
	str[0] = '1';
	str[1] = '0';
	str[2] = '0';
	str[3] = '.';
	str[4] = '0';
	str[5] = '0';
	str[6] = '\0';
	return (str);
}

char	*strdisorder(double disorder)
{
	double	d;
	char	*str;
	int		i;

	str = malloc(7 * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (disorder == 1.0)
		return (ilovemalloc(str));
	d = disorder * 10000;
	i = 4;
	while (i-- >= 0)
	{
		if (i != 2)
		{
			str[i] = ((int) d % 10) + '0';
			d = d / 10;
		}
		else
			str[i] = '.';
	}
	str[5] = '\0';
	return (str);
}

double	compute_disorder(t_node *stack)
{
	int		mistakes;
	int		totalpairs;
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
		return (0);
	return ((double) mistakes / (double) totalpairs);
}

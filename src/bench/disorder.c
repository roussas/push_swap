/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   disorder.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 15:29:23 by username         #+#    #+#              */
/*   Updated: 2026/11/16 15:29:23 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strdisorder(double disorder)
{
	int		d;
	char	*str;
	int		i;

	str = malloc(6 * sizeof(char));
	if (str == NULL)
		return (NULL);
	d = (int)(disorder * 10);
	i = 0;
	while (i < 5)
	{
		if (i != 2)
		{
			str[i] = (d % 10) + '0';
			d = d / 10;
		}
		else
			str[i] = '.';
		i++;
	}
	str[i] = '\0';
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

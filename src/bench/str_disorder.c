/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   disorder.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 13:41:36 by username         #+#    #+#              */
/*   Updated: 2026/11/16 13:55:55 by username        ###   ########.fr        */
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
	d = (int)(disorder * 100);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:43:47 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:43:51 by yaozhou          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:44:09 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:44:12 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	k;
	long	sign;

	i = 0;
	k = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = 10 * k + nptr[i] - '0';
		i++;
		if (k > 2147483648)
			return (2147483649);
	}
	return (k * sign);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	k;
	int	sign;

	i = 0;
	k = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = 10 * k + nptr[i] - '0';
		i++;
	}
	return (k * sign);
}

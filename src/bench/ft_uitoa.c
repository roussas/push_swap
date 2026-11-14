/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:57:50 by yaozhou           #+#    #+#             */
/*   Updated: 2026/10/20 14:30:37 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_intlength(unsigned int n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	len;
	char	*nstr;

	len = ft_intlength(n);
	nstr = malloc((len + 1) * sizeof(char));
	if (nstr == NULL)
		return (NULL);
	nstr[len] = '\0';
	if (n == 0)
		nstr[0] = '0';
	if (n < 0)
	{
		nstr[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		nstr[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (nstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   str_utils.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:29:25 by username         #+#    #+#              */
/*   Updated: 2026/11/14 12:51:31 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	comp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}

int	ft_strcmp(char *s)
{
	char	*simple;
	char	*medium;
	char	*complex;
	char	*adaptive;

	simple = "--simple";
	medium = "--medium";
	complex = "--complex";
	adaptive = "--adaptive";
	if (comp(s, simple))
		return (1);
	else if (comp(s, medium))
		return (2);
	else if (comp(s, complex))
		return (3);
	else if (comp(s, adaptive))
		return (4);
	else
		return (0);
}

t_node	*str_sel(char *s, t_node **a, t_node **b)
{
	if (ft_strcmp(s) == 1)
		insertion(a, b);
	else if (ft_strcmp(s) == 2)
		rangebased_sort(a, b);
	else if (ft_strcmp(s) == 3)
		radix_sort(a, b);
	else
		adaptive(a, b);
	return (*a);
}

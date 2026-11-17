/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   error_handle.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:23:07 by username         #+#    #+#              */
/*   Updated: 2026/11/17 11:24:18 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *s)
{
	int	i;
	int	digits;

	if (s == NULL)
		return (0);
	i = 0;
	digits = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			digits++;
		else if (s[i] == '+' || s[i] == '-')
		{
			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				return (0);
			if (i != 0 && s[i - 1] != ' ')
				return (0);
		}
		else if (s[i] != ' ')
			return (0);
		i++;
	}
	return (digits > 0);
}

void	free_list(char **l)
{
	int	i;

	if (l == NULL)
		return ;
	i = 0;
	while (l[i])
	{
		free(l[i]);
		i++;
	}
	free(l);
}

int	count_numbers(char **l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

void	add_back(t_node **a, t_node *new)
{
	t_node	*last;

	if (a == NULL || new == NULL)
		return ;
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	no_doubles(t_node *a)
{
	t_node	*tmp;
	t_node	*current;

	tmp = a;
	while (tmp)
	{
		current = tmp->next;
		while (current)
		{
			if (tmp->value == current->value)
				return (0);
			current = current->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

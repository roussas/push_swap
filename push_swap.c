/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:34:03 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/27 13:46:02 by kpagkalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	append_arg(t_node **a, char *arg)
{
	t_node	*new;

	if (!is_valid_int(arg) || !is_int(arg))
		return (0);
	new = str_to_node(arg);
	if (new == NULL)
		return (0);
	add_back(a, new);
	return (1);
}

t_node	*list(char **s, int i)
{
	t_node	*a;

	a = NULL;
	while (s[i])
	{
		if (!append_arg(&a, s[i]))
		{
			free_stack(&a);
			return (NULL);
		}
		i++;
	}
	return (a);
}

static int	print_error(t_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	return (1);
}

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
	char	*simple = "--simple";
	char	*medium = "--medium";
	char	*complex = "--complex";
	char	*adaptive = "--adaptive";

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

t_node *str_sel(char *s, t_node **a, t_node **b)
{
	if(ft_strcmp(s) == 1)
		insertion(a,b);
	else if (ft_strcmp(s) == 2)
		rangebased_sort(a,b);
	else if (ft_strcmp(s) == 3)
		radix_sort(a,b);	
	else
		adaptive(a,b);
	return (*a);
}


int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == '-')
		i = 2;
	a = list(argv, i);
	if (a == NULL || !no_doubles(a))
		print_error(&a);
	if (i == 2)
		a = str_sel(argv[1], &a, &b);
	else
		adaptive(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

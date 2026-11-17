/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:52:10 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:52:17 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_error(t_node **a, t_flag *f)
{
	free_stack(a);
	free(f);
	write(2, "Error\n", 6);
	return (1);
}

static void	free_all(t_node **a, t_node **b, t_flag *f, t_bench *bench)
{
	free_stack(a);
	free_stack(b);
	free(bench);
	free(f);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_flag	*f;
	t_bench	*bench;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	f = flags_init();
	if (f == NULL)
		return (1);
	if (!parseargs(argc, argv, &a, f) || !no_doubles(a))
	{
		print_error(&a, f);
		return (1);
	}
	bench = bench_init(a, f);
	if (bench == NULL)
		return (1);
	sort(&a, &b, &f, &bench);
	if (f->bench && f->countsonly == 0)
		write_bench(bench, f);
	else if (f->bench && f->countsonly == 1)
	{
		write_bench(bench, f);
		ft_putnbr1(total_ops(bench));
	}
	else if (f->bench == 0 && f->countsonly == 1)
		ft_putnbr1(total_ops(bench));
	free_all(&a, &b, f, bench);
	return (0);
}

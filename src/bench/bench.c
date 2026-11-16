/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 15:48:40 by username         #+#    #+#              */
/*   Updated: 2026/11/16 16:20:36 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*bench_init(t_node *a)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (bench == NULL)
		return (NULL);
	bench->disorder = compute_disorder(a);
	bench->cntpa = 0;
	bench->cntpb = 0;
	bench->cntsa = 0;
	bench->cntsb = 0;
	bench->cntss = 0;
	bench->cntra = 0;
	bench->cntrb = 0;
	bench->cntrr = 0;
	bench->cntrra = 0;
	bench->cntrrb = 0;
	bench->cntrrr = 0;
	return (bench);
}

void	write_bench(t_bench *bench, t_flag *flag)
{
	char *str;

	str = strdisorder(bench->disorder);
	write(2, "[bench] disorder:  ", 19);
	write(2, str, 5);
	free(str);
	write(2, "%\n", 2);
	if (flag->strategy == 0 || flag->strategy == 8)
	{
		if (bench->disorder < 0.2)
			write(2, "[bench] strategy:  Adaptive / O(n^2)", 36);
		else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
			write(2, "[bench] strategy:  Adaptive / O(n*sqrt(n))", 43);
		else if (bench->disorder >= 0.5)
			write(2, "[bench] strategy:  Adaptive / O(n*log(n))", 41);
	}
	else if (flag->strategy == 1)
		write(2, "[bench] strategy:  Simple / O(n^2)", 34);
	else if (flag->strategy == 2)
		write(2, "[bench] strategy:  Medium / O(n*sqrt(n))", 40);
	else if (flag->strategy == 4)
		write(2, "[bench] strategy:  Complex / O(n*log(n))", 40);
	write(2, "\n", 1);
	write_counts(bench);
}

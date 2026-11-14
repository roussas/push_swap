/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 11:33:24 by yaozhou           #+#    #+#             */
/*   Updated: 2026/10/20 15:24:48 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	ft_putnbr(unsigned int n)
{
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	write(2, &"0123456789"[n % 10], 1);
}

static unsigned int total_ops(t_bench *bench)
{
	unsigned int	total_ops;

	total_ops = bench->cntpa \
				+ bench->cntpb \
				+ bench->cntsa \
				+ bench->cntsb \
				+ bench->cntss \
				+ bench->cntra \
				+ bench->cntrb \
				+ bench->cntrr \
				+ bench->cntrra \
				+ bench->cntrrb \
				+ bench->cntrrr;
	return (total_ops);
}

void write_counts(t_bench *bench)
{
	write(2, "[bench] total_ops:  ", 21);
	ft_putnbr(total_ops(bench));
    write(2, "\n", 1);
	write(2, "[bench] sa:  ", 14);
	ft_putnbr(bench->cntsa);
	write(2, "  sb:  ", 8);
	ft_putnbr(bench->cntsb);
	write(2, "  ss:  ", 8);
	ft_putnbr(bench->cntss);
	write(2, "  pa:  ", 8);
	ft_putnbr(bench->cntpa);
	write(2, "  pb:  ", 8);
	ft_putnbr(bench->cntpa);
    write(2, "\n", 1);
	write(2, "[bench] ra:  ", 14);
	ft_putnbr(bench->cntra);
	write(2, "  rb:  ", 8);
	ft_putnbr(bench->cntrb);
	write(2, "  rr:  ", 8);
	ft_putnbr(bench->cntrr);
	write(2, "  rra:  ", 9);
	ft_putnbr(bench->cntrra);
	write(2, "  rrb:  ", 9);
	ft_putnbr(bench->cntrrb);
	write(2, "  rrr:  ", 9);
	ft_putnbr(bench->cntrrr);
    write(2, "\n", 1);
}
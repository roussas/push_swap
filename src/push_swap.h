/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:34:25 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/11/14 15:16:07 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> //DEBUG ONLY: remove before submit
# include <unistd.h>

typedef struct s_flag
{
	int		strategy;
	int		bench;
}	t_flag;

typedef struct s_bench
{
	int		cntpa;
	int		cntpb;
	int		cntsa;
	int		cntsb;
	int		cntss;
	int		cntra;
	int		cntrb;
	int		cntrr;
	int		cntrra;
	int		cntrrb;
	int		cntrrr;
}	t_bench;


typedef struct t_node
{
	int			value;
	int			rank;
	struct t_node	*next;
}	t_node;

t_node	*new_t_node(int value);

void	push_top(t_node **stack, t_node *new);
t_node	*pop_top(t_node **stack);
int		stack_length(t_node *stack);
void	free_stack(t_node **stack);
void	print_stack(t_node *stack);

void	push_to(t_node **from, t_node **to);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
//DEBUG ONLY: remove before submit
void	pa(t_node **a, t_node **b, t_bench **bench);
void	pb(t_node **a, t_node **b, t_bench **bench);
void	sa(t_node **a, t_bench **bench);
void	sb(t_node **b, t_bench **bench);
void	ss(t_node **a, t_node **b, t_bench **bench);
void	ra(t_node **a, t_bench **bench);
void	rb(t_node **b, t_bench **bench);
void	rra(t_node **a, t_bench **bench);
void	rrb(t_node **b, t_bench **bench);
void	rrr(t_node **a, t_node **b, t_bench **bench);
void	rr(t_node **a, t_node **b, t_bench **bench);

int		is_sorted(t_node **stack);
int		max_bits(t_node **a);

 
// Parsing data
int		ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

t_flag	*flags_init();
int		parseargs(int count, char **args, t_node **a, t_flag *f);
int		is_valid_int(char *s);
t_node	*str_to_node(char *s);
void	add_back(t_node **a, t_node *new);
void	free_list (char **l);
int		no_doubles(t_node *a);


// Ranking functions
int		rank_set(t_node *node, t_node **a);
void	rank_list(t_node **a);

double  compute_disorder(t_node *stack);
// Sorting fork
void	sort(t_node *a, t_node *b, t_flag **f, t_bench **bench);
void	adaptive_sort(t_node *a, t_node *b, t_bench **bench);

// Benchmarking
t_bench	*bench_init(void);
void	write_bench(t_bench *bench, t_flag *flag, t_node *a);

// Sorting algorithms
void    insertion(t_node **a, t_node **b, t_bench **bench);
void    chunkbased(t_node **a, t_node **b);
void	rangebased_sort(t_node **a, t_node **b, t_bench **bench);
void	radix_sort(t_node **a, t_node **b, t_bench **bench);

#endif

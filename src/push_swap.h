/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaozhou <yaozhou@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:52:31 by yaozhou           #+#    #+#             */
/*   Updated: 2026/11/17 11:52:34 by yaozhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define SMALL_INPUT 5

typedef struct t_node
{
	int				value;
	int				rank;
	struct t_node	*next;
}	t_node;

typedef struct s_flag
{
	int	strategy;
	int	bench;
}	t_flag;

typedef struct s_bench
{
	double			disorder;
	unsigned int	cntpa;
	unsigned int	cntpb;
	unsigned int	cntsa;
	unsigned int	cntsb;
	unsigned int	cntss;
	unsigned int	cntra;
	unsigned int	cntrb;
	unsigned int	cntrr;
	unsigned int	cntrra;
	unsigned int	cntrrb;
	unsigned int	cntrrr;
}	t_bench;

typedef struct s_chunk
{
	int	lo;
	int	hi;
}	t_chunk;

t_node	*new_t_node(int value);

void	push_top(t_node **stack, t_node *new);
t_node	*pop_top(t_node **stack);
int		stack_length(t_node *stack);
void	free_stack(t_node **stack);

void	push_to(t_node **from, t_node **to);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

void	pa(t_node **a, t_node **b, t_bench **bench);
void	pb(t_node **a, t_node **b, t_bench **bench);
void	sa(t_node **a, t_bench **bench);
void	sb(t_node **b, t_bench **bench);
void	ss(t_node **a, t_node **b, t_bench **bench);
void	ra(t_node **a, t_bench **bench);
void	rb(t_node **b, t_bench **bench);
void	rr(t_node **a, t_node **b, t_bench **bench);
void	rra(t_node **a, t_bench **bench);
void	rrb(t_node **b, t_bench **bench);
void	rrr(t_node **a, t_node **b, t_bench **bench);
int		is_sorted(t_node **stack);
int		max_bits(t_node **a);

// Parsing data
t_flag	*flags_init(void);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		parseargs(int count, char **args, t_node **a, t_flag *f);
int		checkarg(const char *arg);
int		parseflags(const char *arg, t_flag *f);
int		parsedata(const char *arg, t_node **a);
int		is_valid_int(char *s);
int		is_valid_data(char *s);
t_node	*str_to_node(char *s);
void	add_back(t_node **a, t_node *new);

void	free_list(char **l);
int		no_doubles(t_node *a);

// Ranking functions
int		rank_set(t_node *node, t_node **a);
void	rank_list(t_node **a);

// Benchmarking
t_bench	*bench_init(t_node *a);
double	compute_disorder(t_node *stack);
char	*strdisorder(double disorder);
char	*ft_uitoa(unsigned int n);
void	write_bench(t_bench *bench, t_flag *flag);
void	write_counts(t_bench *bench);

// Sorting fork
void	sort(t_node **a, t_node **b, t_flag **f, t_bench **bench);
void	adaptive_sort(t_node **a, t_node **b, t_bench **bench);

// Sorting algorithms
void	insertion(t_node **a, t_node **b, t_bench **bench);
void	chunkbased(t_node **a, t_node **b);
void	rangebased_sort(t_node **a, t_node **b, t_bench **bench);
void	radix_sort(t_node **a, t_node **b, t_bench **bench);

void	reverse_rotate(t_node **stack);
void	rotate(t_node **stack);
void	swap(t_node **stack);
void	push_to(t_node **from, t_node **to);
int		rank_set(t_node *node, t_node **a);
void	rank_list(t_node **a);
int		max_bits(t_node **a);
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
int		is_valid_int(char *s);
void	free_list(char **l);
t_node	*str_to_node(char *s);
void	add_back(t_node **a, t_node *new);
int		no_doubles(t_node *a);
int		ft_atoi(const char *nptr);
double	compute_disorder(t_node *stack);
void	chunkbased(t_node **a, t_node **b);
int		is_int(char *s);
int		findmax_n(t_node *stack, int n);
int		sqrt_approx(int nb);
int		count_numbers(char **l);
t_node	*str_sel(char *s, t_node **a, t_node **b);
int		ft_strcmp(char *s);
int		comp(char *s1, char *s2);
int		findmax_n(t_node *stack, int n);
int		pushrange(t_node **a, t_node **b, int rtop, t_bench **bench);
void	rangebased_insertion(t_node **a, t_node **b, int n, t_bench **bench);
void	sort_chunk(t_node **a, t_node **b, int n, t_bench **bench);
void	rotate_to(t_node **b, int pos, t_bench **bench);
void	sort_three(t_node **a, t_bench **bench);

#endif

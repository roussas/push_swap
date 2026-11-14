/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/14 12:23:42 by username         #+#    #+#              */
/*   Updated: 2026/11/14 13:19:06 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stddef.h>

# define SMALL_INPUT 5

typedef struct t_node
{
	int				value;
	int				rank;
	struct t_node	*next;
}	t_node;

typedef struct s_flag
{
	int		strategy;
	int		bench;
}	t_flag;
// typedef struct t_bench
// {
// 	double	disorder_n;
// 	char    *strat;
//     int     total_ops;
//     int     sa;
//     int     sb;
//     int     ss;
//     int     pa;
//     int     pb;
//     int     ra;
//     int     rb;
//     int     rr;
//     int     rra;
//     int     rrb;
//     int     rrr;
// } t_bench;

void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	ss(t_node **a, t_node **b);
void	sb(t_node **b);
void	sa(t_node **a);
void	rrr(t_node **a, t_node **b);
void	rrb(t_node **b);
void	rra(t_node **a);
void	rr(t_node **a, t_node **b);
void	rb(t_node **b);
void	ra(t_node **a);
t_node	*new_t_node(int value);
void	push_top(t_node **stack, t_node *new);
t_node	*pop_top(t_node **stack);
int		stack_length(t_node *stack);
void	free_stack(t_node **stack);
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
void	insertion(t_node **a, t_node **b);
void	chunkbased(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
int		is_int(char *s);
void	rangebased_sort(t_node **a, t_node **b);
int		findmax_n(t_node *stack, int n);
int		sqrt_approx(int nb);
int		count_numbers(char **l);
t_node	*str_sel(char *s, t_node **a, t_node **b);
int		ft_strcmp(char *s);
int		comp(char *s1, char *s2);
int		findmax_n(t_node *stack, int n);
int		pushrange(t_node **a, t_node **b, int rtop);
void	rangebased_insertion(t_node **a, t_node **b, int n);
void    sort_chunk(t_node **a, t_node **b, int n);
void    rotate_to(t_node **b, int pos);
void	sort_three(t_node **a);
int is_valid_data(char *s);
int parsedata(const char *arg, t_node **a);
int parseflags(const char *arg, t_flag *f);
t_flag *flags_init();
int checkarg(const char *arg);
int parseargs(int count, char **args, t_node **a, t_flag *f);
void	adaptive_sort(t_node **a, t_node **b);
void	sort(t_node **a, t_node **b, t_flag *f);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

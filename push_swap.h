/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpagkalo <kpagkalo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:34:25 by kpagkalo          #+#    #+#             */
/*   Updated: 2026/10/27 13:52:14 by kpagkalo         ###   ########.fr       */
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

typedef struct t_node
{
	int			value;
	int			rank;
	struct t_node	*next;
}	t_node;

void	print_stack(t_node *stack);
//DEBUG ONLY: remove before submit
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
int		is_sorted(t_node **stack);
int rank_set(t_node *node, t_node **a);
void rank_list (t_node **a);
int max_bits(t_node **a);
void radix_sort(t_node **a, t_node **b);
int	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);







double  compute_disorder(t_node *stack);
// Ranking functions
int rank_set(t_node *node, t_node **a);
void rank_list(t_node **a);

// Sorting algorithms
void    insertion(t_node **a, t_node **b);
void    chunkbased(t_node **a, t_node **b);

#endif

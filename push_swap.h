#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				value;
	int				rank;
	struct t_node	*next;
}	t_node;

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
void	adaptive(t_node **a, t_node **b);

#endif

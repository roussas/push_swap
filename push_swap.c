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

// void	ft_lstadd_back(t_node **lst, t_node *new)
// {
// 	t_node	*last;

// 	if (new == NULL || lst == NULL)
// 		return ;
// 	last = ft_lstlast(*lst);
// 	if (last == NULL)
// 		*lst = new;
// 	else
// 		last->next = new;
// 	new->next = NULL;
// }

// t_node	*ft_lstlast(t_node *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 	{
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

int	ft_atoi(const char *nptr)
{
	int	i;
	int	k;
	int	sign;

	i = 0;
	k = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = 10 * k + nptr[i] - '0';
		i++;
	}
	return (k * sign);
}

// t_node **list(char **s, int i)
// {
// 	t_node  **a;

// 	//Trying to get the list into a linked list , move backwards to put it
//     //in correct form || NEEDS BETTER LOGIC
//     while(argv[i])
//     {
// 		//Maybe check for atoi return
//         ft_lstadd_back(a,new_t_node(ft_atoi(argc[i])));
//         i++;
//     }
// 	return (a);
// }

// int main (int argc , char ** argv)
// {

//     int i;
//     t_node  **a;
//     t_node  *b;
//     //Error handling  , must check for how many arguments I can take
//     if (argc < 2)
//         write(2,"Error\n",6);
//     //check for command , also needs work
//     if (argv[1] == "--simple" || argv[1] == "--medium" || argv[1] == "--complex"|| argv[1] =="--adaptive")
// 	{
// 		i = 2;
// 		a = list(argv,i);
// 	}
// 	else
// 	{
// 		i = 1;
// 		a = list(argv[i])
// 	}   
// }
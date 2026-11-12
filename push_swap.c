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

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;
    t_flag *f;

    if (argc < 2)
        return (0);
    a = NULL;
    b = NULL;
    f = flags_init();
    // if (f == NULL)
    //     return (error);
    if (!parseargs(argc, argv, &a, f))
    {
        write(2, "Error\n", 6);
        return (0);
    }
    if (!no_doubles(a))
    {
        printf("Doubles found\n");
        write(2, "Error\n", 6);
        return (0);
    }
    // print_stack(a);
    sort(a, b, f);
    // print_stack(a);
    return (1);
}
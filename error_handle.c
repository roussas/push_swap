#include "push_swap.h"
#include <stdio.h>

int is_valid_int(char *s)
{
    int i;
    int digits;

    if (s == NULL)
        return (0);
    i = 0;
    digits = 0;
    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
            digits++;
        else if (s[i] == '+' || s[i] == '-')
        {
            if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
                return (0);
            if (i != 0 && s[i - 1] != ' ')
                return (0);
        }
        else if (s[i] != ' ')
            return (0);
        i++;
    }
    return (digits > 0);
}

void free_list (char **l)
{
    int i;

    if (l == NULL)
        return;
    i = 0;
    while(l[i])
    {
        free(l[i]);
        i++;
    }
    free(l);
}

static int count_numbers(char **l)
{
    int i;

    i = 0;
    while (l[i])
        i++;
    return (i);
}

void add_back(t_node **a, t_node *new)
{
    t_node  *last;

    if (a == NULL || new == NULL)
		return ;
    if (*a == NULL)
    {
        *a = new;
        return ;
    }
    last = *a;
    while (last->next)
        last = last->next;
    last->next = new;
}

int no_doubles(t_node *a)
{
    t_node *tmp;
    t_node *current;
    int     counter;

    counter = 0;
    tmp = a;
    while (tmp)
    {
        while (current)
        {
            if(tmp->value == current->value)
                counter++;
            current = current->next;
        }
        if (counter != 1)
            return (0);
        current = a;
        tmp = tmp->next;
        counter = 0;
    }
    return (1);
}

int is_int(char *s)
{
    char **l;
    long     n;
    int     i;

    l = ft_split(s,' ');
    if (l == NULL)
        return (0);
    i = 0;
    while (l[i])
    {
        n = ft_atol(l[i]);
        if(n < -2147483648 || n > 2147483647)
        {
            free_list(l);
            return (0);
        }
        i++;
    }
    free_list(l);
    return (1);
}

t_node *str_to_node(char *s)
{
    char    **l;
    int     i;
    t_node  *a;
    t_node  *n;

    a = NULL;
    l = ft_split(s, ' ');
    if (l == NULL)
        return (NULL);
    i = count_numbers(l) - 1;
    while (i >= 0)
    {
        n = new_t_node(ft_atoi(l[i]));
        if (n == NULL)
        {
            free_stack(&a);
            free_list(l);
            return (NULL);
        }
        push_top(&a, n);
        i--;
    }
    free_list(l);
    return (a);
}
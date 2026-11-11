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
//NOT WORKING
int no_doubles(t_node *a)
{
    t_node *tmp;
    t_node *prp;
    int     counter;

    counter = 0;
    tmp = a;
    prp = a;
    while (tmp)
    {
        while (prp)
        {
            if(tmp->value == prp->value)
                counter++;
            prp = prp->next;
        }
        if (counter != 1)
            return (0);
        prp = a;
        tmp = tmp->next;
        counter = 0;
    }
    return (1);
}

int is_int(t_node *a)
{
    t_node *tmp;

    tmp = a;
    while (tmp)
    {
        if(tmp->value <= -2147483648 && tmp->value >= 2147483648)
            return (0);
        tmp = tmp->next;
    }
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
        n = new_t_node(ft_atol(l[i]));
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


int main()
{
    char *s = "1 08742  748 173 7645186 5490 637 5742734 53 8761 9 15000000000";
    char *l = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 18 10000 231";
    t_node *a = str_to_node(s);
    t_node *b = str_to_node(l);
    print_stack(a);
    // printf("\n");
    // print_stack(b);
    printf("Invalid : %i\nValid : %i\n",is_int(a),is_int(b));
}
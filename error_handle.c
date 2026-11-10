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
static int is_int (char **l)
{
    int i;

    if (i < ft_ato)
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

// int main (void)
// {
//     char *s = "1 2 3 4 5 -65 -34 +34";
//     char *b = "1 8 4 0 56 35-45 1 3";

//     printf("valid : %i\ninvalid : %i\n",is_valid_int(s),is_valid_int(b));
// }

int main (void)
{
    char *s = "2 5 6 -556 -642 -12 5582 8673";
    t_node *a = str_to_node(s);
    print_stack(a);
}
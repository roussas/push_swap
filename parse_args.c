#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

// romve below
#include <stdio.h>

// possible flags
// strategy selector:
//      --simple
//      --medium
//      --complex
//      --adaptive
// bench mode: (display)
//      --bench
//
// 6-bit integer
// 0th: bench
// 1st: simple, [0000, 0001], [0, 1]
// 2nd: medium, [0000, 0010], [0, 2]
// 3rd: complex, [0000, 0100], [0, 4]
// 4th: adaptive, [0000, 1000], [0, 8]
// 0; 0000: adaptive, no bench mode
// 1; 0001: adaptive with bench
// 2; 0010: simple, no bench
// 3; 0011: simple, with bench
// 4, 0100: medium, no bench
// 5, 0101: medium, with bench
// 8, 1000: complex, no bench
// 9, 1001: complex, with bench

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
            {
                counter++;
                if(counter > 1)
                    printf("double found: %d\n", prp->value);

            }
            prp = prp->next;
        }
        if (counter != 1)
        {
            return (0);
        }
        prp = a;
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

int is_valid_data(char *s)
{
    if (!is_valid_int(s))
        return (0);
    if (!is_int(s))
        return (0);
    return (1);
}

int parsedata(const char *arg, t_node **a)
{
    t_node  *tmp;

    if (!is_valid_data((char *)arg))
        return (0);
    // printf("Valid integer detected: %s\n", arg);
    // printf("Making node from str\n");
    tmp = str_to_node((char *)arg);
    add_back(a, tmp);

    // check if it is a single argument
    //      whitespace?, atoi, put on stack
    // check if it is a string in the correct format to split
    //      whitespace?, split, atoi, put on stack
    // include validation check --> call validator
    //      put on stack, mind direction (earliest arg is top of stack)
    return (1);
}

int parseflags(const char *arg, t_flag *f)
{
    int strat;

    strat = 0;
    if (!ft_strncmp(arg, "--bench", 8))
        f->bench = 1;
    else if (!ft_strncmp(arg, "--simple", 9))
        strat = 1;
    else if (!ft_strncmp(arg, "--medium", 9))
        strat = 2;
    else if (!ft_strncmp(arg, "--complex", 10))
        strat = 4;
    else if (!ft_strncmp(arg, "--adaptive", 11))
        strat = 8;
    strat = f->strategy | strat;
    if (!(strat == 0 || strat == 1 || strat == 2 || strat == 4 || strat == 8))
        return (0);
    f->strategy = strat;
    return (1);
}

t_flag *flags_init()
{
    t_flag *f;
    f = malloc(sizeof(t_flag));
    if (f == NULL)
        return (NULL);
    f->bench = 0;
    f->strategy = 0;
    return (f);
}

int checkarg(const char *arg)
{
    if (!ft_strncmp(arg, "--", 2))
        return ('f');
    else
        return ('d');
}

int parseargs(int count, char **args, t_node **a, t_flag *f)
{
    int i;

    i = 1;
    while (i < count)
    {
        if (checkarg(args[i]) == 'f')
        {
            if (!parseflags(args[i], f))
                return (0);
        }
        else if (checkarg(args[i]) == 'd')
        {
            // printf("no flag detected: %s\n", args[i]);
            if(!parsedata(args[i], a))
                return (0);
        }
        i++;
    }
    return (1);
}

void adaptive_sort(t_node *a, t_node *b)
{
    float disorder;
    
    disorder = compute_disorder(a);
    if (disorder < 0.2)
        insertion(&a, &b);
    else if ((0.2 <= disorder) && (disorder < 0.5))
        rangebased_sort(&a, &b);
    else if (disorder >= 0.5)
        radix_sort(&a, &b);
}

void sort(t_node *a, t_node *b, t_flag *f)
{
    // printf("strategy chosen: %d\n", f->strategy);
    if (f->strategy == 0 || f->strategy == 8)
        adaptive_sort(a, b);
    else if (f->strategy == 1)
        insertion(&a, &b);
    else if (f->strategy == 2)
        rangebased_sort(&a, &b);
    else if (f->strategy == 4)
        radix_sort(&a, &b);
}
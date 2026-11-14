#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

t_bench *bench_init(void)
{
    t_bench *bench;

    bench = malloc(sizeof(t_bench));
    if (bench == NULL)
        return (NULL);
    bench->cntpa = 0;
    bench->cntpb = 0;
    bench->cntsa = 0;
    bench->cntsb = 0;
    bench->cntss = 0;
    bench->cntra = 0;
    bench->cntrb = 0;
    bench->cntrr = 0;
    bench->cntrra = 0;
    bench->cntrrb = 0;
    bench->cntrrr = 0;
    return (bench);
}

static char *strdisorder(t_node *a)
{
    float   disorder;
    int     d;
    char    *str;
    int     i;

    disorder = compute_disorder(a);
    str = malloc(6 * sizeof(char));
    d = (int)(disorder * 100);
    i = 0;
    while(i < 5)
    {
        if (i != 2)
        {
            str[i] = (d % 10) + '0';
            d = d / 10;
        }
        else
            str[i] = '.';
        i++;
    }
    str[i] = '\0';
    return (str);    
}

void write_bench(t_bench *bench, t_flag *flag, t_node *a)
{
    int total;

    write(2, strdisorder(a), 6);
    total = bench->cntpa + bench->cntpb;
    if (flag->strategy == 0 || flag->strategy == 8)
        write(2, "[bench] strategy:  Adaptive / O(n*sqrt(n))", 44);
    printf("pa: %d\n", bench->cntpa);
}
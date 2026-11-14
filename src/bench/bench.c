#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

t_bench *bench_init(t_node *a)
{
    t_bench *bench;

    bench = malloc(sizeof(t_bench));
    if (bench == NULL)
        return (NULL);
    bench->disorder = compute_disorder(a);
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

void write_bench(t_bench *bench, t_flag *flag)
{
    int total;

    write(2, "[bench] disorder:  ", 20);
    write(2, strdisorder(bench->disorder), 6);
    write(2, "\n", 1);
    total = bench->cntpa + bench->cntpb;
    if (flag->strategy == 0 || flag->strategy == 8)
        write(2, "[bench] strategy:  Adaptive / O(n*sqrt(n))", 44);
    else if (flag->strategy == 1)
        write(2, "[bench] strategy:  Simple / O(n^2)", 35);
    else if (flag->strategy == 2)
        write(2, "[bench] strategy:  Medium / O(n*sqrt(n))", 41);
    else if (flag->strategy == 4)
        write(2, "[bench] strategy:  Complex / O(n*log(n))", 41);
    write(2, "\n", 1);
    write_counts(bench);
}
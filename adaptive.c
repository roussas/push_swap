#include "push_swap.h"

void *adaptive(t_node **a, t_node **b)
{
    double dis;

    dis = compute_disorder(*a);
    if (dis < 0.2)
        insertion(a,b);
    else if (dis >= 0.2 && dis < 0.5)
        rangebased_sort(a,b);
    else if (dis >= 0.5)
        radix_sort(a, b);
}
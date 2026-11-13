#include "push_swap.h"

double  compute_disorder(t_node *stack)
{
    int mistakes;
    int totalpairs;
    t_node *i;
    t_node *j;

    mistakes = 0;
    totalpairs = 0;
    i = stack;
    while (i)
    {
        j = i->next;
        while (j)
        {
            totalpairs++;
            if (i->value > j->value)
                mistakes++;
            j = j->next;
        }
        i = i->next;
    }
    return ((double)mistakes / (double)totalpairs);
}
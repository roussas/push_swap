#include "push_swap.h"

double  compute_disorder(t_node *stack)
{
    double mistakes;
    double totalpairs;
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
    if  (totalpairs == 0)
        return(totalpairs);
    return (mistakes / totalpairs);
}

int main(void)
{
    t_node *a = NULL;
    t_node *one = new_t_node(4);
    printf("%f\n", compute_disorder(one));
    printf("%f\n", compute_disorder(a));
}
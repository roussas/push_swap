#include "push_swap.h"

int rank_set(t_node *node, t_node **a)
{
    int i;
    t_node *tmp;
    i = 0;
    tmp = *a;
    while(tmp != NULL)
    {
        if (node->value > tmp->value)
            i++;
        tmp = tmp->next;
    }
    return (i);
}

void rank_list (t_node **a)
{
    t_node *tmp;
    tmp = *a;
    while (tmp != NULL)
    {
        tmp->rank = rank_set(tmp,a);
        tmp = tmp->next; 
    }
}
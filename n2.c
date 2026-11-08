#include "push_swap.h"
#include <stdlib.h>


    //FIND THE SMALLEST NUMBER IN A , PUT IT TO B , WHEN A HAS ONLY ONE NUMBER , PUT EVERYTHING FROM B TO A
    // THIS IS N^2 ALGORITHM
    //The idea is find the smallest number :
    /*
        if the min is after the middle of the linked list
            rra
        else 
            ra
        if min is in the head
            pb
        if stack a has only one element
            pa everything from pb
    
    */
void    ntwo(t_node **a, t_node **b)
{

    int min;
    t_node *tmp;
    int pos;
    int i;
    if (a == NULL)
        return ;
    i = 0;
    pos = i;
    min = (*a)->value;
    tmp = *a;
    while(tmp)
    {
        if (tmp-> value < min)
        {
             min = tmp->value;
             pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    if (pos > i / 2)
    {
        while (i - pos > 0)
        {
            rra(a);
            pos++;
        }
    }
    else if (pos <= i / 2)
    {
        while (pos != 0)
        {
            ra(a);
            pos--;
        }
    }
    pb(a,b);
    if (stack_length(*a) != 1)
        ntwo(a,b);
    while (*b != NULL)
        pa(a,b);
}

// int main (void)
// {
//     t_node *a = NULL;
//     t_node *b = NULL;
//     //*a = new_t_node(18);
//     int i []= { 18, 1 , 93, 5 ,22 , 7 ,2 ,9 ,8 ,3};
//     int k = 0 ;
//     while (k < 10)
//     {
//         push_top(&a,new_t_node(i[k]));
//         k++;
//     }
//     ntwo(&a,&b);
//     print_stack(a);
//     free_stack(&a);
//     free_stack(&b);
// }
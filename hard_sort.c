
#include "push_swap.h"

void    first_sort(t_list **stack_a, t_list **stack_b, t_sort *sort)
{
    //printf("first_sort\n");

    int i;
    int count_a;

    i = 0;
    count_a = count_lst(stack_a);
    while(i++ < count_a)
    {
        if((*stack_a)->index <= sort->mid)
            pb(stack_a, stack_b);
        else if((*stack_a)->index > sort->mid)
        {
            if(count_lst(stack_b) > 1 && (*stack_b)->index < sort->mid / 2)
                rr(stack_a, stack_b);
            else if ((*stack_a)->index > sort->mid)
                ra(stack_a);
        }
    }
    sort->max = sort->mid;
    sort->mid = (sort->max - sort->min) / 2 + sort->min;
}

void    find_next(t_list **stack_a, t_list **stack_b, t_sort *sort)
{
    //printf("find_next\n");

    if(count_lst(stack_b) > 0 && (*stack_b)->index == sort->min)
    {
        pa(stack_a, stack_b);
      //  printf("////1////\n");
    }
    else if ((*stack_a)->index == sort->min)
    {
        (*stack_a)->flag = -1;
        sort->min++;
        ra(stack_a);
        //printf("////2////\n");
    }
    else if ((*stack_a)->next->index == sort->min)
    {
        sa(stack_a);
        //printf("////7////\n");
    }
    else if (count_lst(stack_b) == 2 && (*stack_b)->next->index == sort->min)
    {
         sb(stack_b);
    //     printf("////4////\n");
    } 
    else if ((count_lst(stack_a) > 1) && ((*stack_a)->next->index == sort->min) && ((*stack_b)->next->index == sort->min + 1))
    {
        ss(stack_a, stack_b);
        //printf("////3////\n");
    }   
    else if (count_lst(stack_b) > 1 && (ft_lstlast(*stack_b)->index == sort->min))
    {
        rrb(stack_b);
       // printf("////5////\n");
    }
    else
    {
        //printf("////6////\n");
        return ;
    }
    find_next(stack_a, stack_b, sort);
}

void    push_b_to_a(t_list **stack_a, t_list **stack_b, t_sort *sort)
{
    //printf("push_a\n");

    while(count_lst(stack_b) > 0)
    {
        if((*stack_b)->index == sort->min)
            find_next(stack_a, stack_b, sort);
        else if ((*stack_b)->index >= sort->mid)
        {
            (*stack_b)->flag = 1;
            pa(stack_a, stack_b);
        }
        else if ((*stack_b)->index < sort->mid)
            rb(stack_b);
    }
    sort->max = sort->mid;
    sort->mid = (sort->max - sort->min) / 2 + sort->min;
}

void    push_a_to_b(t_list **stack_a,  t_list **stack_b, t_sort *sort)
{
    //printf("push_bbb\n");
    //int new_flag;
    //new_flag = (*stack_a)->flag;
    if((*stack_a)->flag == 1)
    {
        while((*stack_a)->flag == 1)
        {
            if((*stack_a)->index != sort->min)
                pb(stack_a, stack_b);
            find_next(stack_a, stack_b, sort);
        }
    }
    else if((*stack_a)->flag  == 0)
    {
        while((*stack_a)->flag != -1)
        {
            if((*stack_a)->index != sort->min)
                pb(stack_a, stack_b);
            find_next(stack_a, stack_b, sort);
        }   
    }
    if(count_lst(stack_b))
        sort->max = (get_max(stack_b))->index;
    sort->mid = (sort->max - sort->min) / 2 + sort->min;
}

///////////////////////////////7
void print_list(t_list *list)
{
    while (list)
    {
        printf("%d \n", list->value);
        list = list->next;
    }
    printf("\n");
}

///////////////////////////////





void    hard_sort(t_list **stack_a, t_list **stack_b)
{
    t_sort sort;
    int count;
    set_index(stack_a);
    sort.min = get_min(stack_a)->index;
    sort.max = get_max(stack_a)->index;
    sort.mid = sort.max / 2 + sort.min;
    count = count_lst(stack_a);
    first_sort(stack_a, stack_b, &sort);
    //printf("stack A =\n");
    //print_list(*stack_a);

    //printf("stack B =\n");
    //print_list(*stack_b);

    while ((a_is_sorted(stack_a, count)) == 1)
    {
      //  printf("RESULT  from while = %d\n", a_is_sorted(stack_a, count));
       // printf("---------------------------wort\n");
        //printf("stack A =\n");
      //  print_list(*stack_a);

        //printf("stack B =\n");
        //print_list(*stack_b);
        if(count_lst(stack_b) == 0)
        {
            push_a_to_b(stack_a, stack_b, &sort);
        }
        else
        {
            push_b_to_a(stack_a, stack_b, &sort);
        }
    }
    //print_list(*stack_a);
}

#include "push_swap.h"

int main(int ac, char **av)
{
    char **arg_temp;
    t_list *stack_a;
    t_list *stack_b;
    if(ac < 2)
        return(1);
    check_args(ac, av);
    stack_a = (t_list **)malloc(sizeof(t_list));
    stack_b = (t_list **)malloc(sizeof(t_list));
    init(stack_a, ac, av);
    start_sort();
    return 0;
}
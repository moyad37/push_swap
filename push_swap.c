
#include "push_swap.h"

static void    init_stack(t_list **stack_a, int ac, char **av)
{
    printf("init\n");
    char **str;
    int i = 0;
    if(ac == 2)
    {
        str = ft_split(av[1], ' ');
        while (str[i])
        {
            ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(str[i])));
            i++;
        }
        free(str);
    }
    else
    {
        i = 1;
        while (i < ac)
        {
            ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i])));
            i++;   
        }
    }
}

int main(int ac, char **av)
{
    //char **arg_temp;
    t_list **stack_a;
    //t_list **stack_b;
    if(ac < 2)
        return(1);
    check_args(ac, av);
    stack_a = (t_list **)malloc(sizeof(t_list));
    //stack_b = (t_list **)malloc(sizeof(t_list));
    if(!stack_a || !stack_b)
        return (NULL);    
    init_stack(stack_a, ac, av);
    printf("fertig\n");
    //start_sort();
    return 0;
}
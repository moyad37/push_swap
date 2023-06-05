#include "push_swap.h"

int ft_check_doupple(char **str, int n)
{
    //printf("-----Check\n");
    int i;
    int key;
    
    key = 0;
    i = 0;
    while(str[i])
    {
        int num;
        num = ft_atoi(str[i]);
        if(num == n)
        {
            key++;
            if(key > 1)
                return (1);
        }
        i++;
    }
    return (0);
}

void check_args(int ac, char **av)
{
    int i;
    char **test;

    if(ac == 2)
    {
        //printf("-TEST1\n");
        test = ft_split(av[1], ' ');
    }
    else if (ac > 2)
    {
        //printf("--TEST2\n");
        i = 1;
        test = av;
    }
    while (test[i])
    {
        //printf("---TEST3\n");
        if(ft_is_number(test[i]) == 0)
            return_error("check your args, it have to be a number\n");
        if(ft_atol(test[i]) >= 2147483647 || ft_atol(test[i]) < -2147483648)
            return_error("check your args, INT_MAX or -INT_MAX\n");
        if (ft_check_doupple(test, ft_atoi(test[i])) != 0)
            return_error("check your args, it contains doupple numbers\n");
        i++;
    }
    if(ac == 2)
        free(test);
}
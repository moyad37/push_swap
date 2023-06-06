/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 14:11:29 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_doupple(char **str, int n)
{
    //printf("-----Check_doupple\n");
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
    printf("check_args\n");
    int i;
    char **test;

    if(ac == 2)
    {
        //printf("-TEST1\n");
        //printf("av[1] = %s\n", av[1]);
        i = 0;
        test = ft_split(av[1], ' ');
        //printf("pause\n");
        //for (size_t j = 0; test[j]; j++)
        //    printf("test = %s\n", test[j]);
        //printf("after for\n");
    }
    else if (ac > 2)
    {
        //printf("--TEST2\n");
        i = 1;
        test = av;
    }
    //printf("---TEST3\n");
    while (test[i])
    {
        //printf("---TEST6\n");
        if(ft_is_number(test[i]) == 0)
            return_error("check your args, it have to be a number\n");
        if(ft_atol(test[i]) >= 2147483647 || ft_atol(test[i]) < -2147483648)
            return_error("check your args, INT_MAX or -INT_MAX\n");
        if (ft_check_doupple(test, ft_atoi(test[i])) != 0)
            return_error("check your args, it contains doupple numbers\n");
        //write(1, "Hallo\n", 6);
        i++;
    }
    if(ac == 2)
        free(test);
}

int check_sorted(t_list **stack)
{
    t_list  *tmp;

    tmp = *stack;
    while(tmp && tmp->next)
    {
        if(tmp->value > tmp->next->value)
            return(0);
        tmp = tmp->next;
    }
    return (1);
}

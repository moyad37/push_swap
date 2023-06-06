/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 14:42:29 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_list **stack)
{
    t_list *tmp;
    if(!(*stack) || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = *stack->next;
    ft_lstadd_back(stack, tmp);
}

void    ra(t_list **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void    rb(t_list **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}


void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}

/*
void print_list(t_list *list)
{
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 14:42:29 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void revers_rotate(t_list **stack)
{
    t_list *tmp;
    t_list *bottom;
    if(!(*stack) || !(*stack)->next)
        return ;
    tmp = *stack;
    bottom = ft_lstlast(*stack);
    while((*stack)->next->next)
        *stack = (*stack)->next;
    bottom->next = tmp;
    (*stack)->next = NULL;
    *stack = bottom;
}

void    rra(t_list **stack_a)
{
    revers_rotate(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_list **stack_b)
{
    revers_rotate(stack_b);
    write(1, "rrb\n", 4);
}


void    rrr(t_list **stack_a, t_list **stack_b)
{
    revers_rotate(stack_a);
    revers_rotate(stack_b);
    write(1, "rrr\n", 4);
}

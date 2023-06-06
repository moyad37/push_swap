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
///MUSS NOCH MACHEN ALLES
static void revers_rotate(t_list **stack)
{
    t_list *tmp;
    if(!(*stack) || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = *stack->next;
    ft_lstadd_back(stack, tmp);
}

void    rra(t_list **stack_a)
{
    revers_rotate(stack_a);
    write(1, "rra\n", 3);
}

void    rrb(t_list **stack_b)
{
    revers_rotate(stack_b);
    write(1, "rrb\n", 3);
}


void    rrr(t_list **stack_a, t_list **stack_b)
{
    revers_rotate(stack_a);
    revers_rotate(stack_b);
    write(1, "rrr\n", 3);
}

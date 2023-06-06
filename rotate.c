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

void print_list(t_list *list)
{
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}
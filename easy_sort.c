/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:36:14 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/07 15:03:08 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack)
{
	if (((*stack)->value) > ((*stack)->next->value))
		sa(stack);
}

static int	operation(int a, int b, int c)
{
	if ((a > b) && (b > c) && (c < a))
		return (1);
	else if ((a < b) && (b > c) && (c > a))
		return (2);
	else if ((a > b) && (b < c) && (c < a))
		return (3);
	else if ((a < b) && (b > c) && (c < a))
		return (4);
	else if ((a > b) && (b < c) && (c > a))
		return (5);
	return (0);
}

void	sort_3(t_list **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;

	if (operation(a, b, c) == 1)
	{
		sa(stack);
		rra(stack);
	}
	else if (operation(a, b, c) == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if (operation(a, b, c) == 5)
		sa(stack);
	else if (operation(a, b, c) == 3)
		ra(stack);
	else if (operation(a, b, c) == 4)
		rra(stack);
}

void    sort_4(t_list **stack_a, t_list **stack_b)
{
    int min_value;
    int min_index;

    min_value = find_min_value(*stack_a);
    min_index = find_index_of_min(*stack_a, min_value);
    get_min_to_top(stack_a, min_index);
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}

void    sort_5(t_list **stack_a, t_list **stack_b)
{
    int min_value;
    int min_index;

    min_value = find_min_value(*stack_a);
    min_index = find_index_of_min(*stack_a, min_value);
    get_min_to_top(stack_a, min_index);
    pb(stack_a, stack_b);
    min_value = find_min_value(*stack_a);
    min_index = find_index_of_min(*stack_a, min_value);
    get_min_to_top(stack_a, min_index);
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

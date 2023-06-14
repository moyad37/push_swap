/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:37:31 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/14 14:29:28 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_list *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_index_of_min(t_list *stack, int min)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = 0;
	while (stack)
	{
		if (stack->value == min)
			min_index = i;
		stack = stack->next;
		i++;
	}
	return (min_index);
}

void	get_min_to_top(t_list **stack_a, int top_index)
{
	int	stack_size;

	if (top_index == 0)
		return ;
	else if (top_index == 1)
		sa(stack_a);
	else if (top_index <= ft_lstsize(*stack_a) / 2)
	{
		while (top_index > 0)
		{
			ra(stack_a);
			top_index--;
		}
	}
	else
	{
		stack_size = ft_lstsize(*stack_a);
		top_index = stack_size - top_index;
		while (top_index > 0)
		{
			rra(stack_a);
			top_index--;
		}
	}
}

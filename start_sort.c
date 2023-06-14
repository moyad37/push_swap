/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/14 14:29:56 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

void	start_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (check_sorted(stack_a) == 1)
	{
		return ;
	}
	size = ft_lstsize(*stack_a);
	if (size > 1 && size < 6)
		easy_sort(stack_a, stack_b, size);
	else if (size > 5)
		hard_sort(stack_a, stack_b);
}

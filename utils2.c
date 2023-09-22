/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/21 11:42:58 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_lst(t_list **stack)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	set_index(t_list **stack_a)
{
	t_list			*temp;
	t_list			*min_list;
	long long int	min;
	int				i;
	int				j;

	i = count_lst(stack_a);
	j = 0;
	while (j < i)
	{
		min = LLONG_MAX;
		temp = *stack_a;
		while (temp)
		{
			if ((temp->value < min) && (temp->index == -1))
			{
				min = temp->value;
				min_list = temp;
			}
			temp = temp->next;
		}
		min_list->index = j;
		j++;
	}
}

int	a_is_sorted(t_list **stack_a, int count)
{
	int	i;

	i = count_lst(stack_a);
	if (i == count && check_sorted(stack_a) == 1)
		return (0);
	return (1);
}

void	ft_free_stack_content(t_list **stack)
{
	t_list	*temp;
	t_list	*next;

	temp = *stack;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*stack = NULL;
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("value -> %d \n flag -> %d\n", list->value, list->flag);
		list = list->next;
	}
	printf("\n");
}

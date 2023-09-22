/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:57 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/14 14:25:57 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//alt
void	first_sort(t_list **stack_a, t_list **stack_b, t_sort *sort)
{
	int	i;
	int	count_a;

	i = 0;
	count_a = count_lst(stack_a);
	while (i++ < count_a)
	{
		if ((*stack_a)->index <= sort->mid)
			pb(stack_a, stack_b);
		else if ((*stack_a)->index > sort->mid)
		{
			if (count_lst(stack_b) > 1 && (*stack_b)->index < sort->mid / 2)
				rr(stack_a, stack_b);
			else if ((*stack_a)->index > sort->mid)
				ra(stack_a);
		}
	}
	sort->max = sort->mid;
	sort->mid = (sort->max - sort->min) / 2 + sort->min;
	sort->flag++;
}


//neu und richtig
// void	first_sort(t_list **stack_a, t_list **stack_b, t_sort *sort)
// {
// 	int	i;
// 	int	count_a;

// 	i = 0;
// 	count_a = count_lst(stack_a);
// 	while (i++ < count_a)
// 	{
// 		if ((*stack_a)->index <= sort->mid)
// 			pb(stack_a, stack_b);
// 		else
// 		{
// 			if (count_lst(stack_b) > 1 && (((*stack_b)->index) < (sort->mid / 2)))
// 				rr(stack_a, stack_b);
// 			else
// 				ra(stack_a);
// 		}
// 	}
// 	sort->max = sort->mid;
// 	sort->mid = (sort->max - sort->min) / 2 + sort->min;
// 	sort->flag++;
// }


void	find_next(t_list **stack_a, t_list **stack_b, t_sort *sort)
{
	if (count_lst(stack_b) > 0 && (*stack_b)->index == sort->min)
		pa(stack_a, stack_b);
	else if ((*stack_a)->index == sort->min)
	{
		(*stack_a)->flag = -1;
		sort->min++;
		ra(stack_a);
	}
	else if ((*stack_a)->next->index == sort->min)
		sa(stack_a);
	else if (count_lst(stack_b) == 2 && (*stack_b)->next->index == sort->min)
		sb(stack_b);
	else if ((count_lst(stack_a) > 1) && ((*stack_a)->next->index == sort->min)
		&& ((*stack_b)->next->index == sort->min + 1))
		ss(stack_a, stack_b);
	else if (count_lst(stack_b) > 1
		&& (ft_lstlast(*stack_b)->index == sort->min))
		rrb(stack_b);
	else
		return ;
	find_next(stack_a, stack_b, sort);
}

//alt
// void	push_b_to_a(t_list **stack_a, t_list **stack_b, t_sort *sort)
// {
// 	while (count_lst(stack_b) > 0)
// 	{
// 		if ((*stack_b)->index == sort->min)
// 			find_next(stack_a, stack_b, sort);
// 		else if ((*stack_b)->index >= sort->mid)
// 		{
// 			(*stack_b)->flag = sort->flag;
// 			pa(stack_a, stack_b);
// 		}
// 		else if ((*stack_b)->index < sort->mid)
// 			rb(stack_b);
// 	}
// 	sort->max = sort->mid;
// 	sort->mid = (sort->max - sort->min) / 2 + sort->min;
// 	sort->flag++;
// }

//DA IST DER FEHLER
//neu und richtig
void	push_b_to_a(t_list **stack_a, t_list **stack_b, t_sort *sort)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = count_lst(stack_b);
	while (count_lst(stack_b) && ++i < count_b)
	{
		if ((*stack_b)->index == sort->min)
			find_next(stack_a, stack_b, sort);
		else if ((*stack_b)->index >= sort->mid)
		{
			(*stack_b)->flag = sort->flag;
			pa(stack_a, stack_b);
		}
		else if ((*stack_b)->index < sort->mid)
			rb(stack_b);
	}
	sort->max = sort->mid;
	sort->mid = (sort->max - sort->min) / 2 + sort->min;
	sort->flag++;
}


//Falsch und alt
// void	push_a_to_b(t_list **stack_a, t_list **stack_b, t_sort *sort)
// {
// 	//printf("----------HALLOOOOOO PPPPP---------\n");
// 	if ((*stack_a)->flag == 0)
// 	{
// 		while ((*stack_a)->flag != -1)
// 		{
// 			if ((*stack_a)->index != sort->min)
// 				pb(stack_a, stack_b);
// 			find_next(stack_a, stack_b, sort);
// 		}
// 	}
// 	else if ((*stack_a)->flag == 1)
// 	{
// 		while ((*stack_a)->flag == 1)
// 		{
// 			if ((*stack_a)->index != sort->min)
// 				pb(stack_a, stack_b);
// 			find_next(stack_a, stack_b, sort);
// 		}
// 	}
// 	else 
// 	if (count_lst(stack_b))
// 		sort->max = (get_max(stack_b))->index;
// 	sort->mid = (sort->max - sort->min) / 2 + sort->min;
// }

//richtig und neu
void	push_a_to_b(t_list **stack_a, t_list **stack_b, t_sort *sort)
{
	int	now_flag;

	now_flag = (*stack_a)->flag;
	if ((*stack_a)->flag != 0)
	{
		while ((*stack_a)->flag == now_flag)
		{
			if ((*stack_a)->index != sort->min)
				pb(stack_a, stack_b);
			find_next(stack_a, stack_b, sort);
		}
	}
	else if ((*stack_a)->flag == 0)
	{
		while ((*stack_a)->flag != -1)
		{
			if ((*stack_a)->index != sort->min)
				pb(stack_a, stack_b);
			find_next(stack_a, stack_b, sort);
		}
	}
	if (count_lst(stack_b))
		sort->max = (get_max(stack_b))->index;
	sort->mid = (sort->max - sort->min) / 2 + sort->min;
}

void	hard_sort(t_list **stack_a, t_list **stack_b)
{
	t_sort	sort;
	int		count;

	set_index(stack_a);
	sort.min = get_min(stack_a)->index;
	sort.max = get_max(stack_a)->index;
	sort.mid = sort.max / 2 + sort.min;
	count = count_lst(stack_a);
	sort.flag = 0;
	first_sort(stack_a, stack_b, &sort);
	while ((a_is_sorted(stack_a, count)) == 1)
	{
		if (count_lst(stack_b) == 0)
		{
			push_a_to_b(stack_a, stack_b, &sort);
		}
		else
		{
			push_b_to_a(stack_a, stack_b, &sort);
		}
	}
}

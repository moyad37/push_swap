/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/14 14:13:21 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_doupple(char **str, int n)
{
	int	i;
	int	key;
	int	test;
	int	num;

	key = 0;
	i = 0;
	if (n == 0)
		test = 2;
	else
		test = 1;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num == n)
		{
			key++;
			if (key > test)
				return (1);
		}
		i++;
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	int		i;
	char	**test;

	if (ac == 2)
	{
		i = 0;
		test = ft_split(av[1], ' ');
	}
	else if (ac > 2)
	{
		i = 1;
		test = av;
	}
	while (test[i])
	{
		if (ft_is_number(test[i]) == 1)
			return_error("check your args, it have to be a number\n");
		if (ft_atol(test[i]) >= 2147483647 || ft_atol(test[i]) < -2147483648)
			return_error("check your args, INT_MAX or -INT_MAX\n");
		if (ft_check_doupple(test, ft_atoi(test[i])) != 0)
			return_error("check your args, it contains doupple numbers");
		i++;
	}
	if (ac == 2)
		free(test);
}

int	check_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

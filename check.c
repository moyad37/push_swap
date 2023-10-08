/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/29 15:09:10 by mmanssou         ###   ########.fr       */
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

int	check_lehr(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
		{
			i++;
		}
		else if (av[i] != ' ')
		{
			return (0);
		}
	}
	return (i);
}

int	checking_all(int ac, char **test, int i)
{
	if (ft_is_number(test[i]) == 1)
	{
		if (ac == 2)
			free_array(test);
		return_error("Error");
	}
	if (ft_atol(test[i]) >= 2147483647 || ft_atol(test[i]) < -2147483648)
	{
		if (ac == 2)
			free_array(test);
		return_error("Error");
	}
	if (ft_check_doupple(test, ft_atoi(test[i])) != 0)
	{
		if (ac == 2)
			free_array(test);
		return_error("Error");
	}
	return (0);
}

void	check_args(int ac, char **av)
{
	int		i;
	char	**test;

	test = NULL;
	i = 0;
	if (ac == 2)
	{
		if (!*av[1] || (check_lehr(av[1]) > 0))
			return_error("Error");
		test = ft_split(av[1], ' ');
		if(!test)
			return ;
	}
	else if (ac > 2)
	{
		i = 1;
		test = av;
	}
	if(test)
	{
		while (test[i])
		{
			if (checking_all(ac, test, i) == 0)
				i++;
			else
				free_array(test);
		}
		if (ac == 2)
			free_array(test);
	}
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

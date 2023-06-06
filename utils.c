/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 14:18:15 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i++])
		if (!ft_isdigit(n[i]))
			return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int sign = 1;
	long result = 0;
	int i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	free_stack(t_list **stack)
{
	t_list *tmp;
	t_list *head;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*tmp;

// 	if(*lst)
// 	{
// 		tmp = ft_lstlast(*lst);
// 		tmp->next = new;
// 		new->next = NULL;
// 	}
// 	else
// 	{
// 		*lst = new;
// 		(*lst)->next = NULL;
// 	}
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list *tmp;

// 	tmp = lst;
// 	while(tmp->next)
// 	{
// 		tmp = tmp->next;
// 		if(tmp->next == NULL)
// 			return (tmp);
// 	}
// 	return (tmp);
// }

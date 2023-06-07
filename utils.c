/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/07 14:36:40 by mmanssou         ###   ########.fr       */
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

void find_and_push_min(t_list **stack_a, t_list **stack_b)
{
    if (!(*stack_a))
        return;

    t_list *current = *stack_a;
    t_list *min_node = current;
    int min_value = current->value;

    // Finde den minimalen Wert und das zugehörige Listenelement
    while (current)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_node = current;
        }
        current = current->next;
    }

    // Entferne das minimale Element aus Stack A
    if (min_node == *stack_a)
        *stack_a = (*stack_a)->next;
    else
    {
        current = *stack_a;
        while (current->next != min_node)
            current = current->next;
        current->next = min_node->next;
    }

    // Füge das minimale Element zu Stack B hinzu
    min_node->next = *stack_b;
    *stack_b = min_node;
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

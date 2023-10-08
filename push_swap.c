/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/25 15:35:44 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	init_stack(t_list **stack_a, int ac, char **av)
{
	char	**str;
	int		hm;
	int		i;

	str = NULL;
	i = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if(!str)
			return ;
		while (str[i])
		{
			hm = ft_atoi(str[i]);
			ft_lstadd_back(stack_a, ft_lstnew(hm));
			i++;
		}
		free_array(str);
	}
	else
	{
		i = 0;
		while (++i < ac)
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i])));
	}
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (1);
	check_args(ac, av);
	stack_a = malloc(sizeof(t_list *));
    stack_b = malloc(sizeof(t_list *));
    if (!stack_a || !stack_b)
    {
        // Handle memory allocation errors
        if (!stack_a)
            free(stack_a);
        if (!stack_b)
            free(stack_b);
        return_error("Error\n");
    }
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, ac, av);
	start_sort(stack_a, stack_b);
	ft_free_stack_content(stack_a);
	ft_free_stack_content(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

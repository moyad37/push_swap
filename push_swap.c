/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/07 13:34:46 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	init_stack(t_list **stack_a, int ac, char **av)
{
	char	**str;
    //t_list *new;
    int hm;
	int		i;

    str = NULL;
	i = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		//printf("after split\n");
        // for (size_t j = 0; str[j]; j++)
        //     printf("test = %s\n", str[j]);
		while (str[i])
		{
            //new = ft_lstnew(ft_atoi(str[i]));
		    //printf("in while\n");
            hm = ft_atoi(str[i]);
            //printf("hm = %d\n", hm);
			ft_lstadd_back(stack_a, ft_lstnew(hm));
		    //printf("after list1\n");
            i++;
		}
		free(str);
	}
	else
	{
		//printf("elseeee\n");
		i = 1;
		while (i < ac)
		{
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i])));
		    //printf("after list2\n");
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	//char **arg_temp;
	t_list **stack_a;
	t_list **stack_b;
	if (ac < 2)
		return (1);
	check_args(ac, av);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
	if(!stack_a || !stack_b)
	    return (0);
	init_stack(stack_a, ac, av);
	start_sort(stack_a, stack_b);
	return (0);
}
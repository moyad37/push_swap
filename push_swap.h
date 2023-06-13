/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/13 13:46:08 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/include/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
typedef struct s_list
{
struct s_list		*next;
int					index;
int					flag;
int					nb;
void				*content;
}					t_list;
*/
typedef struct s_sort
{
	int				max;
	int				min;
	int				mid;
}					t_sort;

typedef struct s_list
{
	int				value;
	int				flag;
	int				index;
	struct s_list	*next;
}					t_list;

/////////////////////////////////////////
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
//////////////////////////////////////////////

//static void    init_stack(t_list **stack_a, int ac, char **av);
int					ft_check_doupple(char **str, int n);
void				check_args(int ac, char **av);
void				return_error(char *str);
int					ft_is_number(char *n);
long				ft_atol(const char *str);
int					check_sorted(t_list **stack);
void				free_stack(t_list **stack);
void				start_sort(t_list **stack_a, t_list **stack_b);
void				sort_2(t_list **stack);
//static int	operation(int a, int b, int c);
void				sort_3(t_list **stack);
void				sort_4(t_list **stack_a, t_list **stack_b);
void				sort_5(t_list **stack_a, t_list **stack_b);
int					find_min_value(t_list *stack);
int					find_index_of_min(t_list *stack, int min);
void				get_min_to_top(t_list **stack_a, int top_index);
t_list				*get_min(t_list **stack);
t_list				*get_max(t_list **stack);
int					count_lst(t_list **stack);
void				set_index(t_list **stack_a);
int					a_is_sorted(t_list **stack_a, int count);
void				hard_sort(t_list **stack_a, t_list **stack_b);
///Rotate
//static void rotate(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);

////revers_rotate
//static void revers_rotate(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

/////swap
//static void swap(t_list **stack);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);

////push
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);

#endif
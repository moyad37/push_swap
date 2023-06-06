/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 14:43:41 by mmanssou         ###   ########.fr       */
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
struct s_list	*next;
int				index;
int				flag;
int				nb;
void			*content;
}					t_list;
*/


typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
}					t_list;


/////////////////////////////////////////
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int	ft_lstsize(t_list *lst);
//////////////////////////////////////////////


//static void    init_stack(t_list **stack_a, int ac, char **av);
int ft_check_doupple(char **str, int n);
void check_args(int ac, char **av);
void return_error(char *str);
int ft_is_number(char *n);
long	ft_atol(const char *str);
int check_sorted(t_list **stack);
void	free_stack(t_list **stack);
void    start_sort(t_list **stack_a, t_list **stack_b);




/////Rotate
static void rotate(t_list **stack);


/////swap
static void swap(t_list **stack);
void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);

/////////////////////////////
void print_list(t_list *list);
///////////////////////////7
#endif
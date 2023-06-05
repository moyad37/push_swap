
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/include/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>



// typedef struct s_list
// {
// 	struct s_list	*ptr;
// 	int				index;
// 	int				flag;
// 	int				nb;
// 	void			*content;
// }					t_list;


typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
}					t_list;


int ft_check_doupple(char **str, int n);
void check_args(int ac, char **av);
void return_error(char *str);
int ft_is_number(char *n);
long	ft_atol(const char *str);

static void    init(t_list **stack_a, int ac, char **av);
#endif
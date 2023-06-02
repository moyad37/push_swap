
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//# include "./libft/include/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>



typedef struct s_list
{
	struct s_list	*ptr;
	int				index;
	int				flag;
	int				nb;
	void			*content;
}					t_list;


#endif
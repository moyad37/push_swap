#include "push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void return_error(char *str)
{
    ft_putendl_fd(str, 1);
    exit(0);
}
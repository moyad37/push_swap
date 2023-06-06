/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <unistd.h>

static int	zehler(long int n);
static char	*ft_putnbr(long int n, char *my);

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*my;

	size = zehler((long int)n);
	if (n < 0)
		size += 1;
	my = (char *)malloc(sizeof(char) * (size + 1));
	if (!my)
		return (NULL);
	my = ft_putnbr((long int)n, my);
	*my = '\0';
	return (my - size);
}

static char	*ft_putnbr(long int n, char *my)
{
	if (n < 0)
	{
		*my++ = '-';
		my = ft_putnbr(-n, my);
	}
	else if (n > 9)
	{
		my = ft_putnbr(n / 10, my);
		my = ft_putnbr(n % 10, my);
	}
	else
	{
		*my = n + '0';
		my++;
	}
	return (my);
}

static int	zehler(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

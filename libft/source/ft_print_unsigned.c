/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	zehler(unsigned int n);

char	*ft_unsigned_itoa(unsigned int n)
{
	int		size;
	char	*my;

	size = zehler(n);
	my = (char *)malloc(sizeof(char) * (size + 1));
	if (!my)
		return (NULL);
	my[size] = '\0';
	while (n != 0)
	{
		my[size - 1] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (my);
}

static int	zehler(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int n)
{
	int		result;
	char	*my;

	result = 0;
	if (n == 0)
		result += write(1, "0", 1);
	else
	{
		my = ft_unsigned_itoa(n);
		result += ft_print_string(my);
		free(my);
	}
	return (result);
}

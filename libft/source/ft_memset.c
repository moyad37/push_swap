/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*f;

	f = b;
	while (len > 0)
	{
		*f = (unsigned char)c;
		len--;
		f++;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[50];

	strcpy(str, "Hello I am MOOOOO");
	puts(str);
	ft_memset(str, 'l', 5);
	puts(str);
	return (0);
}
*/

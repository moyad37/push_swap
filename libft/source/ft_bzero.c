/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*f;

	f = b;
	while (n > 0)
	{
		*f = '\0';
		n--;
		f++;
	}
}
/*
int	main(void)
{
	char	str[50];

 
	strcpy(str, "Hello I am MOOOOO");
	puts(str);
	ft_bzero(str + 5, 6);
	puts(str);
	return (0);
}
*/

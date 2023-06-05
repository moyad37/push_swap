/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:41 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/02 14:07:51 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

//The function takes a single argument
int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		ch -= 32;
	}
	return (ch);
}
/*
int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, ft_toupper(c));
	c = 'D';
	printf("\n%c -> %c", c, ft_toupper(c));
	c = '9';
	printf("\n%c -> %c", c, ft_toupper(c));
	return (0);
}
*/

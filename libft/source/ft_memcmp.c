/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(str1 + i) != *(unsigned char *)(str2 + i)))
			return (*(unsigned char *)(str1 + i) - *(unsigned char *)(str2
					+ i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[15];
	char	str2[15];
	int		ret;

	memcpy(str1, "abc", 6);
	memcpy(str2, "ABC", 6);
	ret = ft_memcmp(str1, str2, 5);
	printf("%d", ret);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	dest[50];

	//const char src[50] = "Servus";
	strcpy(dest, "Hallooo");
	printf("Before memcpy dest = %s\n", dest);
	//ft_memcpy(dest , src, sizeof(src));
	ft_memcpy(((void *)0), "segfaulter tu dois", 17);
	// char *met;
	// met = ft_memcpy(((void*)0), "segfaulter tu dois", 17);
	printf("After memcpy dest = %s\n", dest);
	return (0);
}
*/

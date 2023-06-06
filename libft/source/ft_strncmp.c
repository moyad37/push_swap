/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n > 0) && (*s1 == *s2) && (*s1 != '\0'))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
int	main(void)
{
	char	str1[15];
	char	str2[15];
	int		ret;
	int		bo;

	strcpy(str1, "\200");
	strcpy(str2, "\0");
	ret = ((strncmp(str1, str2, 1) > 0) ? 1 : ((strncmp(str1, str2, 1) < 0) ?
				-1 : 0));
	bo = ((ft_strncmp(str1, str2, 1) > 0) ? 1 : ((ft_strncmp(str1, str2,
						1) < 0) ? -1 : 0));
	if(ret == bo)
		printf("hmm");
	printf("%d", ret);
	printf("\n");
	printf("%d", bo);
	// char *s1 = "\200";
	// char *s2 = "\0";
	// int i1 = ((strncmp(s1, s2, 1) > 0) ? 1 : ((strncmp(s1, s2, 1) < 0) ?
				-1 : 0));
	// int i2 = ((ft_strncmp(s1, s2, 1) > 0) ? 1 : ((ft_strncmp(s1, s2,
						1) < 0) ? -1 : 0));
	// if (i1 == i2)
	// 	printf("hey");
	// printf("pay");
	return (0);
}
*/

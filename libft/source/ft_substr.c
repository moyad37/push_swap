/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*my;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	my = malloc(sizeof(char) * (len + 1));
	if (!my)
		return (0);
	ft_strlcpy(my, s + start, len + 1);
	return (my);
}
/*
int	main(void)
{
	char	*str;
	size_t	size;
	char	*ret;

    str = "01234";
	size = 10;
	ret = substr(str, 10, size);
	if (strncmp(ret, "", 1))
	{
		printf("strncmp");
	}
	free(ret);
	printf("Fertig");
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:43 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/04 09:02:43 by mmanssou         ###   ########.fr       */
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

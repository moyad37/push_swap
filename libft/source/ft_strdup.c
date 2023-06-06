/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*my;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (s1[size])
	{
		size++;
	}
	my = malloc(sizeof(char) * (size + 1));
	if (!my)
		return (NULL);
	while (s1[i])
	{
		my[i] = s1[i];
		i++;
	}
	my[i] = '\0';
	return (my);
}

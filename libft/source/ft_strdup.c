/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:02:42 by mmanssou          #+#    #+#             */
/*   Updated: 2022/10/11 11:03:36 by mmanssou         ###   ########.fr       */
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

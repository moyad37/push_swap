/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:51:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		trim_start(char const *s1, char const *set);
int		trim_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	int		dif;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	s = trim_start(s1, set);
	e = trim_end(s1, set);
	dif = e - s + 1;
	if (s > e)
		dif = 0;
	new = (char *)malloc((dif + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, &s1[s], dif);
	new[dif] = '\0';
	return (&new[0]);
}

int	trim_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j++;
			i = -1;
		}
		i++;
	}
	return (j);
}

int	trim_end(char const *s1, char const *set)
{
	size_t	i;
	int		j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i--;
			j = -1;
		}
		j++;
	}
	return (i);
}

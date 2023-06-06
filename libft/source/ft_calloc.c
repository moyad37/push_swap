/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/06 13:52:48 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	if (nitems == __SIZE_MAX__ || size == __SIZE_MAX__)
		return (NULL);
	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	p = malloc(nitems * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nitems);
	return (p);
}
/*
int main () {
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
   free( a );
   
   return(0);
}
*/

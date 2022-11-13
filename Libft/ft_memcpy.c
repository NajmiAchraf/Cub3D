/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:52:14 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 22:09:13 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	s = (char *) src;
	d = (char *) dst;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
int	main(void)
{
	const char	src[50] = "http://www.tutorialspoint.com";
	char		dest[50];

	strcpy(dest, "Heloooo!!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	strcpy(dest, "Heloooo!!!");
	printf("Before ft_memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("After ft_memcpy dest = %s\n", dest);
	return (0);
}
*/

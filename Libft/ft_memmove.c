/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:23:44 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 17:29:44 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*firsts;
	char	*firstd;
	char	*lasts;
	char	*lastd;

	if (!dst && !src)
		return (0);
	firsts = (char *) src;
	firstd = (char *) dst;
	lasts = firsts + (len - 1);
	lastd = firstd + (len - 1);
	if (firstd < firsts)
		while (len-- > 0)
			*firstd++ = *firsts++;
	else
		while (len-- > 0)
			*lastd-- = *lasts--;
	return (dst);
}

/*
int	main(void)
{
	char dest[] = "123456";

	strcpy(dest, "123456");
	printf("Before dest = %s \n", dest);
	memmove(&dest[3], dest, 4);
	//memmove(dest, &dest[3], 4);
	printf("After memmove dest = %s    ", dest);
	strcpy(dest, "123456");
	ft_memmove(&dest[3], dest, 4);
	//ft_memmove(dest, &dest[3], 4);
	printf("After ft_memmove dest = %s \n", dest);
	return (0);
}
*/

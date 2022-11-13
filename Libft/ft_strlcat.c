/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:49:31 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 17:37:09 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	if (dstsize > dstlen + 1)
	{
		while (*dst && dstsize > 0)
		{
			dst++;
			dstsize--;
		}
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst++ = '\0';
	}
	return (dstlen + srclen);
}

/*
int	main(void)
{
	printf("\n=> %zu\n", ft_strlcat("123456789", "jnjn5", 8));
	printf("\n=> %zu\n", strlcat("123456789", "jnjn5", 8));
	return (0);
}
*/

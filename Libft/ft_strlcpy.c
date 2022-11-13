/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:10:08 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:46:54 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src,	size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

/*
int	main(void)
{
	char	dst[30];
	char	src[30];

	strcpy(dst, "abcdef");
	strcpy(src, "123456");
	printf("\nft_strlcpy => %zu		", ft_strlcpy(dst, src, 6));
	printf("dst => %s\n", dst);
	strcpy(dst, "abcdef");
	strcpy(src, "123456");
	printf("\nstrlcpy => %zu		", strlcpy(dst, src, 6));
	printf("dst => %s\n\n", dst);
	return (0);
}
*/

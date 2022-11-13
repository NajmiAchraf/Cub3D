/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:07:43 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:46:22 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	a;

	i = ft_strlen(dest);
	a = 0;
	while (src[a] != '\0')
	{
		dest[i + a] = src[a];
		a++;
	}
	dest[i + a] = '\0';
	return (dest);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	cat = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!cat)
		return (NULL);
	ft_strcpy(cat, s1);
	ft_strcat(cat, s2);
	return (cat);
}

/*
int	main(void)
{
	char	dst[30];
	char	src[30];

	strcpy(dst, "abcdef");
	strcpy(src, "123456");
	printf("\nft_strjoin => %s		\n\n", ft_strjoin(dst, src));
	return (0);
}
*/

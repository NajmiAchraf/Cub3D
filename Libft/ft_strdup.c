/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:26:47 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:40:50 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		src_len;

	if (!s1)
		return (0x0);
	src_len = ft_strlen(s1);
	dest = malloc((src_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest = ft_strcpy(dest, s1);
	return (dest);
}

/*
int	main(int argc, char **argv)
{
	(void) argc;
	printf("ft_strdup(%s) => %s\n", argv[1], ft_strdup(argv[1]));
	printf("strdup(%s) => %s\n", argv[1], strdup(argv[1]));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:26:49 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:34:44 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i != n)
		return (str1[i] - str2[i]);
	return (0);
}

/*
int	main(void)
{
	char str1[] = {0, 0, 127, 0};
	char str2[] = {0, 0, 42, 0};
	int		ret;

	ret = ft_memcmp(str1, str2, 4);
	if (ret < 0)
	{
		printf("str1 is less than str2\n");
	}
	else if (ret > 0)
	{
		printf("str2 is less than str1\n");
	}
	else
	{
		printf("str1 is equal to str2\n");
	}
	printf("Value returned by ft_memcmp() is:  %d\n", ret);
	ret = 0;
	ret = memcmp(str1, str2, 4);
	if (ret < 0)
	{
		printf("str1 is less than str2\n");
	}
	else if (ret > 0)
	{
		printf("str2 is less than str1\n");
	}
	else
	{
		printf("str1 is equal to str2\n");
	}
	printf("Value returned by memcmp() is:  %d\n", ret);
	return (0);
}
*/

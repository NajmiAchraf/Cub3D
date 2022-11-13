/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:31:14 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/24 16:32:03 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
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
	char	str1[15];
	char	str2[15];
	int		ret;

	strcpy(str1, "ABC");
	strcpy(str2, "ABCDdbdb");
	ret = ft_strncmp(str1, str2, 4);
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
	printf("Value returned by ft_strncmp() is:  %d\n", ret);
	ret = 0;
	ret = strncmp(str1, str2, 4);
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
	printf("Value returned by strncmp() is:  %d\n", ret);
	return (0);
}
*/

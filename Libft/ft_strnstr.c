/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:12:13 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:48:08 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	str = (char *) haystack;
	if (*needle == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[50];
	char	to_find[50];

	strcpy(str, "ghost every ");
	strcpy(to_find, "t ");
	puts(ft_strnstr(str, to_find, 6));
	strcpy(str, "ghost every ");
	strcpy(to_find, "t ");
	puts(strnstr(str, to_find, 6));
	return (0);
}
*/

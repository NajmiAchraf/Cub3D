/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:46:10 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:48:50 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	result = NULL;
	if (s1 && set)
	{
		while (*s1 && ft_strchr(set, *s1) != NULL)
			s1++;
		len = ft_strlen(s1);
		while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]) != NULL)
			len--;
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (!result)
			return (0);
		ft_strlcpy(result, s1, len + 1);
		result[len] = '\0';
	}
	return (result);
}

/*
int	main(void)
{
	char const 	s1[50] = "3213|21hello32|1321";
	char const 	set[6] = "123";

	printf("\n trim = %s", ft_strtrim(s1, set));
	return (0);
}
*/

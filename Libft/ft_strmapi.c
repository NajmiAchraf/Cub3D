/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:11:17 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:47:25 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	len;
	size_t	i;

	if (s == 0)
		return (NULL);
	len = ft_strlen(s);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*
char	f(unsigned int i, char c)
{
	(void)c;
	(void)i;
	return ('j');
}

int	main(void)
{
	char	str1[] = "abcdef";
	char*	str2;

	str2 = ft_strmapi(str1, *f);
	printf("%s\n", str2);
}
*/

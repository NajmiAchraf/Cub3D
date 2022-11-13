/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:06:28 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/21 13:28:21 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	check;
	char	*out;
	size_t	len;

	check = (char) c;
	out = (char *) s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (*out == check)
			return (out);
		out++;
		len--;
	}
	if (len == 0 && *out == check)
		return (out);
	return (NULL);
}

/*
int	main(void)
{
	const char	str[] = "http://www.tutorialspoint.com";
	const char	ch = '/';
	char		*ret;

	ret = ft_strchr(str, ch);
	printf("\nString after |%c| is - |%s|\n", ch, ret);
	printf("String before |%s|\n\n", str);
	ret = strchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	printf("String before |%s|\n\n", str);
	return (0);
}
*/

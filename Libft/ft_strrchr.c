/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:57:13 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:48:26 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*out;
	size_t			i;
	int				j;

	out = (unsigned char *) s;
	i = 0;
	j = -1;
	while (i < ft_strlen(s))
	{
		if (*out == (unsigned char) c)
			j = (int) i;
		out++;
		i++;
	}
	if (j != -1)
	{
		out = (unsigned char *) s;
		while (j-- > 0)
			out++;
		return ((char *) out);
	}
	if (i == ft_strlen(s) && *out == (unsigned char) c)
		return ((char *) out);
	return (NULL);
}

/*
int	main(void)
{
	const char	str[] = "http://www.tutorialspoint.com";
	const char	ch = 't';
	char		*ret;

	ret = ft_strrchr(str, ch);
	printf("\nString after |%c| is - |%s|\n", ch, ret);
	printf("String before |%s|\n\n", str);
	ret = strrchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	printf("String before |%s|\n\n", str);
	return (0);
}
*/

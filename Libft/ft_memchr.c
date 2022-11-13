/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:59:06 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:30:44 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	check;
	unsigned char	*out;
	size_t			i;

	check = (unsigned char) c;
	out = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (out[i] == check)
			return (out + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char str[] = {0, 1, 2 ,3 ,4 ,5};
	//const char	ch = '2';
	char		*ret;

	ret = ft_memchr(str, 0, 1);
	printf("|%s|\n", ret);
	//printf("String before |%s|\n\n", str);

	ret = memchr(str, 0, 1);
	printf("|%s|\n", ret);
	//printf("String before |%s|\n\n", str);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:41:55 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/19 19:59:45 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
int	main(void)
{
	char	str[50];
	int		a;

	strcpy(str, "This is string.h");
	puts(str);
	a = 0;
	while (a <= 20)
	{
		strcpy(str, "This is string.h");
		ft_memset(str, '$', a);
		printf("(%d)	ft_memset => %s	", a, str);
		strcpy(str, "This is string.h");
		memset(str, '$', a);
		printf("memset => %s\n", str);
		a++;
	}
	int	d;

	ft_memset(&d, 127, sizeof(int));
	printf("%d\n", d);
	return (0);
}
*/

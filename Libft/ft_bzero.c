/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:42:59 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:22:27 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
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
		ft_bzero(str, a);
		printf("(%d)	ft_bzero => %s	", a, str);
		strcpy(str, "This is string.h");
		bzero(str, a);
		printf("bzero => %s\n", str);
		a++;
	}
	return (0);
}
*/

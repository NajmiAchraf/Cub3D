/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:08:58 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:50:18 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32;
	return (c);
}

/*
int	main(void)
{
	int	a;

	a = 97;
	while (a <= 122)
	{
		printf("(%d) (%c)	ft_toupper => %c	", a, a, ft_toupper(a));
		printf("toupper => %c\n", toupper(a));
		a++;
	}
	return (0);
}
*/

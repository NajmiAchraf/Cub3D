/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:33:40 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:49:49 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c + 32;
	return (c);
}

/*
int	main(void)
{
	int	a;

	a = 65;
	while (a <= 90)
	{
		printf("(%d) (%c)	ft_tolower => %c	", a, a, ft_tolower(a));
		printf("tolower => %c\n", tolower(a));
		a++;
	}
	return (0);
}
*/

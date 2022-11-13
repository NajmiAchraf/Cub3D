/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:11:05 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:25:50 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (!('0' <= c && c <= '9')
		&& !('A' <= c && c <= 'Z')
		&& !('a' <= c && c <= 'z'))
	{
		return (0);
	}
	return (1);
}
/*
int	main(void)
{
	int	a;

	a = 0;
	while (a <= 127)
	{
		printf("(%d) (%c)	ft_isalnum => %d	", a, a, ft_isalnum(a));
		printf("isalnum => %d\n", isalnum(a));
		a++;
	}
	return (0);
}
*/

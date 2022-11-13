/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:45:32 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:26:39 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (!(0 <= c && c <= 127))
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
	while (a <= 255)
	{
		printf("(%d) (%c)	ft_isascii => %d	", a, a, ft_isascii(a));
		printf("isascii => %d\n", isascii(a));
		a++;
	}
	return (0);
}
*/

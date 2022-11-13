/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:28:06 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:27:30 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (!(32 <= c && c <= 126))
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
		printf("(%d) (%c)	ft_isprint => %d	", a, a, ft_isprint(a));
		printf("isprint => %d\n", isprint(a));
		a++;
	}
	return (0);
}
*/

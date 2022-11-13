/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:03:06 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:26:58 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (!('0' <= c && c <= '9'))
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
		printf("(%d) (%c)	ft_isdigit => %d	", a, a, ft_isdigit(a));
		printf("isdigit => %d\n", isdigit(a));
		a++;
	}
	return (0);
}
*/

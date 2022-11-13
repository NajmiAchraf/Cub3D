/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:00:22 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:26:19 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z'))
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
		printf("(%d) (%c)	ft_isalpha => %d	", a, a, ft_isalpha(a));
		printf("isalpha => %d\n", isalpha(a));
		a++;
	}
	return (0);
}
*/

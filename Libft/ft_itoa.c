/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:43:12 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/19 14:33:37 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(long value, int i)
{
	long	l;

	l = 1;
	while (value > 9)
	{
		l++;
		value /= 10;
	}
	return (l + i);
}

static char	*process(char *out, long nbr, int i)
{
	while (i >= 0)
	{
		if (0 <= (nbr % 10) && (nbr % 10) < 10)
			out[i] = nbr % 10 + '0';
		i--;
		if (i == -1 || out[i] == '-')
			break ;
		nbr /= 10;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	char	*out;
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		i = 1;
	}
	i = get_int_len(nbr, i);
	out = ft_calloc(i + 1, sizeof(char));
	if (!out)
		return (NULL);
	if (n < 0)
		out[0] = '-';
	i -= 1;
	return (process(out, nbr, i));
}

/*
int	main(void)
{
	char	*str;
	int		val;

	val = 1234567890;
	str = ft_itoa(val);
	printf("Int value = %d, String value = %s\n", val, str);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:18:34 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/21 15:07:30 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	i;

	if (s == 0)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}

/*
void	f(unsigned int i, char *s)
{
	*s -= 32;
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "abcd";

	ft_striteri(str, f);
	printf("%s\n", str);
}
*/

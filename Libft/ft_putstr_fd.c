/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:07:37 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 19:25:27 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s && fd >= 0)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("file", O_CREAT | O_RDWR);
	ft_putstr_fd("hello == > achraf\n", fd);
	return (0);
}
*/

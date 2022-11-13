/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:00:34 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:37:54 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	if (0 <= nbr && nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
}

/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("file", O_CREAT | O_RDWR);
	ft_putnbr_fd(1234567890, fd);
	return (0);
}
*/

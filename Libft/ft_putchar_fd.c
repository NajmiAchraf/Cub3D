/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:38:40 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 21:10:10 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("file", O_CREAT | O_RDWR);
	ft_putchar_fd('l', fd);
	return (0);
}
*/

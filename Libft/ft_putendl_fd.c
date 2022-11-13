/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:51:43 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:37:17 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("file", O_CREAT | O_RDWR);
	ft_putstr_fd("hello == > heho", fd);
	return (0);
}
*/

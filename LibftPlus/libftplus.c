/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftplus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:00:07 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/27 17:43:30 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftplus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

int	ft_strch(char *src, char c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
}

void	show_help(void)
{
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
	ft_putstr_fd("| Usage : ./cub3D [Path of MAP]\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
	ft_putstr_fd("|\tPath of MAP :\t\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\trelative : maps/map*.cub\t\t\t\t|\n", 1);
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
}

void	show_control(void)
{
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
	ft_putstr_fd("| Controls :\t\t\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\tMove : W / S / A / D   \t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\tRotate : Left / Right | Mouse\t\t\t\t\t|\n", 1);
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
}

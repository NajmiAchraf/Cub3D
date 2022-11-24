/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:55:23 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/24 15:03:40 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_fd(int fd)
{
	if (fd < 0)
	{
		printf("Error\nfrom fd");
		exit(1);
	}	
}

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

void	check_extension(int ac, char **av)
{
	char	*str;

	if (ac != 2)
		ft_error("Error from arg");
	str = ft_strrchr(av[1], '.');
	if (str)
	{
		if (ft_strcmp(str, ".cub"))
			ft_error("Error from arg");
	}
}

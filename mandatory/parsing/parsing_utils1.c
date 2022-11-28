/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:55:23 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/28 10:48:37 by sriyani          ###   ########.fr       */
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
	{
		ft_error("Error from arg");
		show_help();
	}
	str = ft_strrchr(av[1], '.');
	if (str)
	{
		if (ft_strcmp(str, ".cub"))
			ft_error("Error from arg");
	}
}

void	ft_atoi_plus1(int k, int i, char *ptr)
{
	if (k != i || i > 4)
		ft_error("Error from atoi 1");
	free(ptr);
}

int	ft_atoi_plus(char *str)
{
	int		res;
	int		i;
	int		k;
	char	*ptr;

	i = 0;
	res = 0;
	k = 0;
	ptr = NULL;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ','
			&& str[i] != ' ' && str[i] != '+')
			ft_error("Error from atoi");
		i++;
	}
	ptr = ft_strtrim(str, " ");
	i = 0;
	if (ptr[i] == '+')
		i++;
	k = count_plus(ptr);
	while (ptr[i] >= '0' && ptr[i] <= '9')
		res = res * 10 + ptr[i++] - '0';
	ft_atoi_plus1(k, i, ptr);
	return (res);
}

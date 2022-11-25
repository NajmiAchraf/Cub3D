/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:35:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/24 17:18:47 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:35:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/10 13:51:59 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_help(void)
{
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
	ft_putstr_fd("| Usage : ./fractol [Window size] [Iteration]", 1);
	ft_putstr_fd(" [Fractal number] {Option} |\n", 1);
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
	ft_putstr_fd("|\tWindow size :\t\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\tFrom 200 to 1000\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\tIteration :\t\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\tFrom 50 to 500\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\tFractal number :\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\t1 : Mandelbrot\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\t2 : Julia set manual input\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\t\tOption :\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\t\t\t[x] Real axe coordinate\t\t\t|\n", 1);
	ft_putstr_fd("|\t\t\t\t[z] Complex axe coordinate\t\t|\n", 1);
	ft_putstr_fd("|\t\t3 : Mandelbrot^n\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\t\tOption : [n] From 3 to 5\t\t\t|\n", 1);
	ft_putstr_fd("|\t\t4 : Julia set auto-mouse input\t\t\t\t|\n", 1);
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("--------------------------\n", 1);
}

void	show_control(void)
{
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
	ft_putstr_fd("| Controls :\t\t\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\tMove : Up / Down / Left / Right\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\tZoom :\t\t\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\t\tMouse Scroll by tracking the mouse pointer\t\t|\n", 1);
	ft_putstr_fd("|\t\tPlus (+) / Minus (-) by tracking the center\t\t|\n", 1);
	ft_putstr_fd("|\tColor : C\t\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("|\tReset values : Space\t\t\t\t\t\t|\n", 1);
	ft_putstr_fd("----------------------------------------------", 1);
	ft_putstr_fd("---------------------------\n", 1);
}

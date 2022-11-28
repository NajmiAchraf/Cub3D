/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:12:06 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/28 10:35:19 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_file_no(t_var *var, int i, int fd)
{
	int	num;

	var->pars->no = ft_split(var->pars->hold[i], ' ');
	num = num_str(var->pars->no);
	if (var->pars->no[0][0] != 'N' || ft_strcmp(var->pars->no[0], "NO") != 0)
		ft_error("Error from Direction NO");
	fd = open(var->pars->no[1], O_RDONLY, 0644);
	if (fd < 0 || var->pars->nn == 1 || num != 2)
		ft_error("Error from fd NO");
	var->pars->nn = 1;
	close (fd);
	return (0);
}

int	check_file_so(t_var *var, int i, int fd)
{
	int	num;

	var->pars->so = ft_split(var->pars->hold[i], ' ');
	num = num_str(var->pars->so);
	if (var->pars->so[0][0] != 'S' || ft_strcmp(var->pars->so[0], "SO") != 0)
		ft_error("Error from Direction SO");
	fd = open(var->pars->so[1], O_RDONLY, 0644);
	if (fd < 0 || var->pars->ss == 1 || num != 2)
		ft_error("Error from fd SO");
	var->pars->ss = 1;
	close (fd);
	return (0);
}

int	check_file_we(t_var *var, int i, int fd)
{
	int	num;

	var->pars->we = ft_split(var->pars->hold[i], ' ');
	num = num_str(var->pars->we);
	if (var->pars->we[0][0] != 'W' || ft_strcmp(var->pars->we[0], "WE") != 0)
		ft_error("Error from Direction WE");
	fd = open(var->pars->we[1], O_RDONLY, 0644);
	if (fd < 0 || var->pars->ww == 1 || num != 2)
		ft_error("Error from fd WE");
	var->pars->ww = 1;
	close (fd);
	return (0);
}

int	check_file_ea(t_var *var, int i, int fd)
{
	int	num;

	var->pars->ea = ft_split(var->pars->hold[i], ' ');
	num = num_str(var->pars->ea);
	if (var->pars->ea[0][0] != 'E' || ft_strcmp(var->pars->ea[0], "EA") != 0)
		ft_error("Error from Direction EA");
	fd = open(var->pars->ea[1], O_RDONLY, 0644);
	if (fd < 0 || var->pars->ee == 1 || num != 2)
		ft_error("Error from fd EA");
	var->pars->ee = 1;
	close (fd);
	return (0);
}

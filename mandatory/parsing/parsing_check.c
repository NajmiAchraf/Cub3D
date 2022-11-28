/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:11:41 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/28 10:22:28 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file_f(t_var *var, int i)
{
	var->pars->f = ft_split(var->pars->hold[i], ',');
	check_f_range(var, var->pars->hold[i]);
	if (var->pars->ff == 1)
		ft_error("Error from FF");
	var->pars->ff = 1;
	return (0);
}

int	check_file_c(t_var *var, int i)
{
	var->pars->c = ft_split(var->pars->hold[i], ',');
	check_c_range(var, var->pars->hold[i]);
	if (var->pars->cc == 1)
		ft_error("Error from CC");
	var->pars->cc = 1;
	return (0);
}

int	check_file2(t_var *var, int i, int j)
{
	int	fd;

	fd = 0;
	if ((var->pars->hold[i][j] == 'N' && var->pars->hold[i][j + 1] == 'O'))
	{
		if (!check_file_no(var, i, fd))
			return (0);
	}
	if (var->pars->hold[i][j] == 'S' && var->pars->hold[i][j + 1] == 'O')
	{
		if (!check_file_so(var, i, fd))
			return (0);
	}
	if (var->pars->hold[i][j] == 'W' && var->pars->hold[i][j + 1] == 'E')
	{
		if (!check_file_we(var, i, fd))
			return (0);
	}
	if (var->pars->hold[i][j] == 'E' && var->pars->hold[i][j + 1] == 'A')
	{
		if (!check_file_ea(var, i, fd))
			return (0);
	}
	return (1);
}

int	check_file3(t_var *var, int i, int j, int len)
{
	if (var->pars->hold[i][j] == 'F')
	{
		if (!check_file_f(var, i))
			return (0);
	}
	if (var->pars->hold[i][j] == 'C')
	{
		if (!check_file_c(var, i))
			return (0);
	}
	if (!var->pars->map1 && (var->pars->hold[i][j] == '1'
		|| var->pars->hold[i][j] == ' '))
	{
		if (!fill_map(var, i, len))
			return (0);
	}
	if (!var->pars->nn || !var->pars->ss || !var->pars->ww
		|| !var->pars->ee || !var->pars->ff || !var->pars->cc
		|| !var->pars->map1)
		ft_error("Error element not found");
	return (1);
}

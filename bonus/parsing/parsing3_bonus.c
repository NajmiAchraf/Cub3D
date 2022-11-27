/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:30:29 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/25 15:49:17 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	valid_map_column(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->pars->map[i])
	{
		j = 0;
		while (var->pars->map[i][j] == ' ')
			j++;
		while (var->pars->map[i][j])
		{
			if (var->pars->map[i][j] != '1')
				ft_error("error from column");
			break ;
		}
		i++;
	}
	valid_map_column1(var);
}

void	valid_map_line1(t_var *var, int i)
{
	int	j;

	j = 0;
	while (var->pars->map[i -1][j])
	{
		if (var->pars->map[i -1][j] != '1' && var->pars->map[i -1][j] != ' ')
			ft_error("Error from valid 3");
		j++;
	}
	if (!ft_strchr(var->pars->map[i -1], '1') && var->pars->map[i] == NULL)
		ft_error("Error from valid 4");
}

void	valid_map_line(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->pars->map[i])
	{
		if (var->pars->map[i][0] == '\0')
			ft_error("Error from valid 1");
		i++;
	}
	j = 0;
	while (var->pars->map[0][j])
	{
		if (var->pars->map[0][j] != '1' && var->pars->map[0][j] != ' ')
			ft_error("Error from valid 2");
		j++;
	}
	valid_map_line1(var, i);
	valid_map_column(var);
}

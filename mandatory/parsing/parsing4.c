/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:33:38 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/28 14:40:44 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_surrounded1(t_var *var, int i)
{
	int	j;

	j = 0;
	while (var->pars->map[i][j])
	{
		if (var->pars->map[i][j] == '0' || var->pars->map[i][j] == 'S'
			|| var->pars->map[i][j] == 'N'
			|| var->pars->map[i][j] == 'W' || var->pars->map[i][j] == 'E')
		{
			if ((var->pars->map[i - 1][j] == '\0'
				|| var->pars->map[i - 1][j] == ' ')
				|| (var->pars->map[i + 1][j] == '\0'
				|| var->pars->map[i + 1][j] == ' '))
				ft_error("Error from map_surrounded");
			if ((var->pars->map[i][j - 1] == '\0'
				|| var->pars->map[i][j - 1] == ' ')
				|| (var->pars->map[i][j + 1] == '\0'
				|| var->pars->map[i][j + 1] == ' '))
				ft_error("Error from map_surrounded2");
		}
		j++;
	}
}

void	check_map_surrounded(t_var *var)
{
	int	i;

	i = 0;
	while (var->pars->map[i])
	{
		check_map_surrounded1(var, i);
		i++;
	}
}

void	valid_map_column1(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->pars->map[i])
	{
		j = ft_strlen(var->pars->map[i]) - 1;
		while (var->pars->map[i][j] == ' ')
			j--;
		while (var->pars->map[i][j])
		{
			if (var->pars->map[i][j] != '1')
				ft_error("error from column1");
			break ;
		}
		i++;
	}
	check_map_surrounded(var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:20:11 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/24 15:27:05 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map2(t_var *var, int i, int j)
{
	if (var->pars->map[i][j] == '0')
		var->pars->zero++;
	if (var->pars->map[i][j] == '1')
		var->pars->one++;
	if (var->pars->map[i][j] == 'N' || var->pars->map[i][j] == 'S'
		|| var->pars->map[i][j] == 'E' || var->pars->map[i][j] == 'W')
		var->pars->player++;
	if (var->pars->map[i][j] == ' ')
		var->pars->space++;
}

void	check_map(t_var *var)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (var->pars->map[i])
	{
		j = 0;
		while (var->pars->map[i][j])
		{
			check_map2(var, i, j);
			j++;
			k++;
		}
		i++;
	}
	j = var->pars->space + var->pars->player + var->pars->one + var->pars->zero;
	i = k - j;
	if (!var->pars->zero || !var->pars->one || var->pars->player != 1 || i)
		ft_error("Error from map");
	valid_map_line(var);
}

void	fill_map(t_var *var, int i, int len)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	var->pars->map = malloc(sizeof(char *) * (len - i));
	while (var->pars->hold[i])
	{
		var->pars->map[k] = var->pars->hold[i];
		k++;
		i++;
	}
	var->pars->map[k] = NULL;
	check_map(var);
}

int	num_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

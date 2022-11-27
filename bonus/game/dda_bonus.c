/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:24:20 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 18:09:20 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	set_delta(t_var *var)
{
	var->dda->len_ray = 1;
	if (var->dda->vx)
		var->dda->delta_x = var->dda->len_ray / fabs(var->dda->vx);
	else
		var->dda->delta_x = 1e30;
	if (var->dda->vy)
		var->dda->delta_y = var->dda->len_ray / fabs(var->dda->vy);
	else
		var->dda->delta_y = 1e30;
}

static void	set_pos_x(t_var *var, double pos_x)
{
	if (var->dda->vx >= 0)
	{
		var->dda->step_x = 1;
		var->dda->map_x = (int)pos_x;
		var->dda->dist_x = (var->dda->map_x + 1 - pos_x) * var->dda->delta_x;
	}
	else
	{
		var->dda->step_x = -1;
		var->dda->map_x = (int)pos_x;
		var->dda->dist_x = (pos_x - var->dda->map_x) * var->dda->delta_x;
	}
}

static void	set_pos_y(t_var *var, double pos_y)
{
	if (var->dda->vy >= 0)
	{
		var->dda->step_y = 1;
		var->dda->map_y = (int)pos_y;
		var->dda->dist_y = (var->dda->map_y + 1 - pos_y) * var->dda->delta_y;
	}
	else
	{
		var->dda->step_y = -1;
		var->dda->map_y = (int)pos_y;
		var->dda->dist_y = (pos_y - var->dda->map_y) * var->dda->delta_y;
	}
}

static void	differential_analyzer(t_var *var)
{
	while (1)
	{
		if (var->dda->dist_x < var->dda->dist_y)
		{
			var->dda->dist_x += var->dda->delta_x;
			var->dda->map_x += var->dda->step_x;
			var->dda->side = 1;
		}
		else
		{
			var->dda->dist_y += var->dda->delta_y;
			var->dda->map_y += var->dda->step_y;
			var->dda->side = 2;
		}
		if (var->pars->map[var->dda->map_y][var->dda->map_x] == '1')
			break ;
	}
}

/* Digital differential analyzer */
void	dda(t_var *var, double pos_x, double pos_y)
{
	set_delta(var);
	set_pos_x(var, pos_x);
	set_pos_y(var, pos_y);
	differential_analyzer(var);
	var->dda->dist = 0;
	var->dda->wall_x = 0;
	if (var->dda->side == 1)
	{
		var->dda->dist = (var->dda->dist_x - var->dda->delta_x);
		var->dda->wall_x = pos_y + var->dda->dist * var->dda->vy;
	}
	else if (var->dda->side == 2)
	{
		var->dda->dist = (var->dda->dist_y - var->dda->delta_y);
		var->dda->wall_x = pos_x + var->dda->dist * var->dda->vx;
	}
	var->dda->wall_x = var->dda->wall_x - (int) var->dda->wall_x;
}

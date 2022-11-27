/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:13:50 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 18:09:20 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	the_move_ad(t_var *var)
{
	double	new_x;
	double	new_y;

	if (var->ply->move[0] == KY_A || var->ply->move[0] == KY_D)
	{
		new_x = var->ply->pos_x - (var->ply->vy * var->ply->step_x);
		new_y = var->ply->pos_y + (var->ply->vx * var->ply->step_x);
		if (get_map_index(var, var->ply->pos_y, new_x) == '0')
			var->ply->pos_x = new_x;
		if (get_map_index(var, new_y, var->ply->pos_x) == '0')
			var->ply->pos_y = new_y;
	}
}

static void	the_move_sw(t_var *var)
{
	double	new_x;
	double	new_y;

	if (var->ply->move[1] == KY_S || var->ply->move[1] == KY_W)
	{
		new_x = var->ply->pos_x + (var->ply->vx * var->ply->step_y);
		new_y = var->ply->pos_y + (var->ply->vy * var->ply->step_y);
		if (get_map_index(var, var->ply->pos_y, new_x) == '0')
			var->ply->pos_x = new_x;
		if (get_map_index(var, new_y, var->ply->pos_x) == '0')
			var->ply->pos_y = new_y;
	}
}

static void	the_rotate_lr(t_var *var)
{
	if (var->ply->move[2] == KY_LEFT)
	{
		mlp_rotation_matrix(ROTATION_SPEED, &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(ROTATION_SPEED, &var->ply->plan_x, \
			&var->ply->plan_y);
	}
	else if (var->ply->move[2] == KY_RIGHT)
	{
		mlp_rotation_matrix(-ROTATION_SPEED, &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(-ROTATION_SPEED, &var->ply->plan_x, \
			&var->ply->plan_y);
	}
}

void	event(t_var *var)
{
	the_move_ad(var);
	the_move_sw(var);
	the_rotate_lr(var);
}

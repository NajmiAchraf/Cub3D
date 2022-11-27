/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_full_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:41:32 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 14:35:31 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_var *var, double x_0, double y_0, double slope, double len)
{
	double	r;
	double	x;
	double	y;

	r = 0;
	while (r < len)
	{
		x = cos(slope) * r;
		y = sin(slope) * r;
		put_pixel_to_image(var, x_0 + x, y_0 + y, CREAMY);
		r += 0.1;
	}
}


void	full_draw_squar(t_var *var, double x, double y, double size_x, double size_y, int color)
{
	for (int j = y; j < y + size_y - 1; j++)
	{
		for (int i = x; i < x + size_x - 1; i++){
			put_pixel_to_image(var, i,j, color);
		}
	}
}

void	full_draw_the_map(t_var *var)
{
	for (int y = 0; var->pars->map[y]; y++){
		for (int x = 0; var->pars->map[y][x]; x++){
			if (var->pars->map[y][x] == '1')
				full_draw_squar(var, x * SCALE, y * SCALE, SCALE, SCALE, WHITE);
			else if (var->pars->map[y][x] == '0')
				full_draw_squar(var, x * SCALE, y * SCALE, SCALE, SCALE, BLUE);
		}
	}
}

void	full_draw_player(t_var *var)
{
	full_draw_squar(var, (var->ply->pos_x * SCALE) - PLY_SIZE, (var->ply->pos_y * SCALE) - PLY_SIZE, PLY_SIZE*2, PLY_SIZE*2, GREEN);
	// Digital differential analyzer
	dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->vx, var->ply->vy); 
	draw_line(var, (var->ply->pos_x) * SCALE, (var->ply->pos_y) * SCALE, atan2(var->ply->vy, var->ply->vx), var->dda->dist * SCALE);
	// printf("x = %lf,y = %lf\n", var->ply->pos_x, var->ply->pos_y);
}

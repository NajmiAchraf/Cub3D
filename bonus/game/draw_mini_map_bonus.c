/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:50:20 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/28 15:04:01 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	draw_line(t_var *var, double slope)
{
	double	r;
	double	x;
	double	y;

	r = 0;
	while (r < var->dda->dist * SCALE)
	{
		x = cos(slope) * r;
		y = sin(slope) * r;
		put_pixel_to_image(var, POS_PLY + x, POS_PLY + y, CREAMY);
		r += 0.1;
	}
}

static void	draw_squar(t_var *var, double x, double y, int color)
{
	int	i;
	int	j;

	j = y;
	while (j < y + SCALE)
	{
		i = x;
		while (i < x + SCALE)
		{
			put_pixel_to_image(var, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_the_map(t_var *var)
{
	int	x;
	int	y;

	y = 0;
	while (var->pars->map[y])
	{
		x = 0;
		while (var->pars->map[y][x])
		{
			if (var->pars->map[y][x] == '1'
				&& ((fabs(var->ply->pos_x - x)) * SCALE) < POS_PLY
				&& ((fabs(var->ply->pos_y - y)) * SCALE) < POS_PLY)
				draw_squar(var, (x - var->ply->pos_x) * SCALE + POS_PLY, \
					(y - var->ply->pos_y) * SCALE + POS_PLY, WHITE);
			else if (var->pars->map[y][x] == '0'
				&& ((fabs(var->ply->pos_x - x)) * SCALE) < POS_PLY
				&& ((fabs(var->ply->pos_y - y)) * SCALE) < POS_PLY)
				draw_squar(var, (x - var->ply->pos_x) * SCALE + POS_PLY, \
					(y - var->ply->pos_y) * SCALE + POS_PLY, BLUE);
			x++;
		}
		y++;
	}
}

static void	draw_circle(t_var *var, int x, int y, double r)
{
	double	angle;
	double	x1;
	double	y1;

	angle = 0;
	while (angle < 360)
	{
		x1 = r * cos(angle * M_PI / 180);
		y1 = r * sin(angle * M_PI / 180);
		put_pixel_to_image(var, x + x1, y + y1, CREAMY);
		angle += 0.1;
	}
}

void	draw_player(t_var *var)
{
	double	r;

	r = 0;
	while (r < PLY_SIZE)
	{
		draw_circle(var, POS_PLY, POS_PLY, r);
		r += 0.5;
	}
	var->dda->vx = var->ply->vx;
	var->dda->vy = var->ply->vy;
	dda(var, var->ply->pos_x, var->ply->pos_y);
	if ((var->dda->dist * SCALE) > POS_PLY)
		var->dda->dist = POS_PLY / SCALE;
	draw_line(var, atan2(var->ply->vy, var->ply->vx));
}

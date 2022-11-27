/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:59:45 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 14:08:18 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_texture_color(t_tex *tex, int x, int y)
{
	int *dist;

	x = x % 64;
	dist = (int *)(tex->ptr + (y * tex->line_lenght + \
			x * (tex->bpp / 8)));
	return (*(dist));
}

static void	put_texture_to_image(t_var *var, int x, int y, double wall_y, int n)
{
	put_pixel_to_image(var, x ,y, get_texture_color(var->tex[n], \
		var->dda->wall_x * var->tex[n]->width, var->tex[n]->height * wall_y));
}

static void	raycaste_images(t_var *var, int x, int y, double wall_y)
{
	if (var->dda->side == 2 && var->dda->vy <= 0)
		put_texture_to_image(var, x, y, wall_y, 0);
	else if (var->dda->side == 2)
		put_texture_to_image(var, x, y, wall_y, 1);
	if (var->dda->side == 1 && var->dda->vx <= 0)
		put_texture_to_image(var, x, y, wall_y, 2);
	else if (var->dda->side == 1)
		put_texture_to_image(var, x, y, wall_y, 3);
}

static void	projection(t_var *var, int x)
{
	int height_line;
	int y;
	int start;
	int end;
	double wall_y;

	height_line = RESOLUTION/ var->dda->dist;
	start  = (RESOLUTION - height_line)/2;
	end  = (RESOLUTION + height_line)/2;
	y = 0;
	while (y < RESOLUTION)
	{
		if (start < y && y < end)
		{
			wall_y = (double)(y - start) / (end -start);
			raycaste_images(var, x, y, wall_y);
		}
		else if (y <= start)
			put_pixel_to_image(var, x, y, var->lx->ceiling);
		else if (y >= end)
			put_pixel_to_image(var, x, y, var->lx->floor);
		y++;
	}
}

void	raycasting(t_var *var)
{
	double	X;
	double	x;

 	x = 0;
	while (x < RESOLUTION)
	{
		X = ((2.0 * x) - RESOLUTION) / (double)RESOLUTION;
		var->ply->ray_dir_x = var->ply->vx + (X * var->ply->plan_x);
		var->ply->ray_dir_y = var->ply->vy + (X * var->ply->plan_y);
		dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->ray_dir_x, var->ply->ray_dir_y);
		projection(var, x);
		x++;
	}
}

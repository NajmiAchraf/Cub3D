/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:20:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/28 19:58:31 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_image(t_var *var, int x, int y, int color)
{
	if (x < 0 || x >= RESOLUTION || y < 0 || y >= RESOLUTION)
		return ;
	var->lx->dst = var->lx->addr + (y * var->lx->line_length + \
			x * (var->lx->bits_per_pixel / 8));
	*(unsigned int *) var->lx->dst = color;
}

static int	draw(t_var *var)
{
	mlx_destroy_image(var->lx->mlx, var->lx->img);
	var->lx->img = mlx_new_image(var->lx->mlx, RESOLUTION, RESOLUTION);
	var->lx->addr = mlx_get_data_addr(var->lx->img, &var->lx->bits_per_pixel,
			&var->lx->line_length, &var->lx->endian);
	raycasting(var);
	mlx_put_image_to_window(var->lx->mlx, var->lx->win, var->lx->img, 0, 0);
	event(var);
	return (0);
}

static void	cub3d(t_var *var)
{
	var->lx->mlx = mlx_init();
	var->lx->win = mlx_new_window(var->lx->mlx, RESOLUTION, \
			RESOLUTION, "CUB3D");
	var->lx->img = mlx_new_image(var->lx->mlx, RESOLUTION, RESOLUTION);
	var->lx->addr = mlx_get_data_addr(var->lx->img, &var->lx->bits_per_pixel,
			&var->lx->line_length, &var->lx->endian);
	fill_textures(var);
	mlx_hook(var->lx->win, ON_KEYDOWN, (1L << 0), downbind, var);
	mlx_hook(var->lx->win, ON_KEYUP, (1L << 1), upbind, var);
	mlx_hook(var->lx->win, ON_DESTROY, 0, xite, var);
	mlx_loop_hook(var->lx->mlx, draw, var);
	mlx_loop(var->lx->mlx);
}

static void	init(t_var *var)
{
	colors(var);
	player_set(var);
	var->ply->step_x = SPEED;
	var->ply->step_y = SPEED;
	var->ply->move[0] = -1;
	var->ply->move[1] = -1;
	var->ply->move[2] = -1;
}

int	main(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->lx = malloc(sizeof(t_mlx));
	var->ply = malloc(sizeof(t_player));
	var->dda = malloc(sizeof(t_dda));
	parsing(var, ac, av);
	show_control(0);
	init(var);
	cub3d(var);
	return (0);
}

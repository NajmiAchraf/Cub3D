/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:20:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/21 14:55:18 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlp_rotation_matrix(double angle, double *x, double *y)
{
	double tmp;

	tmp = *x;
	*x = cos(angle) * *x + sin(angle) * *y;
	*y = -sin(angle) * tmp + cos(angle) * *y;
}

char	get_map_index(t_var *var, double x, double y)
{
	int c;

	c = '_';
	y = y / SCALE;
	x = x / SCALE;
	if (var->pars->map[(int)y])
		c = var->pars->map[(int)y][(int)x];
	return (c);
}

void	set_pos_player(t_var *var)
{
	var->player->pos_x = var->player->ply_x / SCALE;
	var->player->pos_y = var->player->ply_y / SCALE;
}

// Digital differential analyzer
double	dda(t_var *var, double pos_x, double pos_y, double vx, double vy)
{
	double	delta_x;
	double	delta_y;
	// double len_ray = sqrt(vx * vx + vy *vy);
	double len_ray = 1; // is better for raycasting
	if (vx)
		delta_x = len_ray / fabs(vx);//* (var->player->pos_x / var->player->ply_x));
	else
		delta_x = 1e30;

	if (vy)
		delta_y = len_ray / fabs(vy);//* (var->player->pos_y / var->player->ply_y));
	else
		delta_y = 1e30;

	int step_x;
	int	step_y;
	int	map_x;
	int	map_y;
	double	dist_x;
	double	dist_y;

	if (vx >= 0)
	{
		step_x = 1;
		map_x = (int)pos_x;
		dist_x = (map_x + 1 - pos_x) * delta_x;
	}
	else
	{
		step_x = -1;
		map_x = (int)pos_x;
		dist_x = (pos_x - map_x) * delta_x;
	}

	if (vy >= 0)
	{
		step_y = 1;
		map_y = (int)pos_y;
		dist_y = (map_y + 1 - pos_y) * delta_y;
	}
	else{
		step_y = -1;
		map_y = (int)pos_y;
		dist_y = (pos_y - map_y) * delta_y;
	}

	int side;
	while (1)
	{
		// printf("%d, %d\n", map_x, map_y);
		if (dist_x < dist_y){
			dist_x += delta_x;
			map_x += step_x;
			side = 1;
		}
		else{
			dist_y += delta_y;
			map_y += step_y;
			side = 2;
		}
		// printf("%d %d\n", map_y, map_x);
		if (var->pars->map[map_y][map_x] == '1')
		{
			// printf("map_y = %d || map_x = %d || var->pars->map[%d][%d] = %c\n", map_y, map_x, map_y, map_x, var->pars->map[map_y][map_x]);
			// printf("poy = %.2f || pox = %.2f || var->pars->map[%d][%d] || vy = %.2f || vx = %.2f\n", var->player->pos_y, var->player->pos_x, map_y, map_x, var->player->vy, var->player->vx);
			break;
		}
	}
	double dist = 0;
	if (side == 1){
		dist = (dist_x - delta_x);
	}
	else{
		dist = (dist_y - delta_y);
	}

	// printf("%f %d %f %f -- %d %d\n", dist, var->player->re, dist * var->player->re, var->player->ply_x, (int)var->player->pos_x, (int)var->player->pos_y);
	return (dist);
}

void	event(t_var *var)
{

	if (var->player->move[0] == KY_A || var->player->move[0] == KY_D)
	{
		if (get_map_index(var, var->player->ply_x - (var->player->vy * var->player->step_x), var->player->ply_y + (var->player->vx * var->player->step_x)) == '0')
		{
			var->player->ply_x -= var->player->vy * var->player->step_x;
			var->player->ply_y += var->player->vx * var->player->step_x;
		}
		else if (get_map_index(var, var->player->ply_x - (var->player->vy * var->player->step_x), var->player->ply_y) == '0')
			var->player->ply_x -= var->player->vy * var->player->step_x;
		else if (get_map_index(var, var->player->ply_x, var->player->ply_y + (var->player->vx * var->player->step_x)) == '0')
			var->player->ply_y += var->player->vx * var->player->step_x;
	}
	if (var->player->move[1] == KY_S || var->player->move[1] == KY_W)
	{
		if (get_map_index(var, var->player->ply_x + (var->player->vx * var->player->step_y), var->player->ply_y + (var->player->vy * var->player->step_y)) == '0')
		{
			var->player->ply_x += var->player->vx * var->player->step_y;
			var->player->ply_y += var->player->vy * var->player->step_y;
		}
		else if (get_map_index(var, var->player->ply_x + (var->player->vx * var->player->step_y), var->player->ply_y) == '0')
			var->player->ply_x += var->player->vx * var->player->step_y;
		else if (get_map_index(var, var->player->ply_x, var->player->ply_y + (var->player->vy * var->player->step_y)) == '0')
			var->player->ply_y += var->player->vy * var->player->step_y;
	}
	if (var->player->move[2] == KY_LEFT)
	{
		mlp_rotation_matrix(ROTATION_SPEED, &var->player->vx, &var->player->vy);
		mlp_rotation_matrix(ROTATION_SPEED, &var->player->plan_x, &var->player->plan_y);
	}
	else if (var->player->move[2] == KY_RIGHT)
	{
		mlp_rotation_matrix(-ROTATION_SPEED, &var->player->vx, &var->player->vy);
		mlp_rotation_matrix(-ROTATION_SPEED, &var->player->plan_x, &var->player->plan_y);
	}
}

void	execute(int keycode, t_var *var)
{
	if (keycode == KY_A)
	{
		var->player->move[0] = KY_A;
		var->player->step_x = -SPEED;
	}
	else if (keycode == KY_D)
	{
		var->player->move[0] = KY_D;
		var->player->step_x = SPEED;
	}
	else if (keycode == KY_S)
	{
		var->player->move[1] = KY_S;
		var->player->step_y = -SPEED;
	}
	else if (keycode == KY_W)
	{
		var->player->move[1] = KY_W;
		var->player->step_y = SPEED;
	}
	else if (keycode == KY_LEFT)
	{
		var->player->move[2] = KY_LEFT;
	}
	else if (keycode == KY_RIGHT)
	{
		var->player->move[2] = KY_RIGHT;
	}
	// else if (keycode == KY_SPACE)
	// 	init(var);
	// else if (keycode == KY_PLUS && var->player->zoom > 0.)
	// {
	// 	var->player->zoom *= var->player->speed;
	// 	// var->player->step /= var->player->speed;
	// }
	// else if (keycode == KY_MINUS && var->player->zoom >= RESOLUTION / 4.)
	// {
	// 	var->player->zoom /= var->player->speed;
	// 	// var->player->step *= var->player->speed;
	// }
}

int	downbind(int keycode, t_var *var)
{
	if (keycode == KY_LEFT || keycode == KY_RIGHT || keycode == KY_DOWN
		|| keycode == KY_UP|| keycode == KY_A || keycode == KY_S || keycode == KY_D
		|| keycode == KY_W || keycode == KY_SPACE || keycode == KY_PLUS || keycode == KY_MINUS)
		execute(keycode, var);
	else if (keycode == KY_C)
		return (0);
	// printf("%d\n", keycode);
	return (0);
}

int	upbind(int keycode, t_var *var)
{
	if (keycode == KY_ESC)
	{
		mlx_destroy_window(var->lx->mlx, var->lx->win);
		exit(1);
	}
	if (keycode == KY_A || keycode == KY_D)
		var->player->move[0] = -1;
	if (keycode == KY_S || keycode == KY_W)
		var->player->move[1] = -1;
	if (keycode == KY_LEFT || keycode == KY_RIGHT)
		var->player->move[2] = -1;
	return (0);
}

int	mouse_position(int x, int y, t_var *var)
{
	// var->player->x = get_pos(var, var->player->ply_x, x);
	// var->player->y = get_neg(var, var->player->ply_y, y);
	// show(var);
	return (0);
}

int	mouse_zoom(int keycode, int x, int y, t_var *var)
{
	// if (keycode == CK_UP && var->player->zoom > 0.)
	// {
	// 	var->player->zoom *= var->player->speed;
	// 	// var->player->step /= var->player->speed;
	// }
	// else if (keycode == CK_DOWN && var->player->zoom >= RESOLUTION / 4.)
	// {
	// 	var->player->zoom /= var->player->speed;
	// 	// var->player->step *= var->player->speed;
	// }
	// if (keycode == CK_UP || keycode == CK_DOWN)
	// {
	// 	// var->player->trs_re = get_pos(var, var->player->ply_x, x);
	// 	// var->player->trs_im = get_neg(var, var->player->ply_y, y);
	// 	// var->player->scale = 1. / var->player->zoom;
	// 	// var->player->ply_x = get_neg(var, var->player->trs_re, x);
	// 	// var->player->ply_y = get_pos(var, var->player->trs_im, y);
	// 	// show(var);
	// 	return (0);
	// }
	return (0);
}

int	xite(void)
{
	exit(0);
	return (0);
}

void	put_pixel_to_image(t_var *var, int x, int y, int color)
{
	if (x < 0 || x >= RESOLUTION || y < 0 || y >= RESOLUTION)
		return ;
	var->lx->dst = var->lx->addr + (y * var->lx->line_length + \
			x * (var->lx->bits_per_pixel / 8));
	*(unsigned int *) var->lx->dst = color;
}

void	reset_image(t_var *var)
{
	mlx_destroy_image(var->lx->mlx, var->lx->img);
	var->lx->img = mlx_new_image(var->lx->mlx, RESOLUTION, RESOLUTION);
	var->lx->addr = mlx_get_data_addr(var->lx->img, &var->lx->bits_per_pixel,
			&var->lx->line_length, &var->lx->endian);
}

void	show_image(t_var *var)
{
	mlx_put_image_to_window(var->lx->mlx, var->lx->win, var->lx->img, 0, 0);
}

void	draw_line(t_var *var, double x_0, double y_0, double slope, double len){
	double r;
	double x;
	double y;

	for (double r = 0; r < len; r += 0.1){
		x = cos(slope) * r;
		y = sin(slope) * r;
		put_pixel_to_image(var, x_0 + x, y_0 + y, RED);
	}
}

void	projection(t_var *var)
{
	double	X;
	double	dist;

	for (size_t x = 0; x < RESOLUTION; x++)
	{
		X = ((2.0 * x) - RESOLUTION) / (double)RESOLUTION;
		var->player->ray_dir_x = var->player->vx + (X * var->player->plan_x);
		var->player->ray_dir_y = var->player->vy + (X * var->player->plan_y);
		dist = dda(var, var->player->pos_x, var->player->pos_y, var->player->ray_dir_x, var->player->ray_dir_y) * SCALE;
		draw_line(var, var->player->pos_x * SCALE, var->player->pos_y * SCALE, atan2(var->player->ray_dir_y, var->player->ray_dir_x), dist);
	}
	
	
}

void	draw_squar(t_var *var, double x, double y, double size_x, double size_y, int color){
	for (int j = y; j < y + size_y - 1; j++){
		for (int i = x; i < x + size_x - 1; i++){
			put_pixel_to_image(var, i,j, color);
		}
	}
}

void	draw_the_map(t_var *var){
	for (int y = 0; var->pars->map[y]; y++){
		for (int x = 0; var->pars->map[y][x]; x++){
			if (var->pars->map[y][x] == '1')
				draw_squar(var, x * SCALE, y * SCALE, SCALE, SCALE, WHITE);
			else if (var->pars->map[y][x] == '0')
				draw_squar(var, x * SCALE, y * SCALE, SCALE, SCALE, BLUE);
		}
	}
}

void	draw_player(t_var *var)
{
	double	dist; 
	set_pos_player(var);
	draw_squar(var, (var->player->pos_x * SCALE) - PLY_SIZE, (var->player->pos_y * SCALE) - PLY_SIZE, PLY_SIZE*2, PLY_SIZE*2, RED);
	// Digital differential analyzer
	// dist = dda(var, var->player->pos_x, var->player->pos_y, var->player->vx, var->player->vy) * SCALE; 
	// draw_line(var, (var->player->pos_x) * SCALE, (var->player->pos_y) * SCALE, atan2(var->player->vy, var->player->vx), dist);
	projection(var);
}

int	draw(t_var *var)
{
	int i, j;
	char c;
	reset_image(var);
	draw_the_map(var);
	draw_player(var);
	show_image(var);
	event(var);
	return (0);
}

int	draw_init(t_var *var)
{
	int x, y;
	for (y=0; var->pars->map[y]; y++) {
		for (x=0; var->pars->map[y][x]; x++) {
			if (var->pars->map[y][x] == 'N')
			{
				var->player->ply_y = y * SCALE;
				var->player->ply_x = x * SCALE;
				set_pos_player(var);
				var->pars->map[y][x] = '0';
				return 0;
			}
		}
	}
	return (0);
}

void	init(t_var *var)
{
	var->player->step_x = SPEED;
	var->player->step_y = SPEED;
	var->player->ply_x = 0;
	var->player->ply_y = 0;
	var->player->pos_x = 0;
	var->player->pos_y = 0;
	var->player->vx = 1;
	var->player->vy = 0;
	var->player->plan_x = 0;
	var->player->plan_y = 0.63;
	var->pars->map = malloc(sizeof(char *) * 13);
	int fd = open("map.cub", 0666);
	var->pars->map[0] = get_next_line(fd);
	var->pars->map[1] = get_next_line(fd);
	var->pars->map[2] = get_next_line(fd);
	var->pars->map[3] = get_next_line(fd);
	var->pars->map[4] = get_next_line(fd);
	var->pars->map[5] = get_next_line(fd);
	var->pars->map[6] = get_next_line(fd);
	var->pars->map[7] = get_next_line(fd);
	var->pars->map[8] = get_next_line(fd);
	var->pars->map[9] = get_next_line(fd);
	var->pars->map[10] = get_next_line(fd);
	var->pars->map[11] = get_next_line(fd);
	var->pars->map[12] = NULL;
	var->player->move[0] = -1;
	var->player->move[1] = -1;
	var->player->move[2] = -1;
	close(fd);
}

int	main(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->lx = malloc(sizeof(t_lx));
	var->pars = malloc(sizeof(t_pars));
	var->player = malloc(sizeof(t_player));
	init(var);
	var->lx->mlx = mlx_init();
	var->lx->win = mlx_new_window(var->lx->mlx, RESOLUTION, RESOLUTION, "CUB3D");
	var->lx->img = mlx_new_image(var->lx->mlx, RESOLUTION, RESOLUTION);
	var->lx->addr = mlx_get_data_addr(var->lx->img, &var->lx->bits_per_pixel,
			&var->lx->line_length, &var->lx->endian);
	mlx_hook(var->lx->win, ON_KEYDOWN, 0, downbind, var);
	mlx_hook(var->lx->win, ON_KEYUP, 0, upbind, var);
	mlx_hook(var->lx->win, ON_DESTROY, 0, xite, var);
	mlx_hook(var->lx->win, ON_MOUSEMOVE, 0, mouse_position, var);
	mlx_hook(var->lx->win, ON_MOUSEDOWN, 0, mouse_zoom, var);
	show_control();
	draw_init(var);
	mlx_loop_hook(var->lx->mlx, draw, var);
	mlx_loop(var->lx->mlx);
	return (0);
}

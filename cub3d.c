/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:20:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/21 20:36:52 by anajmi           ###   ########.fr       */
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
	if (var->pars->map[(int)y])
		c = var->pars->map[(int)y][(int)x];
	return (c);
}

char	gmie(t_var *var, double x, double to_x, double y, double to_y)
{
	char	c;
	double	i;
	double	j;
	double	dx = (to_x - x) / 10;
	double	dy = (to_y - y) / 10;

	printf("dx = %lf	||	", dx);
	printf("dy = %lf\n", dy);
	printf("start==========================================\n");
	c = '_';

	while (x + i < to_x || y + j < to_y)
	{
		c = get_map_index(var, x + i, y + j);
		if (c == '1')
			return (c);
		i += dx;
		j += dy;
	}
	// for (i = dx; x + i < to_x; i += dx)
	// {
	// 	for (j = dy; y + j < to_y; j += dy)
	// 	{
	// 		c = get_map_index(var, x + i, y + j);
	// 		// printf("x + i = %lf	||	", x + i);
	// 		// printf("y + j = %lf\n", y + j);
	// 		// printf("c = %c\n", c);
	// 		if (c == '1')
	// 		{
	// 			printf("end------------------------------------------\n");
	// 			return (c);
	// 		}
	// 	}
	// }
	printf("------------------------------------------end\n");
	return (c);
}

// Digital differential analyzer
double	dda(t_var *var, double pos_x, double pos_y, double vx, double vy)
{
	double	delta_x;
	double	delta_y;
	// double len_ray = sqrt(vx * vx + vy *vy);
	double len_ray = 1; // is better for raycasting
	if (vx)
		delta_x = len_ray / fabs(vx);
	else
		delta_x = 1e30;

	if (vy)
		delta_y = len_ray / fabs(vy);
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
		if (var->pars->map[map_y][map_x] == '1')
			break;
	}
	double dist = 0;
	if (side == 1){
		dist = (dist_x - delta_x);
	}
	else{
		dist = (dist_y - delta_y);
	}
	return (dist);
}

void	event(t_var *var)
{
	if (var->ply->move[0] == KY_A || var->ply->move[0] == KY_D)
	{
		if (get_map_index(var, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
		{
			var->ply->pos_x -= var->ply->vy * var->ply->step_x;
			var->ply->pos_y += var->ply->vx * var->ply->step_x;
		}
		else if (get_map_index(var, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y) == '0')
			var->ply->pos_x -= var->ply->vy * var->ply->step_x;
		else if (get_map_index(var, var->ply->pos_x, var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
			var->ply->pos_y += var->ply->vx * var->ply->step_x;
	}
	if (var->ply->move[1] == KY_S || var->ply->move[1] == KY_W)
	{
		if (get_map_index(var, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
		{
			var->ply->pos_x += var->ply->vx * var->ply->step_y;
			var->ply->pos_y += var->ply->vy * var->ply->step_y;
		}
		else if (get_map_index(var, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y) == '0')
			var->ply->pos_x += var->ply->vx * var->ply->step_y;
		else if (get_map_index(var, var->ply->pos_x, var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
			var->ply->pos_y += var->ply->vy * var->ply->step_y;
	}
	if (var->ply->move[2] == KY_LEFT)
	{
		mlp_rotation_matrix(ROTATION_SPEED, &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(ROTATION_SPEED, &var->ply->plan_x, &var->ply->plan_y);
	}
	else if (var->ply->move[2] == KY_RIGHT)
	{
		mlp_rotation_matrix(-ROTATION_SPEED, &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(-ROTATION_SPEED, &var->ply->plan_x, &var->ply->plan_y);
	}
}

void	event_n(t_var *var)
{
	if (var->ply->move[0] == KY_A || var->ply->move[0] == KY_D)
	{
		// if (get_map_index(var, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
		if (gmie(var, var->ply->pos_x, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y , var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
		{
			var->ply->pos_x -= var->ply->vy * var->ply->step_x;
			var->ply->pos_y += var->ply->vx * var->ply->step_x;
		}
		// else if (get_map_index(var, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y) == '0')
		else if (gmie(var, var->ply->pos_x, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y, var->ply->pos_y) == '0')
			var->ply->pos_x -= var->ply->vy * var->ply->step_x;
		// else if (get_map_index(var, var->ply->pos_x, var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
		else if (gmie(var, var->ply->pos_x, var->ply->pos_x, var->ply->pos_y, var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
			var->ply->pos_y += var->ply->vx * var->ply->step_x;
	}
	if (var->ply->move[1] == KY_S || var->ply->move[1] == KY_W)
	{
		// if (get_map_index(var, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
		if (gmie(var, var->ply->pos_x, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y, var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
		{
			var->ply->pos_x += var->ply->vx * var->ply->step_y;
			var->ply->pos_y += var->ply->vy * var->ply->step_y;
		}
		// else if (get_map_index(var, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y) == '0')
		else if (gmie(var, var->ply->pos_x, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y, var->ply->pos_y) == '0')
			var->ply->pos_x += var->ply->vx * var->ply->step_y;
		// else if (get_map_index(var, var->ply->pos_x, var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
		else if (gmie(var, var->ply->pos_x, var->ply->pos_x, var->ply->pos_y, var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
			var->ply->pos_y += var->ply->vy * var->ply->step_y;
	}
	if (var->ply->move[2] == KY_LEFT)
	{
		mlp_rotation_matrix(ROTATION_SPEED, &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(ROTATION_SPEED, &var->ply->plan_x, &var->ply->plan_y);
	}
	else if (var->ply->move[2] == KY_RIGHT)
	{
		mlp_rotation_matrix(-ROTATION_SPEED, &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(-ROTATION_SPEED, &var->ply->plan_x, &var->ply->plan_y);
	}
}

void	execute(int keycode, t_var *var)
{
	if (keycode == KY_A)
	{
		var->ply->move[0] = KY_A;
		var->ply->step_x = -SPEED;
	}
	else if (keycode == KY_D)
	{
		var->ply->move[0] = KY_D;
		var->ply->step_x = SPEED;
	}
	else if (keycode == KY_S)
	{
		var->ply->move[1] = KY_S;
		var->ply->step_y = -SPEED;
	}
	else if (keycode == KY_W)
	{
		var->ply->move[1] = KY_W;
		var->ply->step_y = SPEED;
	}
	else if (keycode == KY_LEFT)
	{
		var->ply->move[2] = KY_LEFT;
	}
	else if (keycode == KY_RIGHT)
	{
		var->ply->move[2] = KY_RIGHT;
	}
	// else if (keycode == KY_SPACE)
	// 	init(var);
	// else if (keycode == KY_PLUS && var->ply->zoom > 0.)
	// {
	// 	var->ply->zoom *= var->ply->speed;
	// 	// var->ply->step /= var->ply->speed;
	// }
	// else if (keycode == KY_MINUS && var->ply->zoom >= RESOLUTION / 4.)
	// {
	// 	var->ply->zoom /= var->ply->speed;
	// 	// var->ply->step *= var->ply->speed;
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
		var->ply->move[0] = -1;
	if (keycode == KY_S || keycode == KY_W)
		var->ply->move[1] = -1;
	if (keycode == KY_LEFT || keycode == KY_RIGHT)
		var->ply->move[2] = -1;
	return (0);
}

int	mouse_position(int x, int y, t_var *var)
{
	// var->ply->x = get_pos(var, var->ply->pos_x, x);
	// var->ply->y = get_neg(var, var->ply->pos_y, y);
	// show(var);
	return (0);
}

int	mouse_zoom(int keycode, int x, int y, t_var *var)
{
	// if (keycode == CK_UP && var->ply->zoom > 0.)
	// {
	// 	var->ply->zoom *= var->ply->speed;
	// 	// var->ply->step /= var->ply->speed;
	// }
	// else if (keycode == CK_DOWN && var->ply->zoom >= RESOLUTION / 4.)
	// {
	// 	var->ply->zoom /= var->ply->speed;
	// 	// var->ply->step *= var->ply->speed;
	// }
	// if (keycode == CK_UP || keycode == CK_DOWN)
	// {
	// 	// var->ply->trs_re = get_pos(var, var->ply->pos_x, x);
	// 	// var->ply->trs_im = get_neg(var, var->ply->pos_y, y);
	// 	// var->ply->scale = 1. / var->ply->zoom;
	// 	// var->ply->pos_x = get_neg(var, var->ply->trs_re, x);
	// 	// var->ply->pos_y = get_pos(var, var->ply->trs_im, y);
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
		put_pixel_to_image(var, x_0 + x, y_0 + y, GREEN);
	}
}

void	raycasting(t_var *var, double dda, int ray)
{
	double size;
	int limit;
	int a;
	int b;

	size =  ((double)RESOLUTION / dda);
	limit = size / 2;
	a = (RESOLUTION / 2) - limit;
	b = (RESOLUTION / 2) + limit;
	for (int y = 0; y < RESOLUTION; y++)
	{
		if (a <= y && y <= b)
			put_pixel_to_image(var, ray, y, YELLOW);
		else if (y < a)
			put_pixel_to_image(var, ray, y, CYAN);
		if (y > b)
			put_pixel_to_image(var, ray, y, XCOL);
	}
}

void	projection(t_var *var)
{
	double	X;
	double	dist;

	for (size_t x = 0; x < RESOLUTION; x++)
	{
		X = ((2.0 * x) - RESOLUTION) / (double)RESOLUTION;
		var->ply->ray_dir_x = var->ply->vx + (X * var->ply->plan_x);
		var->ply->ray_dir_y = var->ply->vy + (X * var->ply->plan_y);
		dist = dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->ray_dir_x, var->ply->ray_dir_y);
		// draw_line(var, var->ply->pos_x * SCALE, var->ply->pos_y * SCALE, atan2(var->ply->ray_dir_y, var->ply->ray_dir_x), dist * SCALE);
		raycasting(var, dist, x);
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
	draw_squar(var, (var->ply->pos_x * SCALE) - PLY_SIZE, (var->ply->pos_y * SCALE) - PLY_SIZE, PLY_SIZE*2, PLY_SIZE*2, GREEN);
	// Digital differential analyzer
	dist = dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->vx, var->ply->vy) * SCALE; 
	draw_line(var, (var->ply->pos_x) * SCALE, (var->ply->pos_y) * SCALE, atan2(var->ply->vy, var->ply->vx), dist);
}

int	draw(t_var *var)
{
	int i, j;
	char c;
	reset_image(var);
	projection(var);
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
				var->ply->pos_y = y;
				var->ply->pos_x = x;
				var->pars->map[y][x] = '0';
				return 0;
			}
		}
	}
	return (0);
}

void	init(t_var *var)
{
	var->ply->step_x = SPEED;
	var->ply->step_y = SPEED;
	var->ply->pos_x = 0;
	var->ply->pos_y = 0;
	var->ply->vx = 1;
	var->ply->vy = 0;
	var->ply->plan_x = 0;
	var->ply->plan_y = 0.5;
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
	var->ply->move[0] = -1;
	var->ply->move[1] = -1;
	var->ply->move[2] = -1;
	close(fd);
}

int	main(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->lx = malloc(sizeof(t_mlx));
	var->pars = malloc(sizeof(t_pars));
	var->ply = malloc(sizeof(t_player));
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

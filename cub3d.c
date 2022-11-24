/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:20:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/24 15:51:01 by sriyani          ###   ########.fr       */
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

char	gmie_NE(t_var *var, double x, double to_x, double y, double to_y)
{
	double	i;
	double	j;
	double	dx;
	double	dy;

	i = 0;
	j = 0;
	dx = (to_x - x) / 1000;
	dy = (to_y - y) / 1000;
	while (x + i < to_x || y + j > to_y)
	{
		if (get_map_index(var, x + i, y + j) == '1')
			break ;
		i += dx;
		j += dy;
	}
	return (get_map_index(var, x + i, y + j));
}

char	gmie_ES(t_var *var, double x, double to_x, double y, double to_y)
{
	double	i;
	double	j;
	double	dx;
	double	dy;

	i = 0;
	j = 0;
	dx = (to_x - x) / 1000;
	dy = (to_y - y) / 1000;
	while (x + i < to_x || y + j < to_y)
	{
		if (get_map_index(var, x + i, y + j) == '1')
			break ;
		i += dx;
		j += dy;
	}
	return (get_map_index(var, x + i, y + j));
}

char	gmie_SW(t_var *var, double x, double to_x, double y, double to_y)
{
	double	i;
	double	j;
	double	dx;
	double	dy;

	i = 0;
	j = 0;
	dx = (to_x - x) / 1000;
	dy = (to_y - y) / 1000;
	while (x + i > to_x || y + j < to_y)
	{
		if (get_map_index(var, x + i, y + j) == '1')
			break ;
		i += dx;
		j += dy;
	}
	return (get_map_index(var, x + i, y + j));
}

char	gmie_WN(t_var *var, double x, double to_x, double y, double to_y)
{
	double	i;
	double	j;
	double	dx;
	double	dy;

	i = 0;
	j = 0;
	dx = (to_x - x) / 1000;
	dy = (to_y - y) / 1000;
	while (x + i > to_x || y + j > to_y)
	{
		if (get_map_index(var, x + i, y + j) == '1')
			break ;
		i += dx;
		j += dy;
	}
	return (get_map_index(var, x + i, y + j));
}

char	gmie(t_var *var, double x, double to_x, double y, double to_y)
{
	char	c;
	double	dx;
	double	dy;

	dx = (to_x - x) / 1000;
	dy = (to_y - y) / 1000;
	if (dx >= 0 && dy <= 0)
		c = gmie_NE(var, x, to_x, y, to_y);
	else if (dx >= 0 && dy >= 0)
		c = gmie_ES(var, x, to_x, y, to_y);
	else if (dx <= 0 && dy >= 0)
		c = gmie_SW(var, x, to_x, y, to_y);
	else if (dx <= 0 && dy <= 0)
		c = gmie_WN(var, x, to_x, y, to_y);
	return (c);
}

/* char	gmie_save(t_var *var, double x, double to_x, double y, double to_y)
{
	double	i = 0;
	double	j = 0;
	double	dx = (to_x - x) / 1000;
	double	dy = (to_y - y) / 1000;

	if (dx >= 0 && dy >= 0)
	{
		while (x + i < to_x || y + j < to_y)
		{
			if (get_map_index(var, x + i, y + j) == '1')
				break ;
			i += dx;
			j += dy;
		}
	}
	else if (dx <= 0 && dy >= 0)
	{
		while (x + i > to_x || y + j < to_y)
		{
			if (get_map_index(var, x + i, y + j) == '1')
				break ;
			i += dx;
			j += dy;
		}
	}
	else if (dx >= 0 && dy <= 0)
	{
		while (x + i < to_x || y + j > to_y)
		{
			if (get_map_index(var, x + i, y + j) == '1')
				break ;
			i += dx;
			j += dy;
		}
	}
	else if (dx <= 0 && dy <= 0)
	{
		while (x + i > to_x || y + j > to_y)
		{
			if (get_map_index(var, x + i, y + j) == '1')
				break ;
			i += dx;
			j += dy;
		}
	}
	return (get_map_index(var, x + i, y + j));
} */

/* Digital differential analyzer */
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

/* void	event_old(t_var *var)
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
} */

void	slip_AD(t_var *var)
{
	if (gmie(var, var->ply->pos_x, \
		var->ply->pos_x - (var->ply->vy * var->ply->step_x), \
		var->ply->pos_y, var->ply->pos_y) == '0')
		var->ply->pos_x -= var->ply->vy * var->ply->step_x;
	else if (gmie(var, var->ply->pos_x, \
		var->ply->pos_x, var->ply->pos_y, \
		var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
		var->ply->pos_y += var->ply->vx * var->ply->step_x;
}

void	move_AD(t_var *var)
{
	if (var->ply->move[0] == KY_A || var->ply->move[0] == KY_D)
	{
		if (gmie(var, var->ply->pos_x, \
			var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y, \
			var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
		{
			var->ply->pos_x -= var->ply->vy * var->ply->step_x;
			var->ply->pos_y += var->ply->vx * var->ply->step_x;
		}
		else
			slip_AD(var);
	}
}

void	slip_SW(t_var *var)
{
	if (gmie(var, var->ply->pos_x, \
		var->ply->pos_x + (var->ply->vx * var->ply->step_y), \
		var->ply->pos_y, var->ply->pos_y) == '0')
		var->ply->pos_x += var->ply->vx * var->ply->step_y;
	else if (gmie(var, var->ply->pos_x, var->ply->pos_x, var->ply->pos_y, \
		var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
		var->ply->pos_y += var->ply->vy * var->ply->step_y;
}

void	move_SW(t_var *var)
{
	if (var->ply->move[1] == KY_S || var->ply->move[1] == KY_W)
	{
		if (gmie(var, var->ply->pos_x, \
			var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y, \
			var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
		{
			var->ply->pos_x += var->ply->vx * var->ply->step_y;
			var->ply->pos_y += var->ply->vy * var->ply->step_y;
		}
		else
			slip_SW(var);
	}
}

void	rotate_LR(t_var *var)
{
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

void	event(t_var *var)
{
	move_AD(var);
	move_SW(var);
	rotate_LR(var);
}

/* void	event_save(t_var *var)
{
	if (var->ply->move[0] == KY_A || var->ply->move[0] == KY_D)
	{
		if (gmie(var, var->ply->pos_x, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y , var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
		{
			var->ply->pos_x -= var->ply->vy * var->ply->step_x;
			var->ply->pos_y += var->ply->vx * var->ply->step_x;
		}
		else if (gmie(var, var->ply->pos_x, var->ply->pos_x - (var->ply->vy * var->ply->step_x), var->ply->pos_y, var->ply->pos_y) == '0')
			var->ply->pos_x -= var->ply->vy * var->ply->step_x;
		else if (gmie(var, var->ply->pos_x, var->ply->pos_x, var->ply->pos_y, var->ply->pos_y + (var->ply->vx * var->ply->step_x)) == '0')
			var->ply->pos_y += var->ply->vx * var->ply->step_x;
	}
	if (var->ply->move[1] == KY_S || var->ply->move[1] == KY_W)
	{
		if (gmie(var, var->ply->pos_x, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y, var->ply->pos_y + (var->ply->vy * var->ply->step_y)) == '0')
		{
			var->ply->pos_x += var->ply->vx * var->ply->step_y;
			var->ply->pos_y += var->ply->vy * var->ply->step_y;
		}
		else if (gmie(var, var->ply->pos_x, var->ply->pos_x + (var->ply->vx * var->ply->step_y), var->ply->pos_y, var->ply->pos_y) == '0')
			var->ply->pos_x += var->ply->vx * var->ply->step_y;
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
} */

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
}

int	downbind(int keycode, t_var *var)
{
	if (keycode == KY_LEFT || keycode == KY_RIGHT || keycode == KY_DOWN
		|| keycode == KY_UP|| keycode == KY_A || keycode == KY_S || keycode == KY_D
		|| keycode == KY_W)
		execute(keycode, var);
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
	static int	old_x;

	if (old_x > x)
	{
		mlp_rotation_matrix(MOUSE_ROT_SPEED * (old_x - x), &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(MOUSE_ROT_SPEED * (old_x - x), &var->ply->plan_x, &var->ply->plan_y);
	}
	else if (old_x < x)
	{
		mlp_rotation_matrix(-MOUSE_ROT_SPEED * (x - old_x), &var->ply->vx, &var->ply->vy);
		mlp_rotation_matrix(-MOUSE_ROT_SPEED * (x - old_x), &var->ply->plan_x, &var->ply->plan_y);
	}
	old_x = x;
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
		put_pixel_to_image(var, x_0 + x, y_0 + y, GREEN);
		r += 0.1;
	}
	/* for (double r = 0; r < len; r += 0.1){
		x = cos(slope) * r;
		y = sin(slope) * r;
		put_pixel_to_image(var, x_0 + x, y_0 + y, GREEN);
	} */
}

void	raycasting(t_var *var, double dda, int ray)
{
	double	size;
	int		limit;
	int		a;
	int		b;
	int		y;

	size =  ((double)RESOLUTION / dda);
	limit = size / 2;
	a = ((double)RESOLUTION / 2) - limit;
	b = ((double)RESOLUTION / 2) + limit;
	y = 0;
	while (y < RESOLUTION)
	{
		if (a <= y && y <= b)
			put_pixel_to_image(var, ray, y, CREAMY);
		else if (y < a)
			put_pixel_to_image(var, ray, y, CYAN);
		if (y > b)
			put_pixel_to_image(var, ray, y, PISTASH);
		y++;
	}
	/* for (int y = 0; y < RESOLUTION; y++)
	{
		if (a <= y && y <= b)
			put_pixel_to_image(var, ray, y, CREAMY);
		else if (y < a)
			put_pixel_to_image(var, ray, y, CYAN);
		if (y > b)
			put_pixel_to_image(var, ray, y, PISTASH);
	} */
}

void	projection(t_var *var)
{
	double	X;
	double	dist;
	size_t	x;

 	x = 0;
	while (x < RESOLUTION)
	{
		X = ((2.0 * x) - RESOLUTION) / (double)RESOLUTION;
		var->ply->ray_dir_x = var->ply->vx + (X * var->ply->plan_x);
		var->ply->ray_dir_y = var->ply->vy + (X * var->ply->plan_y);
		dist = dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->ray_dir_x, var->ply->ray_dir_y);
		// draw_line(var, var->ply->pos_x * SCALE, var->ply->pos_y * SCALE, atan2(var->ply->ray_dir_y, var->ply->ray_dir_x), dist * SCALE);
		raycasting(var, dist, x);
		x++;
	}
	/* for (size_t x = 0; x < RESOLUTION; x++)
	{
		X = ((2.0 * x) - RESOLUTION) / (double)RESOLUTION;
		var->ply->ray_dir_x = var->ply->vx + (X * var->ply->plan_x);
		var->ply->ray_dir_y = var->ply->vy + (X * var->ply->plan_y);
		dist = dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->ray_dir_x, var->ply->ray_dir_y);
		// draw_line(var, var->ply->pos_x * SCALE, var->ply->pos_y * SCALE, atan2(var->ply->ray_dir_y, var->ply->ray_dir_x), dist * SCALE);
		raycasting(var, dist, x);
	} */
}

void	full_draw_squar(t_var *var, double x, double y, double size_x, double size_y, int color){
	for (int j = y; j < y + size_y - 1; j++){
		for (int i = x; i < x + size_x - 1; i++){
			put_pixel_to_image(var, i,j, color);
		}
	}
}

void	full_draw_the_map(t_var *var){
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
	double	dist;
	full_draw_squar(var, (var->ply->pos_x * SCALE) - PLY_SIZE, (var->ply->pos_y * SCALE) - PLY_SIZE, PLY_SIZE*2, PLY_SIZE*2, GREEN);
	// Digital differential analyzer
	dist = dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->vx, var->ply->vy) * SCALE; 
	draw_line(var, (var->ply->pos_x) * SCALE, (var->ply->pos_y) * SCALE, atan2(var->ply->vy, var->ply->vx), dist);
	// printf("x = %lf,y = %lf\n", var->ply->pos_x, var->ply->pos_y);
}

void	draw_squar(t_var *var, double x, double y, double size_x, double size_y, int color)
{
	int	i;
	int	j;

	j = y;
	while (j < y + size_y)
	{
		i = x;
		while (i < x + size_x)
		{
			put_pixel_to_image(var, i,j, color);
			i++;
		}
		j++;
	}
	// for (int j = y; j < y + size_y - 1; j++){
	// 	for (int i = x; i < x + size_x - 1; i++){
	// 		put_pixel_to_image(var, i,j, color);
	// 	}
	// }
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
					(y - var->ply->pos_y) * SCALE + POS_PLY, SCALE, SCALE, WHITE);
			else if (var->pars->map[y][x] == '0'
				&& ((fabs(var->ply->pos_x - x)) * SCALE) < POS_PLY
				&& ((fabs(var->ply->pos_y - y)) * SCALE) < POS_PLY)
				draw_squar(var, (x - var->ply->pos_x) * SCALE + POS_PLY, \
					(y - var->ply->pos_y) * SCALE + POS_PLY, SCALE, SCALE, BLUE);
				x++;
		}
		y++;
	}

	// for (int y = 0; var->pars->map[y]; y++){
	// 	for (int x = 0; var->pars->map[y][x]; x++){
	// 		if (var->pars->map[y][x] == '1' && ((fabs(var->ply->pos_x - x)) * SCALE) < POS_PLY && ((fabs(var->ply->pos_y - y)) * SCALE) < POS_PLY)
	// 			draw_squar(var, (x - var->ply->pos_x) * SCALE + POS_PLY, (y - var->ply->pos_y) * SCALE + POS_PLY, SCALE, SCALE, WHITE);
	// 		else if (var->pars->map[y][x] == '0' && ((fabs(var->ply->pos_x - x)) * SCALE) < POS_PLY && ((fabs(var->ply->pos_y - y)) * SCALE) < POS_PLY)
	// 			draw_squar(var, (x - var->ply->pos_x) * SCALE + POS_PLY, (y - var->ply->pos_y) * SCALE + POS_PLY, SCALE, SCALE, BLUE);
	// 	}
	// }
}

void	draw_player(t_var *var)
{
	double	dist;

	draw_squar(var, POS_PLY - PLY_SIZE, POS_PLY - PLY_SIZE, PLY_SIZE*2, PLY_SIZE*2, GREEN);
	dist = dda(var, var->ply->pos_x, var->ply->pos_y, var->ply->vx, var->ply->vy) * SCALE;
	
	if (dist > 20)
		dist = 20;
	draw_line(var, POS_PLY, POS_PLY, atan2(var->ply->vy, var->ply->vx), dist);
}

int	draw(t_var *var)
{
	int i, j;
	char c;
	reset_image(var);
	projection(var);
	// full_draw_the_map(var);
	// full_draw_player(var);
	draw_the_map(var);
	draw_player(var);
	show_image(var);
	event(var);
	return (0);
}

void	set_directions(t_var *var, double vx, double vy, double plan_x, double plan_y)
{
	var->ply->vx = vx;
	var->ply->vy = vy;
	var->ply->plan_x = plan_x;
	var->ply->plan_y = plan_y;
}

void	directions_player(t_var *var, char dir)
{
	if (dir == 'N')
		set_directions(var, 0, -1, 0.5, 0);
	else if (dir == 'S')
		set_directions(var, 0, 1, -0.5, 0);
	else if (dir == 'E')
		set_directions(var, 1, 0, 0, 0.5);
	else if (dir == 'W')
		set_directions(var, -1, 0, 0, -0.5);
}

void	change_map(t_var *var, int x, int y)
{
	char *old;
	char *new;
	int	 i;

	old = ft_strdup(var->pars->map[y]);
	// free(var->pars->map[y]);
	new = malloc((ft_strlen(old) + 1) * sizeof(char));
	i = 0;
	while (old[i])
	{
		if (i != x)
			new[i] = old[i];
		else if (i == x)
			new[i] = '0';
		i++;
	}
	new[i] = '\0';
	var->pars->map[y] = new;
	printf("%s", var->pars->map[y]);
}

void	player_set(t_var *var)
{
	int	x;
	int	y;

	y = 0;
	while (var->pars->map[y])
	{
		printf("%s\n", var->pars->map[y]);
		x = 0;
		while (var->pars->map[y][x])
		{
			if (var->pars->map[y][x] == 'N'
				|| var->pars->map[y][x] == 'S'
				|| var->pars->map[y][x] == 'E'
				|| var->pars->map[y][x] == 'W')
			{
				var->ply->pos_y = y + 0.5;
				var->ply->pos_x = x + 0.5;
				directions_player(var, var->pars->map[y][x]);
				change_map(var, x, y);
				// var->pars->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	/* for (y=0; var->pars->map[y]; y++) {
		for (x=0; var->pars->map[y][x]; x++) {
			if (var->pars->map[y][x] == 'N') // NSEW
			{
				var->ply->pos_y = y + 0.5;
				var->ply->pos_x = x + 0.5;
				var->pars->map[y][x] = '0';
				return 0;
			}
		}
	} */
}

void	init(t_var *var)
{
	var->ply->step_x = SPEED;
	var->ply->step_y = SPEED;
	// var->ply->pos_x = 0;
	// var->ply->pos_y = 0;
	// var->ply->vx = 1;
	// var->ply->vy = 0;
	// var->ply->plan_x = 0;
	// var->ply->plan_y = 0.5;
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
	parsing(var, ac, av);

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
	show_control();
	player_set(var);
	mlx_loop_hook(var->lx->mlx, draw, var);
	mlx_loop(var->lx->mlx);
	return (0);
}

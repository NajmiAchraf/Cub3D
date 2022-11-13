/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:20:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/13 14:12:48 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char get_map_index(t_var *var, int i, int j, int rslt)
{
	int c;

	c = '_';
	if (var->map[(j / var->im) % rslt])
		c = var->map[(j / var->im) % rslt][(i / var->re) % rslt];
	return (c);
}

void set_pos_player(t_var *var)
{
	var->pos_x = (var->ply_x - MAP_POSITION) / var->re;
	var->pos_y = (var->ply_y - MAP_POSITION) / var->im;
}

void event(t_var *var)
{
	if (var->move[0] == KY_LEFT)
	{
		if (get_map_index(var, var->ply_x - var->step - MAP_POSITION, var->ply_y - MAP_POSITION, var->k) == '0')
		// if (var->ply_x >= 0)
			var->ply_x -= var->step;
		// if (var->ply_x == -var->step)
		// 	var->ply_x = 0;
	}
	else if (var->move[0] == KY_RIGHT)
	{
		if (get_map_index(var, var->ply_x + var->step - MAP_POSITION, var->ply_y - MAP_POSITION, var->k) == '0')
		// if (var->ply_x <= RESOLUTION)
			var->ply_x += var->step;
		// if (var->ply_x + var->k == RESOLUTION + var->step)
		// 	var->ply_x = RESOLUTION - var->k;
	}
	if (var->move[1] == KY_DOWN)
	{
		if (get_map_index(var, var->ply_x - MAP_POSITION, var->ply_y + var->step - MAP_POSITION, var->k) == '0')
		// if (var->ply_y <= RESOLUTION)
			var->ply_y += var->step;
		// if (var->ply_y + var->k == RESOLUTION + var->step)
		// 	var->ply_y = RESOLUTION - var->k;
	}
	else if (var->move[1] == KY_UP)
	{
		if (get_map_index(var, var->ply_x - MAP_POSITION, var->ply_y - var->step - MAP_POSITION, var->k) == '0')
		// if (var->ply_y >= 0)
			var->ply_y -= var->step;
		// if (var->ply_y == -var->step)
		// 	var->ply_y = 0;
	}
}

void	execute(int keycode, t_var *var)
{
	if (keycode == KY_LEFT)
	{
		var->move[0] = KY_LEFT;
		/*if (var->ply_x >= 0)
			var->ply_x -= var->step;
		if (var->ply_x == -var->step)
			var->ply_x = 0;*/
	}
	else if (keycode == KY_RIGHT)
	{
		var->move[0] = KY_RIGHT;
		/* if (var->ply_x <= RESOLUTION)
			var->ply_x += var->step;
		if (var->ply_x + var->k == RESOLUTION + var->step)
			var->ply_x = RESOLUTION - var->k; */
	}
	else if (keycode == KY_DOWN)
	{
		var->move[1] = KY_DOWN;
		/* if (var->ply_y <= RESOLUTION)
			var->ply_y += var->step;
		if (var->ply_y + var->k == RESOLUTION + var->step)
			var->ply_y = RESOLUTION - var->k; */
	}
	else if (keycode == KY_UP)
	{
		var->move[1] = KY_UP;
		/* if (var->ply_y >= 0)
			var->ply_y -= var->step;
		if (var->ply_y == -var->step)
			var->ply_y = 0; */
	}
	// else if (keycode == KY_SPACE)
	// 	init(var);
	else if (keycode == KY_PLUS && var->zoom > 0.)
	{
		var->zoom *= var->speed;
		var->step /= var->speed;
	}
	else if (keycode == KY_MINUS && var->zoom >= RESOLUTION / 4.)
	{
		var->zoom /= var->speed;
		var->step *= var->speed;
	}
}

int	downbind(int keycode, t_var *var)
{
	if (keycode == KY_LEFT || keycode == KY_RIGHT || keycode == KY_DOWN
		|| keycode == KY_UP || keycode == KY_SPACE || keycode == KY_PLUS
		|| keycode == KY_MINUS)
		execute(keycode, var);
	else if (keycode == KY_C)
		return (0);
	return (0);
}

int	upbind(int keycode, t_var *var)
{
	if (keycode == KY_ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(1);
	}
	if (keycode == KY_LEFT || keycode == KY_RIGHT)
		var->move[0] = -1;
	if (keycode == KY_DOWN || keycode == KY_UP)
		var->move[1] = -1;
	return (0);
}

int	mouse_position(int x, int y, t_var *var)
{
	// var->x = get_pos(var, var->ply_x, x);
	// var->y = get_neg(var, var->ply_y, y);
	// show(var);
	return (0);
}

int	mouse_zoom(int keycode, int x, int y, t_var *var)
{
	if (keycode == CK_UP && var->zoom > 0.)
	{
		var->zoom *= var->speed;
		var->step /= var->speed;
	}
	else if (keycode == CK_DOWN && var->zoom >= RESOLUTION / 4.)
	{
		var->zoom /= var->speed;
		var->step *= var->speed;
	}
	if (keycode == CK_UP || keycode == CK_DOWN)
	{
		// var->trs_re = get_pos(var, var->ply_x, x);
		// var->trs_im = get_neg(var, var->ply_y, y);
		// var->scale = 1. / var->zoom;
		// var->ply_x = get_neg(var, var->trs_re, x);
		// var->ply_y = get_pos(var, var->trs_im, y);
		// show(var);
		return (0);
	}
	return (0);
}

int	xite(void)
{
	exit(1);
	return (0);
}

void	put_pixel_to_image(t_var *data, int x, int y, int color)
{
	data->dst = data->addr + (y * data->line_length + \
			x * (data->bits_per_pixel / 8));
	*(unsigned int *) data->dst = color;
}

void	reset_image(t_var *var)
{
	mlx_destroy_image(var->mlx, var->img);
	var->img = mlx_new_image(var->mlx, RESOLUTION, RESOLUTION);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
			&var->line_length, &var->endian);
}

void	show_image(t_var *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}

int	check_args(t_var *var, int ac, char **av)
{
	var->nbfc = ft_atoi(av[3]);
	if (1 <= var->nbfc && var->nbfc <= 4)
	{
		if ((var->nbfc == 1 && ac == 4) || (var->nbfc == 2 && ac == 6)
			|| (var->nbfc == 3 && ac == 5) || (var->nbfc == 4 && ac == 4))
			return (1);
		return (0);
	}
	return (0);
}

void	init(t_var *var)
{
	var->k = MAP_RESOLUTION / 50;
	var->step = 5;
	var->speed = 2;
	var->col = 1;
	var->zoom = RESOLUTION / 4.;
	var->scale = 1. / var->zoom;
	var->ply_x = 0;
	var->ply_y = 0;
	var->pos_x = 0;
	var->pos_y = 0;
	var->map = malloc(sizeof(char *) * 7);
	int fd = open("map.cub", 0666);
	var->map[0] = get_next_line(fd);
	var->map[1] = get_next_line(fd);
	var->map[2] = get_next_line(fd);
	var->map[3] = get_next_line(fd);
	var->map[4] = get_next_line(fd);
	var->map[5] = get_next_line(fd);
	var->map[6] = NULL;
	var->move[0] = -1;
	var->move[1] = -1;
	close(fd);
}


void line(t_var *var)
{
	int x, y, nrx, nry;
	nrx = (MAP_RESOLUTION) - var->ply_x; // * cos(angle));
	nry = var->ply_y + (MAP_RESOLUTION); // * sin(angle));
	
	for (x=var->ply_x; x < RESOLUTION; x++){
		for (y=var->ply_y; y < (var->ply_y + 1); y++){
			if (get_map_index(var, x - MAP_POSITION ,y - MAP_POSITION, MAP_RESOLUTION) == '0')
				put_pixel_to_image(var, x, y, RED);
			else
				return;
		}
	}
}

void player(t_var *var)
{
	int x, y;
	for (x=var->ply_x - (var->k / 2); x < ((var->k / 2) + var->ply_x); x++){
		for (y=var->ply_y - (var->k / 2); y < ((var->k / 2) + var->ply_y); y++){
			put_pixel_to_image(var, x, y, WHITE);
		}
	}
	// for (x=var->ply_x; x < (10 + var->ply_x); x++){
	// 	for (y=var->ply_y; y < (10 + var->ply_y); y++){
	// 		put_pixel_to_image(var, x, y, 0x00ffffff);
	// 	}
	// }
	line(var);
	set_pos_player(var);
	// printf("x = %lf,y = %lf\n", var->pos_x, var->pos_y);
}

void point(t_var *var)
{
	int i, j;
	char c;
	for (i=0; i < MAP_RESOLUTION; i++) {
		for (j=0; j < MAP_RESOLUTION; j++) {
			c = get_map_index(var, i ,j, MAP_RESOLUTION);
			// c = var->map[(j / var->im) % MAP_RESOLUTION][(i / var->re) % MAP_RESOLUTION];
			if (c == '1')
				put_pixel_to_image(var, i + MAP_POSITION, j + MAP_POSITION, 0x00abcdef);
			else if (c == '0' || c == 'N')
				put_pixel_to_image(var, i + MAP_POSITION, j + MAP_POSITION, 0x00fedcba);
		}
	}
}

int plot(t_var *var)
{
	int i, j;
	char c;
	reset_image(var);
	// for (i=0; i < RESOLUTION; i += var->k) {
	// 	// printf("(i / var->re) %% var->k == (%d / %d) %% %d = %d\n", i, var->re, var->k, (i / var->re) % var->k);
	// 	for (j=0; j < RESOLUTION; j += var->k) {
	// 		// printf("(j / var->im) %% var->k == (%d / %d) %% %d = %d\n", j, var->im, var->k, (j / var->im) % var->k);
	// 		c = var->map[(j / var->im) % var->k][(i / var->re) % var->k];
	// 		if (c == '1')
	// 			squar(var, i, j, 0x00abcdef);
	// 		else if (c == '0' || c == 'N')
	// 			squar(var, i, j, 0x00fedcba);
	// 	}
	// }
	point(var);
	player(var);
	show_image(var);
	event(var);
	return (0);
}

int plotinit(t_var *var)
{
	int i, j;
	char c;
	var->re = MAP_RESOLUTION / (ft_strlen(var->map[0]) - 1);
	var->im = MAP_RESOLUTION / 6;
	// for (i=0; i < RESOLUTION; i += var->k) {
	// 	for (j=0; j < RESOLUTION; j += var->k) {
	// 		c = var->map[(j / var->im) % var->k][(i / var->re) % var->k];
	// 		if (c == 'N')
	// 		{
	// 			var->ply_x = i;
	// 			var->ply_y = j;
	// 			var->map[(j / var->im) % var->k][(i / var->re) % var->k] = '0';
	// 			return 0;
	// 		}
	// 	}
	// }
	for (i=0; i < MAP_RESOLUTION; i++) {
		for (j=0; j < MAP_RESOLUTION; j++) {
			c = get_map_index(var, i ,j, MAP_RESOLUTION);
			if (c == 'N')
			{
				var->ply_x = i + MAP_POSITION;
				var->ply_y = j + MAP_POSITION;
				var->map[(j / var->im)][(i / var->re)] = '0';
				return 0;
			}
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_var	*var;
	
	var = malloc(sizeof(t_var));
	init(var);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, RESOLUTION, RESOLUTION, "CUB3D");
	var->img = mlx_new_image(var->mlx, RESOLUTION, RESOLUTION);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
			&var->line_length, &var->endian);
	mlx_hook(var->win, ON_KEYDOWN, 0, downbind, var);
	mlx_hook(var->win, ON_KEYUP, 0, upbind, var);
	mlx_hook(var->win, ON_DESTROY, 0, xite, var);
	if (var->nbfc == 4)
		mlx_hook(var->win, ON_MOUSEMOVE, 0, mouse_position, var);
	else if (var->nbfc != 4)
		mlx_hook(var->win, ON_MOUSEDOWN, 0, mouse_zoom, var);
	show_control();
	plotinit(var);
	mlx_loop_hook(var->mlx, plot, var);
	mlx_loop(var->mlx);
	return (0);
}

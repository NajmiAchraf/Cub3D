/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_old.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:20:42 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/21 14:49:18 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlp_rotation_matrix(double angle, double *x, double *y){
	double tmp;

	tmp = *x;
	*x = cos(angle) * *x + sin(angle) * *y;
	*y = -sin(angle) * tmp + cos(angle) * *y;
}

char get_map_index(t_var *var, int i, int j)
{
	int c;

	c = '_';
	if (var->map[(j / var->im)])
		c = var->map[(j / var->im)][(i / var->re)];
	return (c);
}

void set_pos_player(t_var *var)
{
	// var->pos_x = (var->ply_x - MAP_POSITION) / var->re;
	// var->pos_y = (var->ply_y - MAP_POSITION) / var->im;
	var->pos_x = (var->ply_x - MAP_POSITION) / var->re;
	var->pos_y = (var->ply_y - MAP_POSITION) / var->im;
	printf("var->pos_y = %0.2f || var->pos_x = %0.2f\n", var->pos_y, var->pos_x);

}

void event(t_var *var)
{

	if (var->move[0] == KY_A || var->move[0] == KY_D)
	{
		if (get_map_index(var, var->ply_x - (var->vy * var->step) - MAP_POSITION, var->ply_y + (var->vx * var->step) - MAP_POSITION) == '0')
		{
			var->ply_x -= var->vy * var->step;
			var->ply_y += var->vx * var->step;
		}
	}
	if (var->move[1] == KY_S || var->move[1] == KY_W)
	{
		if (get_map_index(var, var->ply_x + (var->vx * var->step) - MAP_POSITION, var->ply_y + (var->vy * var->step) - MAP_POSITION) == '0')
		{
			var->ply_x += var->vx * var->step;
			var->ply_y += var->vy * var->step;
		}
	}
	if (var->move[2] == KY_LEFT)
	{
		mlp_rotation_matrix(ROTATION_SPEED, &var->vx, &var->vy);
	}
	else if (var->move[2] == KY_RIGHT)
	{
		mlp_rotation_matrix(-ROTATION_SPEED, &var->vx, &var->vy);
	}
}

double	ddaold(t_var *var, double pos_x, double pos_y, double vx, double vy)
{
	double	delta_x;
	double	delta_y;
	if (vx)
		delta_x = fabs(1.0 / vx);//* (var->pos_x / var->ply_x));
	else
		delta_x = 1e30;

	if (vy)
		delta_y = fabs(1.0 / vy);//* (var->pos_y / var->ply_y));
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
		if (var->map[map_y][map_x] == '1')
		{
			printf("pox = %d || poy = %d || var->map[%d][%d] = %c\n", map_x, map_y, map_x, map_y, var->map[map_y][map_x]);
			// printf("poy = %.2f || pox = %.2f || var->map[%d][%d] || vy = %.2f || vx = %.2f\n", var->pos_y, var->pos_x, map_y, map_x, var->vy, var->vx);
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

	// printf("%f %d %f %f -- %d %d\n", dist, var->re, dist * var->re, var->ply_x, (int)var->pos_x, (int)var->pos_y);
	return (dist);
}

double    dda0(t_var *var, double pos_x, double pos_y, double vx, double vy)
{
	double	delta_x;
	double	delta_y;
	if (vx)
		delta_x = 1.0 / fabs(vx);//* (var->pos_x / var->ply_x));
	else
		delta_x = 1e30;

	if (vy)
		delta_y = 1.0 / fabs(vy);//* (var->pos_y / var->ply_y));
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
		if (var->map[map_y][map_x] == '1')
		{
			// printf("map_y = %d || map_x = %d || var->map[%d][%d] = %c\n", map_y, map_x, map_y, map_x, var->map[map_y][map_x]);
			// printf("poy = %.2f || pox = %.2f || var->map[%d][%d] || vy = %.2f || vx = %.2f\n", var->pos_y, var->pos_x, map_y, map_x, var->vy, var->vx);
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

	// printf("%f %d %f %f -- %d %d\n", dist, var->re, dist * var->re, var->ply_x, (int)var->pos_x, (int)var->pos_y);
	return (dist);
}

double    dda(t_var *var, double pos_x, double pos_y, double vx, double vy)
{
	double	delta_x;
	double	delta_y;
	if (vx)
		delta_x = 1.0 / fabs(vx);//* (var->pos_x / var->ply_x));
	else
		delta_x = 1e30;

	if (vy)
		delta_y = 1.0 / fabs(vy);//* (var->pos_y / var->ply_y));
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
		if (var->map[map_y][map_x] == '1')
		{
			// printf("map_y = %d || map_x = %d || var->map[%d][%d] = %c\n", map_y, map_x, map_y, map_x, var->map[map_y][map_x]);
			// printf("poy = %.2f || pox = %.2f || var->map[%d][%d] || vy = %.2f || vx = %.2f\n", var->pos_y, var->pos_x, map_y, map_x, var->vy, var->vx);
			break;
		}
	}
	double dist = 0;
	if (side == 1){
		dist = (dist_x - delta_x) * var->re;
	}
	else{
		dist = (dist_y - delta_y) * var->im;
	}

	// printf("%f %d %f %f -- %d %d\n", dist, var->re, dist * var->re, var->ply_x, (int)var->pos_x, (int)var->pos_y);
	return (dist);
}

void	execute(int keycode, t_var *var)
{
	if (keycode == KY_A)
	{
		var->move[0] = KY_A;
		var->step = -SPEED;
	}
	else if (keycode == KY_D)
	{
		var->move[0] = KY_D;
		var->step = SPEED;
	}
	else if (keycode == KY_S)
	{
		var->move[1] = KY_S;
		var->step = -SPEED;
	}
	else if (keycode == KY_W)
	{
		var->move[1] = KY_W;
		var->step = SPEED;
	}
	else if (keycode == KY_LEFT)
	{
		var->move[2] = KY_LEFT;
	}
	else if (keycode == KY_RIGHT)
	{
		var->move[2] = KY_RIGHT;
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
		mlx_destroy_window(var->mlx, var->win);
		exit(1);
	}
	if (keycode == KY_A || keycode == KY_D)
		var->move[0] = -1;
	if (keycode == KY_S || keycode == KY_W)
		var->move[1] = -1;
	if (keycode == KY_LEFT || keycode == KY_RIGHT)
		var->move[2] = -1;
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
	exit(0);
	return (0);
}

void	put_pixel_to_image(t_var *data, int x, int y, int color)
{
	if (x < 0 || x >= RESOLUTION || y < 0 || y >= RESOLUTION)
		return ;
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
	var->ply_size = 1;
	var->step = SPEED;
	var->speed = 2;
	var->col = 1;
	var->zoom = RESOLUTION / 4.;
	var->scale = 1. / var->zoom;
	var->ply_x = 0;
	var->ply_y = 0;
	var->pos_x = 0;
	var->pos_y = 0;
	var->vx = 0.5;
	var->vy = 0;
	var->map = malloc(sizeof(char *) * 13);
	int fd = open("map.cub", 0666);
	var->map[0] = get_next_line(fd);
	var->map[1] = get_next_line(fd);
	var->map[2] = get_next_line(fd);
	var->map[3] = get_next_line(fd);
	var->map[4] = get_next_line(fd);
	var->map[5] = get_next_line(fd);
	var->map[6] = get_next_line(fd);
	var->map[7] = get_next_line(fd);
	var->map[8] = get_next_line(fd);
	var->map[9] = get_next_line(fd);
	var->map[10] = get_next_line(fd);
	var->map[11] = get_next_line(fd);
	var->map[12] = NULL;
	var->move[0] = -1;
	var->move[1] = -1;
	var->move[2] = -1;
	close(fd);
}

void	draw_line(t_var *var, double x_0, double y_0, double slope, double len){
	/* double y;
	double step;
	double x_n;

	x_n = sqrt(len / (1 + slope * slope)) + x_0;
	step = (x_n - x_0) / 1000;
	for (double x = x_0; x < x_n; x += step) {
		y = slope * (x - x_0) + y_0;
		put_pixel_to_image(var, x, y, RED);
	} */

	double r;
	double x;
	double y;

	// if (len > 1000)
	// 	len = 200;
	for (double r = 0; r < len; r += 0.1){
		x = cos(slope) * r;
		y = sin(slope) * r;
		put_pixel_to_image(var, x_0 + x, y_0 + y, RED);
	}
}


void player(t_var *var)
{
	int x, y;
	for (x=var->ply_x - (var->ply_size / 2); x < ((var->ply_size / 2) + var->ply_x); x++){
		for (y=var->ply_y - (var->ply_size / 2); y < ((var->ply_size / 2) + var->ply_y); y++){
			put_pixel_to_image(var, x, y, WHITE);
		}
	}
	// line(var);
	set_pos_player(var);
	double dist = dda(var, var->pos_x, var->pos_y, var->vx, var->vy);
	// draw_line(var, (var->pos_x) * SCALE, (var->pos_y) * SCALE, atan2(var->vy, var->vx), dist / 2);
	draw_line(var, var->ply_x, var->ply_y, atan2(var->vy, var->vx), dist / 2);//, 100);
	// printf("x = %lf,y = %lf\n", var->pos_x, var->pos_y);
}

void point(t_var *var)
{
	int i, j;
	char c;
	for (i=0; i < MAP_RESOLUTION; i++) {
		for (j=0; j < MAP_RESOLUTION; j++) {
			c = get_map_index(var, i ,j);
			// c = var->map[(j / var->im)][(i / var->re)];
			if (c == '1')
				put_pixel_to_image(var, i + MAP_POSITION, j + MAP_POSITION, 0x00abcdef);
			else if (c == '0' || c == 'N')
				put_pixel_to_image(var, i + MAP_POSITION, j + MAP_POSITION, 0x00fedcba);
		}
	}
}

void	draw_rectangle(t_var *var, double x, double y, double size_x, double size_y, int color){
	for (int j = y + 1; j < y + size_y - 1; j++){
		for (int i = x + 1; i < x + size_x - 1; i++){
			put_pixel_to_image(var, i,j, color);
		}
	}
}

void	draw_the_map(t_var *var){
	for (int y = 0; var->map[y]; y++){
		for (int x = 0; var->map[y][x]; x++){
			if (var->map[y][x] == '1')
				draw_rectangle(var, x * SCALE, y * SCALE, SCALE, SCALE, WHITE);
			else if (var->map[y][x] == '0')
				draw_rectangle(var, x * SCALE, y * SCALE, SCALE, SCALE, BLUE);

		}
	}
	// draw_rectangle(var, var->pos_x * SCALE, var->pos_y * SCALE, 5, 5, RED);
	double dist = dda0(var, var->pos_x, var->pos_y, var->vx, var->vy) * SCALE; //Digital differential analyzer
	draw_line(var, (var->pos_x) * SCALE, (var->pos_y) * SCALE, atan2(var->vy, var->vx), dist / 2);
}

int plot(t_var *var)
{
	int i, j;
	char c;
	reset_image(var);
	// for (i=0; i < RESOLUTION; i += var->ply_size) {
	// 	// printf("(i / var->re) %% var->ply_size == (%d / %d) %% %d = %d\n", i, var->re, var->ply_size, (i / var->re) % var->ply_size);
	// 	for (j=0; j < RESOLUTION; j += var->ply_size) {
	// 		// printf("(j / var->im) %% var->ply_size == (%d / %d) %% %d = %d\n", j, var->im, var->ply_size, (j / var->im) % var->ply_size);
	// 		c = var->map[(j / var->im) % var->ply_size][(i / var->re) % var->ply_size];
	// 		if (c == '1')
	// 			squar(var, i, j, 0x00abcdef);
	// 		else if (c == '0' || c == 'N')
	// 			squar(var, i, j, 0x00fedcba);
	// 	}
	// }
	// point(var);
	// player(var);
	set_pos_player(var);
	draw_the_map(var);
	show_image(var);
	event(var);
	return (0);
}

int plotinit(t_var *var)
{
	int i, j;
	char c;
	var->re = MAP_RESOLUTION / (ft_strlen(var->map[0]) - 1);
	var->im = MAP_RESOLUTION / 12;
	printf("re = %d || im = %d\n", var->re, var->im);
	// for (i=0; i < RESOLUTION; i += var->ply_size) {
	// 	for (j=0; j < RESOLUTION; j += var->ply_size) {
	// 		c = var->map[(j / var->im) % var->ply_size][(i / var->re) % var->ply_size];
	// 		if (c == 'N')
	// 		{
	// 			var->ply_x = i;
	// 			var->ply_y = j;
	// 			var->map[(j / var->im) % var->ply_size][(i / var->re) % var->ply_size] = '0';
	// 			return 0;
	// 		}
	// 	}
	// }
	for (i=0; i < MAP_RESOLUTION; i++) {
		for (j=0; j < MAP_RESOLUTION; j++) {
			c = get_map_index(var, i ,j);
			if (c == 'N')
			{
				var->ply_x = i + MAP_POSITION;
				var->ply_y = j + MAP_POSITION;
				var->map[(j / var->im)][(i / var->re)] = '0';
				// var->ply_x += 10;
				// var->ply_y += 10;
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

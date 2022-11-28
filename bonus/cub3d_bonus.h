/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:40:39 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/28 14:44:24 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../Libft/libft.h"
# include "../LibftPlus/libftplus.h"
# include "../get_next_line/get_next_line.h"

/*
keyboard binds
*/

# define KY_ESC 53

# define ROTATION_SPEED 0.02
# define MOUSE_ROT_SPEED 0.0075
# define SPEED 0.05

# ifdef __linux__
#  define KY_LEFT 65361
#  define KY_RIGHT 65363
#  define KY_A 97
#  define KY_D 100
#  define KY_S 115
#  define KY_W 119

# elif __APPLE__
#  define KY_LEFT 123
#  define KY_RIGHT 124
#  define KY_A 0
#  define KY_D 2
#  define KY_S 1
#  define KY_W 13
# endif

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	RESOLUTION = 1000,
	PLY_SIZE = 3,
	SCALE = 10,
	MAP_SIZE = SCALE * 20,
	POS_PLY = MAP_SIZE / 2,
	WHITE = 0x00ffffff,
	BLACK = 0x00000000,
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff,
	CYAN = 0x00ABCDEF,
	CREAMY = 0x00FEDCBA,
	PISTASH = 0x00DCFEBA
};

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*dst;
	unsigned long	ceiling;
	unsigned long	floor;
}			t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	plan_x;
	double	plan_y;
	double	vx;
	double	vy;
	double	step_x;
	double	step_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		move[3];
}			t_player;

typedef struct s_dda
{
	double	delta_x;
	double	delta_y;
	double	len_ray;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	double	dist_x;
	double	dist_y;
	int		side;
	double	dist;
	double	wall_x;
	double	wall_y;
	double	vx;
	double	vy;
}			t_dda;

typedef struct s_pars
{
	char	**map;
	char	**hold;
	int		flag;
	int		map1;
	char	**no;
	char	**so;
	char	**we;
	char	**ea;
	char	**f;
	char	**c;
	int		nn;
	int		ss;
	int		ww;
	int		ee;
	int		ff;
	int		cc;
	int		zero;
	int		player;
	int		one;
	int		space;
	int		line;
}	t_pars;

typedef struct s_tex
{
	int		bpp;
	int		endian;
	int		line_lenght;
	void	*tex;
	char	*ptr;
	int		width;
	int		height;
}			t_tex;

typedef struct s_var
{
	t_mlx		*lx;
	t_player	*ply;
	t_dda		*dda;
	t_pars		*pars;
	t_tex		*tex[4];
}				t_var;

int		count_plus(char *str);
int		ft_atoi_plus(char *str);
char	*ft_join(char *s1);
void	ft_error_fd(int fd);
void	ft_free(char **ptr);
void	check_extension(int ac, char **av);
void	ft_error(char *str);
int		num_str(char **str);
void	check_map_surrounded(t_var *var);
void	valid_map_column1(t_var *var);
void	valid_map_column(t_var *var);
void	valid_map_line(t_var *var);
void	check_map(t_var *var);
int		lent_map(char *str);
void	check_f_range(t_var *var, char *str);
void	check_c_range(t_var *var, char *str);
void	check_map2(t_var *var, int i, int j);
int		fill_map(t_var *var, int i, int len);
int		check_file2(t_var *var, int i, int j);
int		check_file3(t_var *var, int i, int j, int len);
int		check_file_no(t_var *var, int i, int fd);
int		check_file_so(t_var *var, int i, int fd);
int		check_file_we(t_var *var, int i, int fd);
int		check_file_ea(t_var *var, int i, int fd);
void	parsing(t_var *var, int ac, char **av);

void	put_pixel_to_image(t_var *var, int x, int y, int color);
void	player_set(t_var *var);
void	colors(t_var *var);
void	fill_textures(t_var	*var);
void	raycasting(t_var *var);
void	event(t_var *var);
void	dda(t_var *var, double pos_x, double pos_y);
void	mlp_rotation_matrix(double angle, double *x, double *y);
char	get_map_index(t_var *var, double y, double x);

/* BINDS || HOOKS */
int		downbind(int keycode, t_var *var);
int		upbind(int keycode, t_var *var);
int		mouse_position(int x, int y, t_var *var);
int		xite(void);

/* BONUS */
void	draw_the_map(t_var *var);
void	draw_player(t_var *var);

#endif
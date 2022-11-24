/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:40:39 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/24 15:25:44 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "Libft/libft.h"
# include "LibftPlus/libftplus.h"
# include "get_next_line/get_next_line.h"

/*
keyboard binds
*/

# define KY_ESC 53

# define CK_LEFT 1
# define CK_UP 4
# define CK_DOWN 5

# define ROTATION_SPEED 0.02
# define MOUSE_ROT_SPEED 0.0075
# define SPEED 0.05

# ifdef __linux__
#  define KY_LEFT 65361
#  define KY_RIGHT 65363
#  define KY_DOWN 65364
#  define KY_UP 65362
#  define CK_RIGHT 3
#  define CK_MIDDLE 2

# elif __APPLE__
#  define KY_LEFT 123
#  define KY_RIGHT 124
#  define KY_DOWN 125
#  define KY_UP 126
#  define KY_A 0
#  define KY_D 2
#  define KY_S 1
#  define KY_W 13
#  define CK_RIGHT 2
#  define CK_MIDDLE 3
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
	PLY_SIZE = 2,
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
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*dst;
}			t_mlx;

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

typedef struct s_text
{
	void	*img[4];
	char	*ptr;
	char	*bbp;
	int		line_length;
	int		endian;
} 	t_text;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	plan_x;
	double	plan_y;
	double 	vx;
	double	vy;
	double	step_x;
	double	step_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		move[3];
}			t_player;

typedef struct s_var
{
	t_mlx		*lx;
	t_player	*ply;
	t_pars		*pars;
	t_text		*text;
}				t_var;



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
void	fill_map(t_var *var, int i, int len);
int		check_file2(t_var *var, int i, int j, int fd);
int		check_file3(t_var *var, int i, int j, int len);
int		check_file_no(t_var *var, int i, int j, int fd);
int		check_file_so(t_var *var, int i, int j, int fd);
int		check_file_we(t_var *var, int i, int j, int fd);
int		check_file_ea(t_var *var, int i, int j, int fd);
char	*fill_texture1(t_var *var, char *path);
void	fill_textue(t_var	*var);
void	parsing(t_var *var, int ac, char **av);




void	show_help(void);
void	show_control(void);

#endif
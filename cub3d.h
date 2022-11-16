/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:40:39 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/16 19:12:37 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <complex.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"

/*
keyboard binds
*/

# define KY_ESC 53
# define KY_C 8

# define CK_LEFT 1
# define CK_UP 4
# define CK_DOWN 5

# define ROTATION_SPEED 0.09

# ifdef __linux__
#  define KY_LEFT 65361
#  define KY_RIGHT 65363
#  define KY_DOWN 65364
#  define KY_UP 65362
#  define KY_PLUS 65451
#  define KY_MINUS 65453
#  define KY_SPACE 32
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
#  define KY_PLUS 69
#  define KY_MINUS 78
#  define KY_SPACE 49
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
	MAP_RESOLUTION = 1000,
	MAP_POSITION = RESOLUTION - MAP_RESOLUTION,
	STEP = 10,
	WHITE = 0x00ffffff,
	BLACK = 0x00000000,
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff

};

typedef struct s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	char			**map;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*dst;

	int				ply_size;
	int				re;
	int				im;
	double			ply_x;
	double			ply_y;
	double			pos_x;
	double			pos_y;
	double 			vx;
	double			vy;
	double			speed;
	double			zoom;
	double			step;

	double			x;
	double			y;
	double			scale;
	double			zrtmp;
	double			dist;
	int				nbfc;
	int				col;

	int				move[3];

}					t_var;

void	show_help(void);
void	show_control(void);

#endif
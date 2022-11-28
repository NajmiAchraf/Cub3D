/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:45:27 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/28 14:54:40 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_tex	*fill_texture(t_var *var, char *path)
{
	t_tex	*tex;
	char	*extention;

	extention = ft_strrchr(path, '.');
	if (extention && ft_strncmp(extention, ".xpm", 4) == 0)
	{
		tex = malloc(sizeof(t_tex));
		tex->tex = mlx_xpm_file_to_image(var->lx->mlx, path, \
		&tex->width, &tex->height);
		if (tex->tex)
			tex->ptr = mlx_get_data_addr(tex->tex, \
				&tex->bpp, &tex->line_lenght, &tex->endian);
		if (!tex->tex || !tex->ptr)
		{
			if (tex->tex)
				mlx_destroy_image(var->lx->mlx, tex->tex);
			free(tex);
			return (NULL);
		}
		return (tex);
	}
	return (NULL);
}

void	fill_textures(t_var	*var)
{
	var->tex[0] = fill_texture(var, var->pars->no[1]);
	var->tex[1] = fill_texture(var, var->pars->so[1]);
	var->tex[2] = fill_texture(var, var->pars->we[1]);
	var->tex[3] = fill_texture(var, var->pars->ea[1]);
}

static unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	colors(t_var *var)
{
	char	**ptr;

	ptr = ft_split(var->pars->c[0], ' ');
	var->lx->ceiling = create_rgb(ft_atoi(ptr[1]), \
		ft_atoi(var->pars->c[1]), ft_atoi(var->pars->c[2]));
	ft_free(ptr);
	free(ptr);
	ptr = ft_split(var->pars->f[0], ' ');
	var->lx->floor = create_rgb(ft_atoi(ptr[1]), \
		ft_atoi(var->pars->f[1]), ft_atoi(var->pars->f[2]));
	ft_free(ptr);
	free(ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:41:54 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/24 15:09:19 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_file(t_var *var, int len)
{
	int	i;
	int	fd;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (var->pars->hold[i])
	{	
		j = 0;
		while (var->pars->hold[i][j])
		{
			if (var->pars->hold[i][j] != ' ')
			{
				if (!check_file2(var, i, j, fd) || !check_file3(var, i, j, len))
					break ;
			}
			j++;
		}
		i++;
	}
	if (!var->pars->nn || !var->pars->ss || !var->pars->ww
		|| !var->pars->ee || !var->pars->ff
		|| !var->pars->cc || !var->pars->map1)
		ft_error("Error element not found");
}

void	parsing_init(t_var *var)
{
	var->pars->nn = 0;
	var->pars->ss = 0;
	var->pars->ww = 0;
	var->pars->ee = 0;
	var->pars->ff = 0;
	var->pars->cc = 0;
	var->pars->map1 = 0;
	var->pars->zero = 0;
	var->pars->player = 0;
	var->pars->one = 0;
	var->pars->space = 0;
	var->pars->line = 0;
}
// void	*fill_texture1(t_var *var, char *path)
// {
// 	char	*img;
// 	void	*mlx;
// 	int		img_width;
// 	int		img_height;
// 	if (ft_strncmp(path, ".xpm", 4))
// 		img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
// 	return (img);
// }
// void	fill_texture(t_var	*var)
// {
// 	var->text->img[0] = fill_texture1(var, var->pars->no[1]);
// 	var->text->img[1] = fill_texture1(var, var->pars->so[1]);
// 	var->text->img[2] = fill_texture1(var, var->pars->we[1]);
// 	var->text->img[3] = fill_texture1(var, var->pars->ea[1]);
// }

void	parsing(t_var *var, int ac, char **av)
{
	int		fd;
	int		len;
	int		i;

	i = 0;
	var->pars = malloc(sizeof(t_pars));
	fd = open(av[1], O_RDONLY, 0644);
	ft_error_fd(fd);
	check_extension(ac, av);
	len = lent_map(av[1]);
	var->pars->hold = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		var->pars->hold[i] = ft_join(get_next_line(fd));
		i++;
	}
	var->pars->hold[i] = NULL;
	if (!len)
		ft_error("Error file empty");
	check_file(var, len);
	// fill_texture(var);
}

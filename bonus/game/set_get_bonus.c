/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:28:13 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 16:39:40 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlp_rotation_matrix(double angle, double *x, double *y)
{
	double	tmp;

	tmp = *x;
	*x = cos(angle) * *x + sin(angle) * *y;
	*y = -sin(angle) * tmp + cos(angle) * *y;
}

char	get_map_index(t_var *var, double y, double x)
{
	int	c;

	c = '_';
	if (var->pars->map[(int)y])
		c = var->pars->map[(int)y][(int)x];
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:27:00 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 15:14:35 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	gmie_ne(t_var *var, t_gmie *gm)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (gm->x + i < gm->to_x || gm->y + j > gm->to_y)
	{
		if (get_map_index(var, gm->x + i, gm->y + j) == '1')
			break ;
		i += gm->dx;
		j += gm->dy;
	}
	return (get_map_index(var, gm->x + i, gm->y + j));
}

static char	gmie_es(t_var *var, t_gmie *gm)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (gm->x + i < gm->to_x || gm->y + j < gm->to_y)
	{
		if (get_map_index(var, gm->x + i, gm->y + j) == '1')
			break ;
		i += gm->dx;
		j += gm->dy;
	}
	return (get_map_index(var, gm->x + i, gm->y + j));
}

static char	gmie_sw(t_var *var, t_gmie *gm)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (gm->x + i > gm->to_x || gm->y + j < gm->to_y)
	{
		if (get_map_index(var, gm->x + i, gm->y + j) == '1')
			break ;
		i += gm->dx;
		j += gm->dy;
	}
	return (get_map_index(var, gm->x + i, gm->y + j));
}

static char	gmie_wn(t_var *var, t_gmie *gm)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (gm->x + i > gm->to_x || gm->y + j > gm->to_y)
	{
		if (get_map_index(var, gm->x + i, gm->y + j) == '1')
			break ;
		i += gm->dx;
		j += gm->dy;
	}
	return (get_map_index(var, gm->x + i, gm->y + j));
}

/* Get Map Index Express */
char	gmie(t_var *var, double to_x, double to_y)
{
	char	c;
	t_gmie	gm;

	c = '-';

	gm.x = var->ply->pos_x;
	gm.y = var->ply->pos_y;
	gm.to_x = to_x;
	gm.to_y = to_y;
	gm.dx = (gm.to_x - gm.x) / 1000;
	gm.dy = (gm.to_y - gm.y) / 1000;
	if (gm.dx >= 0 && gm.dy <= 0)
		c = gmie_ne(var, &gm);
	else if (gm.dx >= 0 && gm.dy >= 0)
		c = gmie_es(var, &gm);
	else if (gm.dx <= 0 && gm.dy >= 0)
		c = gmie_sw(var, &gm);
	else if (gm.dx <= 0 && gm.dy <= 0)
		c = gmie_wn(var, &gm);
	return (c);
}

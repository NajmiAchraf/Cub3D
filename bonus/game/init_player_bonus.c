/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:42:48 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 18:09:20 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	set_vectors(t_var *var, double vx, double vy)
{
	var->ply->vx = vx;
	var->ply->vy = vy;
}

static void	set_plans(t_var *var, double plan_x, double plan_y)
{
	var->ply->plan_x = plan_x;
	var->ply->plan_y = plan_y;
}

static void	directions_player(t_var *var, char dir)
{
	if (dir == 'N')
	{
		set_vectors(var, 0, -1);
		set_plans(var, 0.5, 0);
	}
	else if (dir == 'S')
	{
		set_vectors(var, 0, 1);
		set_plans(var, -0.5, 0);
	}
	else if (dir == 'E')
	{
		set_vectors(var, 1, 0);
		set_plans(var, 0, 0.5);
	}
	else if (dir == 'W')
	{
		set_vectors(var, -1, 0);
		set_plans(var, 0, -0.5);
	}
}

static void	change_map(t_var *var, int x, int y)
{
	char	*old;
	char	*new;
	int		i;

	old = ft_strdup(var->pars->map[y]);
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
	free(old);
	free(var->pars->map[y]);
	var->pars->map[y] = new;
}

void	player_set(t_var *var)
{
	int	x;
	int	y;

	y = 0;
	while (var->pars->map[y])
	{
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
				return ;
			}
			x++;
		}
		y++;
	}
}

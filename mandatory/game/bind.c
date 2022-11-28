/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:11:30 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/28 15:33:18 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	execute(int keycode, t_var *var)
{
	if (keycode == KY_A)
	{
		var->ply->move[0] = KY_A;
		var->ply->step_x = -SPEED;
	}
	else if (keycode == KY_D)
	{
		var->ply->move[0] = KY_D;
		var->ply->step_x = SPEED;
	}
	else if (keycode == KY_S)
	{
		var->ply->move[1] = KY_S;
		var->ply->step_y = -SPEED;
	}
	else if (keycode == KY_W)
	{
		var->ply->move[1] = KY_W;
		var->ply->step_y = SPEED;
	}
	else if (keycode == KY_LEFT)
		var->ply->move[2] = KY_LEFT;
	else if (keycode == KY_RIGHT)
		var->ply->move[2] = KY_RIGHT;
}

int	downbind(int keycode, t_var *var)
{
	if (keycode == KY_LEFT || keycode == KY_RIGHT || keycode == KY_A
		|| keycode == KY_S || keycode == KY_D || keycode == KY_W)
		execute(keycode, var);
	return (0);
}

int	upbind(int keycode, t_var *var)
{
	if (keycode == KY_ESC)
	{
		mlx_destroy_window(var->lx->mlx, var->lx->win);
		xite();
	}
	if (keycode == KY_A || keycode == KY_D)
		var->ply->move[0] = -1;
	if (keycode == KY_S || keycode == KY_W)
		var->ply->move[1] = -1;
	if (keycode == KY_LEFT || keycode == KY_RIGHT)
		var->ply->move[2] = -1;
	return (0);
}

int	xite(void)
{
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:19:54 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/26 18:41:14 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	lent_map(char *str)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(str, O_RDWR, 0644);
	ft_error_fd(fd);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	check_f_range1(t_var *var, int i, int k, int num)
{	
	if (i == 0)
	{
		while (var->pars->f[i][k])
		{
			if (var->pars->f[i][k] == 'F')
			{
				num = ft_atoi_plus(var->pars->f[i] + (k + 1));
				break ;
			}
			k++;
		}
	}
	else
		num = ft_atoi_plus(var->pars->f[i]);
	return (num);
}

void	check_f_range(t_var *var, char *str)
{
	int	i;
	int	num;
	int	k;

	i = 0;
	k = 0;
	num = 0;
	while (str[i])
	{	
		if (str[i] == ',')
			k++;
		i++;
	}
	if (k != 2)
		ft_error("Error from F range");
	i = 0;
	k = 0;
	while (var->pars->f[i])
	{
		num = check_f_range1(var, i, k, num);
		if (num < 0 || num > 255)
			ft_error("Error from F range");
		i++;
	}
}

int	check_c_range1(t_var *var, int i, int k, int num)
{
	if (i == 0)
	{
		while (var->pars->c[i][k])
		{
			if (var->pars->c[i][k] == 'C')
			{
				num = ft_atoi_plus(var->pars->c[i] + (k + 1));
				break ;
			}
			k++;
		}
	}
	else
		num = ft_atoi_plus(var->pars->c[i]);
	return (num);
}

void	check_c_range(t_var *var, char *str)
{
	int	i;
	int	num;
	int	k;

	i = 0;
	k = 0;
	num = 0 ;
	while (str[i])
	{	
		if (str[i] == ',')
			k++;
		i++;
	}
	if (k != 2)
		ft_error("Error from C range");
	i = 0;
	k = 0;
	while (var->pars->c[i])
	{
		num = check_c_range1(var, i, k, num);
		if (num < 0 || num > 255)
			ft_error("Error from C range");
		i++;
	}
}

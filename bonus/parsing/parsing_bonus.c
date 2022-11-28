/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:41:54 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/28 10:37:08 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	check_only_space(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			k++;
		i++;
	}
	if (k == i)
		ft_error("Error from only space");
}

void	check_file(t_var *var, int len)
{
	int	i;
	int	j;

	i = 0;
	while (var->pars->hold[i])
	{
		j = 0;
		while (var->pars->hold[i][j])
		{
			if (var->pars->hold[i][j] != ' ')
			{
				if (!check_file2(var, i, j) || !check_file3(var, i, j, len))
					break ;
			}
			j++;
		}
		if (ft_strch(var->pars->hold[i], ' '))
			check_only_space(var->pars->hold[i]);
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

void	parsing(t_var *var, int ac, char **av)
{
	int	fd;
	int	len;
	int	i;

	i = 0;
	var->pars = malloc(sizeof(t_pars));
	fd = open(av[1], O_RDONLY, 0644);
	ft_error_fd(fd);
	check_extension(ac, av);
	len = lent_map(av[1]);
	var->pars->hold = malloc(sizeof(char *) * (len + 1));
	var->pars->map = NULL;
	parsing_init(var);
	while (i < len)
	{
		var->pars->hold[i] = ft_join(get_next_line(fd));
		i++;
	}
	var->pars->hold[i] = NULL;
	close(fd);
	if (!len)
		ft_error("Error file empty");
	check_file(var, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:42:16 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/24 15:03:40 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_join1(void)
{
	char	*ptr;

	ptr = malloc (sizeof(char) * 1);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_join(char *s1)
{
	char	*ptr;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1)
		s1 = ft_join1();
	if (!s1)
		return (NULL);
	ptr = malloc((ft_strlen (s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (ft_strchr(s1, '\n'))
	{
		while (s1[k] != '\n')
		{
			ptr[i] = s1[k];
			i++;
			k++;
		}
		ptr[i] = '\0';
	}	
	free(s1);
	return (ptr);
}

int	ft_atoi_plus(char *str)
{
	size_t	res;
	int		signe;
	size_t	i;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ','
			&& str[i] != ' ' && str[i] != '+')
			ft_error("Error from atoi");
		i++;
	}
	i = 0;
	str = ft_strtrim(str, " ");
	if (ft_strlen(str) > 4)
		ft_error("Error from atoi");
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return (res * signe);
}

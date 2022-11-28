/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:42:16 by sriyani           #+#    #+#             */
/*   Updated: 2022/11/28 10:51:46 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_join1(void)
{
	char	*ptr;

	ptr = malloc (sizeof(char) * 1);
	ptr[0] = '\0';
	return (ptr);
}

char	*alloc_ptr(char *s1)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strchr(s1, '\n'))
		ptr = malloc((ft_strlen (s1)) * sizeof(char));
	else if (ft_strchr(s1, '\0'))
		ptr = malloc((ft_strlen (s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*alloc_ptr2(char *s1, char	*ptr)
{
	int		i;

	i = 0;
	while (s1[i] != '\n')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_join(char *s1)
{
	char	*ptr;
	int		i;

	if (!s1)
		s1 = ft_join1();
	if (!s1)
		return (NULL);
	ptr = alloc_ptr(s1);
	if (ft_strch(s1, '\n'))
		ptr = alloc_ptr2(s1, ptr);
	i = 0;
	if (!ft_strch(s1, '\n'))
	{
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	free(s1);
	return (ptr);
}

int	count_plus(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '+')
			k++;
		i++;
	}
	if (k > 1)
		ft_error("Error from atoi");
	return (i);
}

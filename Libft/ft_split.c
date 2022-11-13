/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:36:14 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/18 13:40:04 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*out;
	int		i;

	out = malloc((n + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (s1[i] && i < (int)n)
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static int	between(char const *s1, char c, int count)
{
	int	i;

	i = 0;
	if (count == 0)
	{
		while (*s1 && *s1 != c)
		{
			s1++;
			i++;
		}
	}
	else
	{
		while (*s1 && *s1 == c)
		{
			s1++;
			i++;
		}
	}
	return (i);
}

static char	**second_process(char **out, char const *s, char c, int i)
{
	char	*tmp;
	int		j;
	int		k;

	k = 0;
	tmp = (char *)s;
	if (*tmp == c)
		tmp += between(tmp, c, 1);
	while (k < i)
	{
		j = between(tmp, c, 0);
		out[k] = ft_strndup(tmp, j);
		if (!out[k])
			return (out);
		if ((k + 1) == i)
			break ;
		tmp = tmp + j;
		j = between(tmp, c, 1);
		tmp = tmp + j;
		k++;
	}
	out[k + 1] = NULL;
	return (out);
}

static int	first_process(char *tmp, char c)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = between(tmp, c, 0);
		if (j == 0)
			break ;
		tmp = tmp + j;
		j = between(tmp, c, 1);
		tmp = tmp + j;
		i += 1;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	*tmp;
	int		i;

	if ((s == 0 && c == '\0') || s == 0)
		return (0);
	out = malloc(sizeof(char *) * (1));
	if (!out)
		return (NULL);
	out[0] = NULL;
	if (s == 0 || *s == '\0')
		return (out);
	tmp = (char *)s;
	if (*tmp == c)
		tmp += between(tmp, c, 1);
	if (*tmp == '\0')
		return (out);
	i = first_process(tmp, c);
	if (i == 0)
		return (out);
	free(out);
	out = (char **)malloc(sizeof(char *) * (i + 1));
	if (!out)
		return (NULL);
	return (second_process(out, s, c, i));
}

/*
int	main(void)
{
	const char	*str = "      split     this for   me  !    ";
	char		ch = ' ';
	char		**ret;

	ret = ft_split(str, ch);
	printf("\nspliter |%c|\nslipted =>", ch);
	for (size_t i = 0; ret[i]; i++)
	{
		printf(" {%s}", ret[i]);
	}
	printf("\n\n");
	return (0);
}
*/

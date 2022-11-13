/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:42:09 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 12:10:53 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*out;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && len > i)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*
int	main(int argc, char **argv)
{
	(void) argc;
	printf("ft_substr(%s, %s, %s) => ", argv[1], argv[2], argv[3]);
	printf("%s\n", ft_substr(argv[1], (unsigned int) ft_atoi(argv[2]),
	 (unsigned int) ft_atoi(argv[3])));
	return (0);
}
*/

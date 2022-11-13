/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:15:38 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 21:12:27 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/*
#include <stdio.h>

void	up(void *c)
{
	int		i;
	char	*s;

	s = (char *)c;
	i = 0;
	while (s[i] != '\0')
	{
		s[i] = s[i] + 32;
		printf("s ==> %c\n", s[i]);
		i++;
	}
	return ;
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew(ft_strdup("1"));
	b = ft_lstnew(ft_strdup("2"));
	c = ft_lstnew(ft_strdup("3"));

	a->next = b;
	b->next = c;
	c->next = NULL;

	ft_lstclear(&a, up);
	return (0);
}
*/

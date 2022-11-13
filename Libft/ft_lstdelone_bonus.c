/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:08:32 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 22:27:14 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
void	zero(void *z)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)z;
	// while (s[i])
	// {
	// 	s[i] = '\0';
	// 	i++;
	// }
	s[0] = '\0';
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew(ft_strdup("1llllll"));
	b = ft_lstnew(ft_strdup("2llllll"));
	c = ft_lstnew(ft_strdup("3llllll"));

	a->next = b;
	b->next = c;
	c->next = NULL;

	ft_lstdelone(a, zero);
	printf("a ==> %s\n", a->content);
	ft_lstdelone(b, zero);
	printf("b ==> %s\n", b->content);
	ft_lstdelone(c, zero);
	printf("c ==> %s\n", c->content);
	return (0);
}
*/

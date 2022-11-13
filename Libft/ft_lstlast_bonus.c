/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:03:03 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 14:04:34 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
int	main(void)
{
	t_list	*alst;

	alst = ft_lstnew("4");
	ft_lstadd_front(&alst, ft_lstnew("3"));
	ft_lstadd_front(&alst, ft_lstnew("2"));
	ft_lstadd_front(&alst, ft_lstnew("1"));
	printf("\n%s\n", ft_lstlast(alst)->content);
}
*/

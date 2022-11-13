/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:19:02 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 14:04:25 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	if (lst)
		i++;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	t_list	*alst;

	alst = ft_lstnew("78");
	ft_lstadd_front(&alst, ft_lstnew("56"));
	ft_lstadd_front(&alst, ft_lstnew("34"));
	ft_lstadd_front(&alst, ft_lstnew("21"));

	printf("\n list content number =>> %d\n", ft_lstsize(alst));
}
*/

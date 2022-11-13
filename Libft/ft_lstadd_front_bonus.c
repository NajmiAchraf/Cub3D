/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:19:27 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 21:39:46 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

/*
int	main(void)
{
	t_list	*alst;

	alst = ft_lstnew("78");
	ft_lstadd_front(&alst, ft_lstnew("56"));
	ft_lstadd_front(&alst, ft_lstnew("34"));
	while (alst->next)
	{
		printf("%s\n", alst->content);
		alst = alst->next;
	}
	printf("%s\n", alst->content);
}
*/

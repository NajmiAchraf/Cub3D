/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:48:37 by anajmi            #+#    #+#             */
/*   Updated: 2021/11/20 21:38:59 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else
		(ft_lstlast(*alst))->next = new;
}

/*
#include <stdio.h>
int	main(void)
{
	t_list	*alst;

	alst = ft_lstnew("1");
	ft_lstadd_back(&alst, ft_lstnew("2"));
	ft_lstadd_back(&alst, ft_lstnew("3"));
	ft_lstadd_back(&alst, ft_lstnew("4"));
	while (alst->next)
	{
		printf("%s\n", alst->content);
		alst = alst->next;
	}
	printf("%s\n", alst->content);
}
*/

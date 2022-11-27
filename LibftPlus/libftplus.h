/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftplus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:58:11 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/27 17:43:45 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPLUS_H
# define LIBFTPLUS_H
# include <stddef.h>
# include <stdlib.h>
# include "../Libft/libft.h"

int		ft_strch(char *src, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **ptr);
void	show_help(void);
void	show_control(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftplus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:58:11 by anajmi            #+#    #+#             */
/*   Updated: 2022/11/23 15:18:16 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPLUS_H
# define LIBFTPLUS_H
# include <stddef.h>
# include <stdlib.h>
# include "../Libft/libft.h"

int		ft_strch(char c, char const *src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **ptr);
#endif
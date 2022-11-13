/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:13:24 by anajmi            #+#    #+#             */
/*   Updated: 2022/10/06 14:55:26 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

void	*ft_callocgnl(size_t count, size_t size);
char	*ft_strjoingnl(char *s1, char *s2, int readsize);
char	*ft_substrgnl(char *s, unsigned int start, size_t len);
size_t	ft_strlengnl(const char *s);
char	*ft_strchrgnl(const char *s, int c);

void	freeing(char **to_free);
char	*error(char *buffer, char **save);
char	*get_next_line(int fd);

#endif

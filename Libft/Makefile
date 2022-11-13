# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 20:14:52 by anajmi            #+#    #+#              #
#    Updated: 2022/06/22 12:50:23 by anajmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRC_PART1 =	\
	./ft_atoi.c		\
	./ft_isalpha.c	\
	./ft_isdigit.c	\
	./ft_isalnum.c	\
	./ft_isascii.c	\
	./ft_isprint.c	\
	./ft_toupper.c	\
	./ft_tolower.c	\
	./ft_bzero.c	\
	./ft_calloc.c	\
	./ft_memchr.c	\
	./ft_memcmp.c	\
	./ft_memcpy.c	\
	./ft_memmove.c	\
	./ft_memset.c	\
	./ft_strchr.c	\
	./ft_strdup.c	\
	./ft_strlcat.c	\
	./ft_strlcpy.c	\
	./ft_strrchr.c	\
	./ft_strlen.c	\
	./ft_strncmp.c	\
	./ft_strnstr.c

SRC_PART2 = 	\
	./ft_substr.c		\
	./ft_strjoin.c		\
	./ft_strtrim.c		\
	./ft_split.c		\
	./ft_itoa.c			\
	./ft_strmapi.c		\
	./ft_striteri.c		\
	./ft_putchar_fd.c	\
	./ft_putstr_fd.c	\
	./ft_putendl_fd.c	\
	./ft_putnbr_fd.c

BONUS = \
	./ft_lstnew_bonus.c	 	\
	./ft_lstadd_front_bonus.c	\
	./ft_lstsize_bonus.c		\
	./ft_lstlast_bonus.c		\
	./ft_lstadd_back_bonus.c	\
	./ft_lstclear_bonus.c		\
	./ft_lstdelone_bonus.c

PARTS = $(SRC_PART1) $(SRC_PART2)

OBJS = $(PARTS:.c=.o)

OBBS = $(BONUS:.c=.o)

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

.PHONY : all clean fclean re bonus

%.o: %.c
	@gcc $(CFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "$(C_GREEN)[LIBFT CREATED!]$(C_RES)"

clean :
	@rm -f $(OBJS) $(OBBS)
	@echo "$(C_RED)[LIBFT OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(C_RED)[LIBFT ARCHIVE DELETED!]$(C_RES)"

re : fclean all
	
bonus : $(OBBS)
	@ar -rc $(NAME) $(OBBS)
	@echo "$(C_L_BLUE)[LIBFT BONUS CREATED!]$(C_RES)"
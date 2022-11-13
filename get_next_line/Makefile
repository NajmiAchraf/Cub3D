# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 20:14:52 by anajmi            #+#    #+#              #
#    Updated: 2022/10/06 14:45:57 by anajmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CFLAGS = -Wall -Werror -Wextra

SRC =	\
	./get_next_line.c	\
	./get_next_line_utils.c

OBJS = $(SRC:.c=.o)

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

.PHONY : all clean fclean re

%.o: %.c
	@gcc $(CFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "$(C_GREEN)[GET NEXT LINE CREATED!]$(C_RES)"

clean :
	@rm -f $(OBJS) $(OBBS)
	@echo "$(C_RED)[GET NEXT LINE OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(C_RED)[GET NEXT LINE ARCHIVE DELETED!]$(C_RES)"

re : fclean all

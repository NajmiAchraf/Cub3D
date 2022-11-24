# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 17:43:40 by anajmi            #+#    #+#              #
#    Updated: 2022/11/24 15:48:55 by sriyani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -fsanitize=address # -Wall -Werror -Wextra

CC = cc 

PARSE = \
		./parsing/parsing.c\
		./parsing/parsing_check.c\
		./parsing/parsing_check1.c\
		./parsing/parsing1.c\
		./parsing/parsing2.c\
		./parsing/parsing3.c\
		./parsing/parsing4.c\
		./parsing/parsing_utils.c\
		./parsing/parsing_utils1.c\

EXEC = \
	./cub3d.c	\
	./help.c	\

SRCS = $(PARSE) $(EXEC)

OBJ = $(SRCS:.c=.o)

ifeq ($(shell uname -s), Linux)
  MLXINC	= -I/usr/local/include -Imlx_linux -O3
  MLXLIB	= -lmlx -lXext -lX11 -lm -lz
else
  MLXINC	= -Imlx
  MLXLIB	= -lmlx -framework OpenGL -framework AppKit
endif

#*******************************#
#			LIBFT				#
#*******************************#

LIBFT = ./Libft
ARLIB = $(LIBFT)/libft.a
ALLIBFT = make -C $(LIBFT)
CLEANLIBFT = make clean -C $(LIBFT)
FCLEANLIBFT = rm -f $(ARLIB)
RELIBFT = make re -C $(LIBFT)

#*******************************#
#			LIBFT PLUS			#
#*******************************#

LIBPL = ./LibftPlus
ARPLS = $(LIBPL)/libftplus.a
ALLIBPL = make -C $(LIBPL)
CLEANLIBPL = make clean -C $(LIBPL)
FCLEANLIBPL = rm -f $(ARPLS)
RELIBPL = make re -C $(LIBPL)


#*******************************#
#			GNL					#
#*******************************#

GNL = ./get_next_line
ARGNL = $(GNL)/get_next_line.a
ALLGNL = make -C $(GNL)
CLEANGNL = make clean -C $(GNL)
FCLEANGNL = rm -f $(ARGNL)
REGNL = make re -C $(GNL)

#*******************************#
#			COLORS				#
#*******************************#

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

#*******************************#
#			MAKING				#
#*******************************#

.PHONY : all clean fclean re bonus

%.o: %.c
	@$(CC) $(CFLAGS) $(MLXINC) -c $^ -o $@

all : $(NAME) run

$(NAME) : $(OBJ)
	$(ALLIBFT)
	$(ALLIBPL)
	$(ALLGNL)
	@$(CC) $(CFLAGS) $(OBJ) $(ARLIB) $(ARPLS) $(ARGNL) $(MLXLIB) -o $(NAME)
	@echo "$(C_GREEN)[CUB3D MANDATORY CREATED!]$(C_RES)"

clean :
	@$(CLEANLIBFT)
	@$(CLEANLIBPL)
	@$(CLEANGNL)
	@rm -f $(OBJ)
	@echo "$(C_RED)[CUB3D OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@$(FCLEANLIBFT)
	@echo "$(C_RED)[LIBFT ARCHIVE DELETED!]$(C_RES)"
	@$(FCLEANLIBPL)
	@echo "$(C_RED)[LIBFT PLUS ARCHIVE DELETED!]$(C_RES)"
	@$(FCLEANGNL)
	@echo "$(C_RED)[GET NEXT LINE ARCHIVE DELETED!]$(C_RES)"
	@rm -f $(NAME)
	@echo "$(C_RED)[CUB3D EXECUTABLES DELETED!]$(C_RES)"

re : fclean all

bonus :
	@echo "$(C_RED)[CUB3D BONUS NOT EXIST YET!]$(C_RES)"

run :
	@echo "$(C_L_BLUE)[RUN CUB3D!]$(C_RES)"
	@./cub3D map.cub

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 17:43:40 by anajmi            #+#    #+#              #
#    Updated: 2022/11/28 19:59:40 by anajmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

CFLAGS = -Wall -Werror -Wextra

CC = cc

PARSE = \
		./mandatory/parsing/parsing.c			\
		./mandatory/parsing/parsing_check.c		\
		./mandatory/parsing/parsing_check1.c	\
		./mandatory/parsing/parsing1.c			\
		./mandatory/parsing/parsing2.c			\
		./mandatory/parsing/parsing3.c			\
		./mandatory/parsing/parsing4.c			\
		./mandatory/parsing/parsing_utils.c		\
		./mandatory/parsing/parsing_utils1.c	\

EXEC = \
	./mandatory/game/bind.c					\
	./mandatory/game/dda.c					\
	./mandatory/game/events.c				\
	./mandatory/game/init_colors.c			\
	./mandatory/game/init_player.c			\
	./mandatory/game/raycasting.c			\
	./mandatory/game/set_get.c				\
	./mandatory/cub3d.c						\

PARSE_BONUS = \
		./bonus/parsing/parsing_bonus.c			\
		./bonus/parsing/parsing_check_bonus.c	\
		./bonus/parsing/parsing_check1_bonus.c	\
		./bonus/parsing/parsing1_bonus.c		\
		./bonus/parsing/parsing2_bonus.c		\
		./bonus/parsing/parsing3_bonus.c		\
		./bonus/parsing/parsing4_bonus.c		\
		./bonus/parsing/parsing_utils_bonus.c	\
		./bonus/parsing/parsing_utils1_bonus.c	\

EXEC_BONUS = \
	./bonus/game/bind_bonus.c			\
	./bonus/game/dda_bonus.c			\
	./bonus/game/draw_mini_map_bonus.c	\
	./bonus/game/events_bonus.c			\
	./bonus/game/init_colors_bonus.c	\
	./bonus/game/init_player_bonus.c	\
	./bonus/game/raycasting_bonus.c		\
	./bonus/game/set_get_bonus.c		\
	./bonus/cub3d_bonus.c				\

SRCS = $(PARSE) $(EXEC)

OBJ = $(SRCS:.c=.o)

SRCS_BONUS = $(PARSE_BONUS) $(EXEC_BONUS)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

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

all : $(NAME)

$(NAME) : $(OBJ)
	$(ALLIBFT)
	$(ALLIBPL)
	$(ALLGNL)
	@$(CC) $(CFLAGS) $(OBJ) $(ARLIB) $(ARPLS) $(ARGNL) $(MLXLIB) -o $(NAME)
	@echo "$(C_GREEN)[CUB3D MANDATORY CREATED!]$(C_RES)"

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(ALLIBFT)
	$(ALLIBPL)
	$(ALLGNL)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(ARLIB) $(ARPLS) $(ARGNL) $(MLXLIB) -o $(NAME_BONUS)
	@echo "$(C_GREEN)[CUB3D BONUS CREATED!]$(C_RES)"

clean :
	@$(CLEANLIBFT)
	@$(CLEANLIBPL)
	@$(CLEANGNL)
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@echo "$(C_RED)[CUB3D OBJECTS DELETED!]$(C_RES)"

fclean : clean
	@$(FCLEANLIBFT)
	@echo "$(C_RED)[LIBFT ARCHIVE DELETED!]$(C_RES)"
	@$(FCLEANLIBPL)
	@echo "$(C_RED)[LIBFT PLUS ARCHIVE DELETED!]$(C_RES)"
	@$(FCLEANGNL)
	@echo "$(C_RED)[GET NEXT LINE ARCHIVE DELETED!]$(C_RES)"
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(C_RED)[CUB3D EXECUTABLES DELETED!]$(C_RES)"

re : fclean all

run :
	@echo "$(C_L_BLUE)[RUN CUB3D!]$(C_RES)"
	@./cub3D tools/maps/map.cub

runbonus :
	@echo "$(C_L_BLUE)[RUN CUB3D BONUS!]$(C_RES)"
	@./cub3D_bonus tools/maps/map.cub

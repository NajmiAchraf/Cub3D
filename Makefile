# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 17:43:40 by anajmi            #+#    #+#              #
#    Updated: 2022/11/27 18:03:43 by anajmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

CFLAGS = -Wall -Werror -Wextra # -fsanitize=address

CC = cc

PARSE = \
		parsing/parsing.c			\
		parsing/parsing_check.c		\
		parsing/parsing_check1.c	\
		parsing/parsing1.c			\
		parsing/parsing2.c			\
		parsing/parsing3.c			\
		parsing/parsing4.c			\
		parsing/parsing_utils.c		\
		parsing/parsing_utils1.c	\

EXEC = \
	game/bind.c					\
	game/dda.c					\
	game/events.c				\
	game/init_colors.c			\
	game/init_player.c			\
	game/raycasting.c			\
	game/set_get.c				\
	cub3d.c						\

PARSE_BONUS = \
		parsing/parsing_bonus.c			\
		parsing/parsing_check_bonus.c	\
		parsing/parsing_check1_bonus.c	\
		parsing/parsing1_bonus.c		\
		parsing/parsing2_bonus.c		\
		parsing/parsing3_bonus.c		\
		parsing/parsing4_bonus.c		\
		parsing/parsing_utils_bonus.c	\
		parsing/parsing_utils1_bonus.c	\

EXEC_BONUS = \
	game/bind_bonus.c			\
	game/dda_bonus.c			\
	game/draw_mini_map_bonus.c	\
	game/events_bonus.c			\
	game/init_colors_bonus.c	\
	game/init_player_bonus.c	\
	game/raycasting_bonus.c		\
	game/set_get_bonus.c		\
	cub3d_bonus.c				\

SRCS = ./mandatory/$(PARSE) ./mandatory/$(EXEC)

OBJ = $(SRCS:.c=.o)

SRCS_BONUS = ./bonus/$(PARSE_BONUS) ./bonus/$(EXEC_BONUS)

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

all : $(NAME) run

$(NAME) : $(OBJ)
	$(ALLIBFT)
	$(ALLIBPL)
	$(ALLGNL)
	@$(CC) $(CFLAGS) $(OBJ) $(ARLIB) $(ARPLS) $(ARGNL) $(MLXLIB) -o $(NAME)
	@echo "$(C_GREEN)[CUB3D MANDATORY CREATED!]$(C_RES)"

bonus : $(NAME_BONUS) runbonus

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
	@echo "$(C_L_BLUE)[RUN CUB3D!]$(C_RES)"
	@./cub3D_bonus tools/maps/map.cub

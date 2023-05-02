# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 15:23:45 by iamongeo          #+#    #+#              #
#    Updated: 2023/05/02 02:00:49 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= 	src/

_SRCS		= 	fdf_main.c	\
			load_map2.c	\
			fdf_map_utils.c	\
			camera_utils.c	\
			viewport_utils.c	\
			mouse_events_handlers.c	\
			mlx_draw_line_z_shift.c

INCLS		= includes/

SRCS		= $(addprefix $(SRC_DIR), $(_SRCS))

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O2

NAME		= fdf

ifeq ($(shell uname -s), Linux)
	MINILIBX_PATH	= minilibx/minilibx-linux/
	LIBMLX		= $(MINILIBX_PATH)libmlx.a
	FRAMEWORKS	= -lm -lX11 -lXext

endif
ifeq ($(shell uname -s), Darwin)
	MINILIBX_PATH	= minilibx/minilibx_macos/
	LIBMLX			= $(MINILIBX_PATH)libmlx.a
	FRAMEWORKS		= -lm -framework OpenGL -framework Appkit
endif

LIBFT		= libft/libft.a
LIBMLXADDS	= mlx_addons/libmlxadds.a
LIBMTX		= mtxlib/libmtx.a
LIBS		= $(LIBMLXADDS) $(LIBMTX) $(LIBFT) $(LIBMLX)


SUBMODULES	= $(MINILIBX_PATH)

%.o:	%.c
	$(CC) $(CFLAGS) -I$(INCLS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -I$(INCLS) $(OBJS) $(FRAMEWORKS) -o $(NAME) $(LIBS) 

$(NAME_BONUS):	$(LIBS) $(OBJ_COM) $(OBJ_B)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJ_COM) $(OBJ_B) -o $(NAME_BONUS) $(LIBS)

bonus:	$(NAME_BONUS)

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

$(SUBMODULES):
	git submodule init
	git submodule update --init --remote

$(LIBFT):
	make -C libft/
	make -C libft/ bonus
$(LIBMTX):
	make -C mtxlib/

$(LIBMLX): $(SUBMODULES)
	@make -C $(MINILIBX_PATH)

$(LIBMLXADDS):
	make -C mlx_addons/

re:	fclean all

.PHONY:	all re clean fclean 

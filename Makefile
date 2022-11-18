
SRC_DIR		= 	src/

_SRCS		= 	fdf_main.c	\
				load_map2.c

INCLS		= includes/

SRCS		= $(addprefix $(SRC_DIR), $(_SRCS))

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O2

NAME		= fdf

ifeq ($(shell uname -s), Linux)
	FRAMEWORKS	= -lm -lmlx -lX11 -lXext
endif
ifeq ($(shell uname -s), Darwin)
	FRAMEWORKS	= -framework OpenGL -framework Appkit -lmlx
endif

LIBFT		= libft/libft.a
LIBMLXADDS	= mlx_addons/libmlxadds.a
LIBMTX		= mtxlib/libmtx.a
LIBS		= $(LIBFT) $(LIBMLXADDS) $(LIBMTX)

%.o:	%.c
	$(CC) $(CFLAGS) -I$(INCLS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) -o $(NAME) $(LIBS)

$(NAME_BONUS):	$(LIBS) $(OBJ_COM) $(OBJ_B)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJ_COM) $(OBJ_B) -o $(NAME_BONUS) $(LIBS)

bonus:	$(NAME_BONUS)

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

$(LIBFT):
	make -C libft/
$(LIBMTX):
	make -C mtxlib/
$(LIBMLXADDS):
	make -C mlx_addons/

re:	fclean all

.PHONY:	all re clean fclean 

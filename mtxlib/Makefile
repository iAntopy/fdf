SRC_DIR	= src

SRCS	= $(wildcard $(SRC_DIR)/*/*.c)# mtx_create/* mtx_ufuncs/* mtx_display/* mtx_mem/* miniLibft/*


OBJS	= $(SRCS:.c=.o)

INCLS	= includes/

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INCLS)

AR	= ar -rcs

NAME	= libmtx.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
#	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

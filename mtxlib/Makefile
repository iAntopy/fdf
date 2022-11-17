# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 23:23:37 by iamongeo          #+#    #+#              #
#    Updated: 2022/11/16 23:31:22 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= src
LIBFT_DIR	= ../libft/

SRCS	= $(wildcard $(SRC_DIR)/*/*.c)\
		  $(wildcard $(SRC_DIR)/mtx_math/*opps/*.c)\
		  $(wildcard $(SRC_DIR)/mtx_ufuncs/*copps/*.c)

OBJS	= $(SRCS:.c=.o)

INCLS	= includes/

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INCLS)

AR	= ar -rcs

LIBFT	= $(LIBFT_DIR)/libft.a

NAME	= libmtx.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)# $(LIBFT)
#	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

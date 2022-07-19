# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_includes.sh                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 19:27:55 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/18 20:44:35 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MINILIBX_LINUX_PATH='../../minilibx/minilibx-linux'
#MINILIBX_MACOS_PATH='../../minilibx/minilibx-macos'
CURR_PATH=$(dirname "$(readlink -f "$0")")

MLX_ADDONS_PATH='../../minilibx/mlx_addons/includes'

MTXLIB_PATH='../../mtxlib/includes'

LIBFT_PATH='../../libft'

if [ -d $MLX_ADDONS_PATH ]; then
	cd $MLX_ADDONS_PATH
	cp *.h $CURR_PATH
	cd $CURR_PATH
else
	echo "Missing mlx_addons headers"
fi

if [ -d $MTXLIB_PATH ]; then
	cd $MTXLIB_PATH
	cp mtxlib.h $CURR_PATH
	cd $CURR_PATH
else
	echo "Missing mtxlib header"
fi

if [ -d $MTXLIB_PATH ]; then
	cd $LIBFT_PATH
	cp libft.h $CURR_PATH
	cp ft_printf.h $CURR_PATH
	cd $CURR_PATH
else
	echo "Missing libft headers"
fi

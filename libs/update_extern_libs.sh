# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_libs.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:11:09 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/18 21:18:59 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURR_PATH=$(dirname "$(readlink -f "$0")")

MTXLIB_PATH='../../mtxlib'
MINILIBX_LINUX_PATH='../../minilibx/minilibx-linux'
MINILIBX_MACOS_PATH='../../minilibx/minilibx-macos'
LIBFT_PATH='../../libft'

if [ -d $MINILIBX_LINUX_PATH -a -f $MINILIBX_LINUX_PATH"/libmlx.a" ]; then
	echo "creating libmlx_linux.a link"
	ln $MINILIBX_LINUX_PATH'/libmlx.a' $CURR_PATH'/libmlx_linux.a'
#	cd $MINILIBX_LINUX_PATH
#	cp libmlx.a $CURR_PATH"/libmlx_linux.a"
#	cd $CURR_PATH
else
	echo "Missing minilibx linux library"
fi

if [ -d $MINILIBX_MACOS_PATH -a -f $MINILIBX_MACOS_PATH"/libmlx.a" ]; then
	echo "creating libmlx_macos.a link"
	ln $MINILIBX_MACOS_PATH"/libmlx.a"  $CURR_PATH'/libmlx_macos.a'
#	cd $MINILIBX_MACOS_PATH
#	cp libmlx.a $CURR_PATH"/libmlx_macos.a"
#	cd $CURR_PATH
else
	echo "Missing minilibx macos library"
fi

if [ -d $MTXLIB_PATH -a -f $MTXLIB_PATH"/libmtx.a" ]; then
	echo "creating libmtx.a link"
	ln $MTXLIB_PATH"/libmtx.a" $CURR_PATH'/libmtx.a'
#	cd $MTXCURR_PATH
#	cp libmtx.a $CURR_PATH
#	cd $CURR_PATH
else
	echo "Missing mtxlib library"
fi

if [ -d $LIBFT_PATH -a -f $LIBFT_PATH"/libft.a" ]; then
	echo "creating libft.a link"
	ln $LIBFT_PATH"/libft.a" $CURR_PATH'/libft.a'
#	cd $LIBFT_PATH
#	cp libft.a $CURR_PATH
#	cd $CURR_PATH
else
	echo "Missing libft library"
fi

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_libs.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 17:11:09 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/19 16:34:43 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURR_PATH=$(dirname "$(readlink -f "$0")")

MTXLIB_PATH='../../mtxlib'
ZOOBAG_PATH='../../Zoobag_Renderer'
LIBFT_PATH='../../libft'


# ---[ LINKING ]---

if [ -d $ZOOBAG_PATH -a -f $ZOOBAG_PATH"/libzoo.a" ]; then
	echo "creating libzoo.a link"
	ln $ZOOBAG_PATH"/libzoo.a" $CURR_PATH
else
	echo "Missing Zoobag Renderer library"
fi

if [ -d $MTXLIB_PATH -a -f $MTXLIB_PATH"/libmtx.a" ]; then
	echo "creating libmtx.a link"
	ln $MTXLIB_PATH"/libmtx.a" $CURR_PATH'/libmtx.a'
else
	echo "Missing mtxlib library"
fi

if [ -d $LIBFT_PATH -a -f $LIBFT_PATH"/libft.a" ]; then
	echo "creating libft.a link"
	ln $LIBFT_PATH"/libft.a" $CURR_PATH'/libft.a'
else
	echo "Missing libft library"
fi

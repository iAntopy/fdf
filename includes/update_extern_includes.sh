# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_includes.sh                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 19:27:55 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/19 16:35:56 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURR_PATH=$(dirname "$(readlink -f "$0")")

ZOOBAG_PATH='../../Zoobag_Renderer/includes'
MTXLIB_PATH='../../mtxlib/includes'
LIBFT_PATH='../../libft'


# >---[ LINKING ]---<
if [ -d $ZOOBAG_PATH ]; then
	cd $ZOOBAG_PATH
	cp *.h $CURR_PATH
	cd $CURR_PATH
else
	echo "Missing Zoobag headers"
fi

if [ -d $MTXLIB_PATH ]; then
	cd $MTXLIB_PATH
	cp mtxlib.h $CURR_PATH
	cd $CURR_PATH
else
	echo "Missing mtxlib header"
fi

if [ -d $LIBFT_PATH ]; then
	cd $LIBFT_PATH
	cp libft.h $CURR_PATH
	cp ft_printf.h $CURR_PATH
	cd $CURR_PATH
else
	echo "Missing libft headers"
fi

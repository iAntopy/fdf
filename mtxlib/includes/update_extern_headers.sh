# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_headers.sh                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 19:12:02 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/18 20:42:49 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CURR_PATH=$(dirname "$(readlink -f "$0")")

LIBFT_PATH='../../libft'

if [ -d $LIBFT_PATH ]; then
	cd $LIBFT_PATH
	cp *.h $CURR_PATH
	cd $CURR_PATH
else
	echo "libft path not found."
fi

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update_extern_libs.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 02:38:33 by iamongeo          #+#    #+#              #
#    Updated: 2022/07/20 02:42:09 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

CURR_PATH=$(dirname "$(readlink "$0")")
LIBFT_PATH='../../libft'

if [ $1 = 're' ]; then
	echo "Deleting and relinking libraries."
	rm *.a
fi

if [ -d $LIBFT_PATH -a -f $LIBFT_PATH"/libft.a" ]; then
	ln $LIBFT_PATH"/libft.a" libft.a
else
	echo "Missing libft.a"
fi

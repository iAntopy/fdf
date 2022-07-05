/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:56:12 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/29 17:57:31 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mtxlib.h"

//only inits full arrays not views.
int	mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols)
{
	if (!mtx || !mtx->arr || mtx->shape[0] != rows || mtx->shape[1] != cols)
		return (0);
	ft_memcpy(mtx->arr, arr, mtx_sizeof_array(mtx));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_reshape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:36:35 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:17:20 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_reshape(t_mtx *mtx, int rows, int cols)
{
	int	dsize;

	if (!mtx || mtx->is_view || mtx->is_transposed)
		return (MTX_ERROR("no input or is view/trans"));
	if ((rows * cols) != (mtx->shape[0] * mtx->shape[1]))
		return (MTX_ERROR("incompatible in/out shapes"));
	mtx->shape[0] = rows;
	mtx->shape[1] = cols;
	dsize = mtx_get_dsize(mtx->dtype);
	if ((rows == 1) || (cols == 1))
	{
		rows = (rows > 1) * rows + (cols > 1) * cols;
		cols = 1;
		mtx->ndims = 1;
		mtx->strides[0] = dsize;
		mtx->strides[1] = 0;
	}
	else
	{
		mtx->ndims = 2;
		mtx->strides[0] = dsize * cols;
		mtx->strides[1] = dsize;	
	}
	return (mtx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:47:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/12 16:03:33 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_setup_1d(t_mtx *mtx, int rows, int cols, size_t stride)
{
	mtx->ndims = (unsigned char)1;
	if ((rows > 1) || (cols > 1))
		mtx->shape[0] = (rows > 1) * rows + (cols > 1) * cols;
	else
		mtx->shape[0] = 1;
	mtx->shape[1] = 1;
	mtx->strides[0] = stride;
	mtx->strides[1] = 0;
	mtx->is_view = 0;
	mtx->is_transposed = 0;
	mtx->swap = NULL;
	mtx->offset = 0;
}

void	__mtx_setup_2d(t_mtx *mtx, int rows, int cols, size_t stride)
{	
	mtx->ndims = (unsigned char)2;
	mtx->shape[0] = rows;
	mtx->shape[1] = cols;
	mtx->strides[1] = stride;
	mtx->strides[0] = cols * stride;
	mtx->is_view = 0;
	mtx->is_transposed = 0;
	mtx->swap = NULL;
	mtx->offset = 0;
}

t_mtx	*mtx_create_empty(int rows, int cols, int dtype)
{
	t_mtx	*mtx;
	size_t	dsize;

	if (rows < 1 || cols < 1 || !mtx_isvalid_dtype(dtype))//!(dtype == DTYPE_I || dtype == DTYPE_F))
		return (MTX_ERROR("invalid inputs"));
	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (MTX_ERROR("malloc error"));
	mtx->ndims = (unsigned char)((rows > 1) + (cols > 1));
	dsize = mtx_get_dsize(dtype);
	mtx->dtype = dtype;
	mtx->arr = NULL;
	mtx->swap = NULL;
	if (rows == 1 || cols == 1)
		__mtx_setup_1d(mtx, rows, cols, dsize);
	else
		__mtx_setup_2d(mtx, rows, cols, dsize);
	if (!malloc_free_p(dsize * rows * cols, (void **)&(mtx->arr)))
		return (malloc_free(0, (void **)&mtx));
	mtx->swap = NULL;
	mtx->view_ptr = &mtx->arr;
	return (mtx);
}

t_mtx	*mtx_create_zeros(int rows, int cols, int dtype)
{
	t_mtx		*mtx;
	
	mtx = mtx_create_empty(rows, cols, dtype);
	if (!mtx)
		return (MTX_ERROR("malloc error"));
	__mtx_fill_zeros(mtx);
	return (mtx);
}

t_mtx	*mtx_create_array(void *arr, int rows, int cols, int dtype)
{
	t_mtx		*mtx;

	printf("arr ptr : %p\n", arr);
	if (!arr)
		return (MTX_ERROR("no array provided"));
	mtx = mtx_create_empty(rows, cols, dtype);
	if (!mtx)
		return (MTX_ERROR("malloc error"));
	if (!mtx_init_as_array(mtx, arr, rows, cols))
	{
		mtx_clear(&mtx);
		return (MTX_ERROR("failed to copy arr data"));
	}
	return (mtx);
}

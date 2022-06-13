/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_create_2d_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:42:50 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/12 23:52:39 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_create_emtpy_2d_f(int rows, int cols, int dtype)
{
	t_mtx	*mtx;
	int		i;

	if (rows < 1 || cols < 1)
	{
		perror("mtx_creat_empty : Invalid nb of rows or cols ");
		return (NULL);
	}
	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)(rows > 1 + cols > 1);
	if (dtype == DTYPE_I || dtype == DTYPE_F)
	{
		perror("mtx_creat_empty : Invalid dtype ");
		return (NULL);
	}
	mtx->dtype = dtype;
	if (rows == 1 || rows == 1)
	{
		mtx->ndims = (unsigned char)1;
		mtx->shape[0] = (rows > 1) * rows + (cols > 1) * cols;
		mtx->strides[0] = sizeof(float);
	}
	else
	{
		mtx->ndims = (unsigned char)2;
		mtx->shape[0] = rows;
		mtx->shape[1] = cols;
		mtx->strides[1] = sizeof(float);
		mtx->strides[0] = cols * sizeof(float);
	}
	if (!malloc_free_p(sizeof(float) * rows * cols, (void **)&(mtx->arr)))
		return (malloc_free(0, (void **)&mtx));
	return (mtx);
}

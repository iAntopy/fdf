/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_create_2d_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:42:50 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/12 22:39:59 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_create_1x2_i(int arr[2])
{
	t_mtx	*mtx;
	int		*marr;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	
	mtx->ndims = (unsigned char)1;
	mtx->dtype = DTYPE_I;
	mtx->shape[0] = 2;
	mtx->strides[0] = sizeof(int);

	if (!malloc_free_p(sizeof(int) * 2, (void **)&marr))
		return (malloc_free(0, (void **)&mtx));
	marr[0] = arr[0];
	marr[1] = arr[1];
	mtx->arr = marr;
	return (mtx);
}

t_mtx	*mtx_create_2x2_i(int arr[2][2])
{
	t_mtx	*mtx;
	int		*marr;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)2;
	mtx->dtype = DTYPE_I;
	mtx->shape[0] = 2;
	mtx->shape[1] = 2;
	mtx->strides[1] = sizeof(int);
	mtx->strides[0] = 2 * mtx->strides[1];
	if (!malloc_free_p(sizeof(int) * 4, (void **)&marr))
		return (malloc_free(0, (void **)&mtx));
	marr[0] = arr[0][0];
	marr[1] = arr[0][1];
	marr[2] = arr[1][0];
	marr[3] = arr[1][1];
	mtx->arr = marr;
	return (mtx);
}

t_mtx	*mtx_create_nx2_i(int n, int *arr)
{
	t_mtx	*mtx;
	int		*marr;
	int		i;

	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)2;
	mtx->dtype = DTYPE_I;
	mtx->shape[0] = n;
	mtx->shape[1] = 2;
	mtx->strides[1] = sizeof(int);
	mtx->strides[0] = 2 * sizeof(int);
	if (!malloc_free_p(sizeof(int) * n * 2, (void **)&marr))
		return (malloc_free(0, (void **)&mtx));
	i = -1;
	while (++i < n)
	{
		marr[2 * i] = arr[2 * i];
		marr[2 * i + 1] = arr[2 * i + 1];
	}
	mtx->arr = marr;
	return (mtx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:01:06 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/19 20:30:09 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Assumes filled with zeros.
void	__fill_identity_i(int n, int *arr)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		*(arr++) = 1;
		arr += n;
	}
}

// Assumes filled with zeros.
void	__fill_identity_f(int n, float *arr)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		*(arr++) = 1;
		arr += n;
	}
}

// Assumes filled with zeros.
void	_mtx_fill_identity_i(t_mtx *mtx)
{
	int	n;

	n = mtx->shape[0];
	while (n)
	{
		n--;
		*(int *)_mtx_idx(mtx->arr, mtx->strides, n, n) = 1;
	}
}

// Assumes filled with zeros.
void	_mtx_fill_identity_f(t_mtx *mtx)
{
	int	n;

	n = mtx->shape[0];
	while (n)
	{
		n--;
		*(float *)_mtx_idx(mtx->arr, mtx->strides, n, n) = 1;
	}
}

t_mtx	*mtx_identity(int n, t_mtx *out, int dtype)
{
	t_mtx	*ret;

	if (n < 1)
		return (MTX_ERROR("invalid negative shape value"));
	ret = out;
	if (!ret)
		ret = mtx_create_empty(n, n, dtype);
	else if (out->shape[0] != out->shape[1])
		return (MTX_ERROR("output mtx must be symetrical"));
	if (!ret)
		return (MTX_ERROR("malloc error"));
	if (ret->is_view)
		_mtx_fill_zeros(ret);
	else
		__mtx_fill_zeros(ret);
	if (dtype == DTYPE_I)
		_mtx_fill_identity_i(ret);
	else if (dtype == DTYPE_F)
		_mtx_fill_identity_f(ret);
	return (ret);
}

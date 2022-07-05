/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:52:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:17:08 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// CAN USE VIEW IN/OUT. len MUST BE initialized at 0.
void	_mtx_norm_apply(t_mtx *mtx, t_mtx *out, float len)
{
	int		i;
	int		j;
	float	*oarr;
	float	*marr;
	float	*mv;

	oarr = (float *)_mtx_arr(out);
	marr = (float *)_mtx_arr(mtx);
	i = -1;
	while (++i < mtx->shape[0])
	{
		len = 0;
		j = -1;
		while (++j < mtx->shape[1])
			len += powf(*(float *)_mtx_idx(marr, mtx->strides, i, j), 2);
		len = sqrtf(len);
		j = -1;
		while (++j < mtx->shape[1])
		{
			mv = (float *)_mtx_idx(marr, mtx->strides, i, j);
			*(float *)_mtx_idx(oarr, out->strides, i, j) = *mv / len;
		}
	}
}

// Takes an array of n vectors <n x m> and normalizes them rowwise as unit vect.
t_mtx	*mtx_normalize(t_mtx *mtx, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (mtx->dtype != DTYPE_F || out->dtype != DTYPE_F)
		return (MTX_ERROR("only dtype float allowed"));
	if (!ret && !mtx_dup_empty(mtx, &ret, mtx->dtype))
		return (MTX_ERROR("malloc error"));
	_mtx_norm_apply(mtx, out, 0);
	return (ret);
}

// Could be optimized be making its own function and call _mtx_idx only once.
t_mtx	*mtx_inormalize(t_mtx *mtx)
{
	if (mtx->dtype != DTYPE_F)
		return (MTX_ERROR("only dtype float allowed"));
	_mtx_norm_apply(mtx, mtx, 0);
	return (mtx);
}

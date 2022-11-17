/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:31:38 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/17 05:02:28 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// All quaternion translations are done inplace, inside the quaternion 
// rotation matrix. 

t_quat	*_quat_translation_set(t_quat *q, float x, float y, float z)
{
	float	*_tr;

	if (!q)
		return (MTX_ERROR("missing quaternion"));
	_tr = (float *)_mtx_arr(q->translation);
	*(_tr++) = x;
	*(_tr++) = y;
	*(_tr++) = z;
	*(_tr++) = 1;
	return (q);
}

t_quat	*_quat_translation_move(t_quat *q, float dx, float dy, float dz)
{
	float	*_tr;

	if (!q)
		return (MTX_ERROR("missing quaternion"));
	_tr = (float *)_mtx_arr(q->translation);
	*(_tr++) += dx;
	*(_tr++) += dy;
	*(_tr++) += dz;
	*(_tr++) = 1;
	return (q);
}

// pos must indexable as row vector.
t_quat	*quat_translation_set(t_quat *q, t_mtx *pos)
{
	float	*_tr;
	float	*_parr;

	if (!q || !pos || (pos->dtype != DTYPE_F))
		return (MTX_ERROR("missing quaternion or pos, or dtype not float."));
	_tr = (float *)_mtx_arr(q->translation);
	_parr = (float *)_mtx_arr(pos);
//	*(_qarr++) = *(float *)_mtx_idx(_parr, pos->strides, 0, 0);
//	*(_qarr++) = *(float *)_mtx_idx(_parr, pos->strides, 1, 0);
//	*(_qarr++) = *(float *)_mtx_idx(_parr, pos->strides, 2, 0);
	*(_tr++) = *(_parr++);
	*(_tr++) = *(_parr++);
	*(_tr++) = *(_parr++);
	*(_tr++) = 1;
	return (q);
}

// pos must contiguous row vector [dx, dy, dz, 0].
t_quat	*quat_translation_move(t_quat *q, t_mtx *delta)
{
	float	*_tr;
	float	*_parr;

	if (!q || !delta || (delta->dtype != DTYPE_F))
		return (MTX_ERROR("missing quaternion or pos, or dtype not float."));
	_tr = (float *)_mtx_arr(q->translation);
	_parr = (float *)_mtx_arr(delta);
//	*(_qarr++) += *(float *)_mtx_idx(_parr, delta->strides, 0, 0);
//	*(_qarr++) += *(float *)_mtx_idx(_parr, delta->strides, 1, 0);
//	*(_qarr++) += *(float *)_mtx_idx(_parr, delta->strides, 2, 0);
	*(_tr++) += *(_parr++);
	*(_tr++) += *(_parr++);
	*(_tr++) += *(_parr++);
	*(_tr++) = 1;
	return (q);
}

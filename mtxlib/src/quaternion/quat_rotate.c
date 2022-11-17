/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:33:38 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/22 18:43:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// The _quat*() versions do no validations on shape, dtype or swap status.
// They are built for efficiency so check yourself..
t_mtx	*_quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out)
{
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, out->arr);
	return (out);
}

//Assumes mtx is <n x 4> and DTYPE_F and mtx and q exist and mtx is NOT view.
t_mtx	*_quat_irotate(t_mtx *mtx, t_quat *q)
{
	if (!mtx->swap && !mtx_malloc_swap(mtx))
		return (MTX_ERROR("malloc error"));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, mtx->swap);
	_mtx_swap_arrays(mtx);
	return (mtx);
}

t_mtx	*quat_irotate(t_mtx *mtx, t_quat *q)
{
	if (!mtx || !q)
		return (MTX_ERROR("missing params"));
	if (mtx->is_view)
		return (MTX_ERROR("Can't output quaternion rotation to view"));
	else if (!mtx_malloc_swap(mtx))
		return (MTX_ERROR("malloc error"));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, mtx->swap);
	if (!mtx_swap_arrays(mtx))
		return (MTX_ERROR("swap error"));
	return (mtx);
}

// The output array MUST NOT be mtx itself. Use quat_irotate for inplace rotation.
// out CANNOT be a view matrix. Quaternions only opperate on nx4 matrices.
t_mtx	*quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out)
{
	t_mtx	*ret;

	if (!mtx || !q)
		return (MTX_ERROR("missing mtx or quaternion"));
	ret = out;
	if (!ret && !mtx_dup_empty(mtx, &ret, DTYPE_F))
		return (MTX_ERROR("malloc error"));
	if (!mtx_are_same_shape(mtx, ret))
		return (MTX_ERROR("mtx -> out shape mismatch"));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, ret->arr);
	return (ret);
}

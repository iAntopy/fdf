/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 03:33:16 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/22 03:55:17 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Set of functions for rotations using q->rot3_mtx which is a view of the
// 4x4 q->rot_mtx. This is to allow doing the rotation but forgoing the
// translation. (origin: updating a camera transform position in the
// quaternion which requires rotation by the quat's rotation mtx itself without
// applying translation). 

// This set of functions is MUCH LESS EFFICIENT than the quat_rotation.c set
// because of their use of mtx_dot() required to be able to operate on views.

// The _quat*() versions do no validations on shape, dtype or swap status.
// They are built for efficiency so check yourself..
t_mtx	*_quat_rotate3(t_mtx *mtx, t_quat *q, t_mtx *out)
{
//	__mtx_dotf_nx3_3x3(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, out->arr);
	mtx_dot(mtx, q->rot3_mtx, out);
	return (out);
}

//Assumes mtx is <n x 3> and DTYPE_F and mtx and q exist and mtx is NOT view.
t_mtx	*_quat_irotate3(t_mtx *mtx, t_quat *q)
{
	if (!mtx->swap && !mtx_malloc_swap(mtx))
		return (MTX_ERROR("malloc error"));
	mtx_dot(mtx, q->rot3_mtx, mtx);
//	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, mtx->swap);
//	_mtx_swap_arrays(mtx);
	return (mtx);
}

t_mtx	*quat_irotate3(t_mtx *mtx, t_quat *q)
{
	if (!mtx || !q)
		return (MTX_ERROR("missing params"));
//	if (mtx->is_view)
//		return (MTX_ERROR("Cannot output quaternion rotation to view"));
//	else if (!mtx_malloc_swap(mtx))
//		return (MTX_ERROR("malloc error"));
//	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, mtx->swap);
	mtx_dot(mtx, q->rot3_mtx, mtx);
//	if (!mtx_swap_arrays(mtx))
//		return (MTX_ERROR("swap error"));
	return (mtx);
}

// The output array MUST NOT be mtx itself. Use quat_irotate for inplace rotation.
// Quaternions only opperate on nx4 matrices.
t_mtx	*quat_rotate3(t_mtx *mtx, t_quat *q, t_mtx *out)
{
	t_mtx	*ret;

	if (!mtx || !q)
		return (MTX_ERROR("missing mtx or quaternion"));
	ret = out;
	if (!ret && !mtx_dup_empty(mtx, &ret, DTYPE_F))
		return (MTX_ERROR("malloc error"));
	if (!mtx_are_same_shape(mtx, ret))
		return (MTX_ERROR("mtx -> out shape mismatch"));
//	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->__rot_arr, ret->arr);
	mtx_dot(mtx, q->rot3_mtx, ret);
	return (ret);
}

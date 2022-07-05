/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:33:38 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/27 00:44:52 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// The _quat*() versions do no validations on shape, dtype or swap status.
// They are most efficient but check what you are doing.
void	_quat_rotate(t_mtx *mtx, t_quat *q, float *out)
{
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, out);
}

void	_quat_irotate(t_mtx *mtx, t_quat *q)
{
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, mtx->swap);
	_mtx_swap_arrays(mtx);		
}

void	*quat_irotate(t_mtx *mtx, t_quat *q)
{
	if (!mtx || !q)
		return (fperror("%s : missing params", __FUNCTION__));
	else if (!mtx_malloc_swap(mtx))
		return (fperror("%s : malloc error", __FUNCTION__));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, mtx->swap);
	if (!mtx_swap_arrays(mtx))
		return (NULL);
	return ((void *)SIZE_MAX);
}

// The output array MUST NOT be mtx itself. Use quat_irotate for inplace rotation.
// out CANNOT be a view matrix. Quaternions only opperate on nx4 matrices.
void	*quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out)
{
	if (!mtx || !q || !out)
		return (fperror("%s : missing params", __FUNCTION__));
	if (!mtx_are_same_shape(mtx, out))
		return (fperror("%s : mtx and out shape mismatch.", __FUNCTION__));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, out->arr);
	return ((void *)SIZE_MAX);
}

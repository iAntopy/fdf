/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:33:38 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/19 02:19:07 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	*quat_irotate(t_mtx *mtx, t_quat *q)
{
	if (!mtx || !q)
		return (fperror("%s : miisng params", __FUNCTION__));
	else if (!mtx_malloc_swap_array(mtx))
		return (fperror("%s : m", __FUNCTION__));
	_mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, q->rot_mat, mtx->swap);
	if (!mtx_swap_arrays(t_mtx))
		return (NULL);
	return (SIZE_MAX);
}

void	*quat_rotate(t_mtx *mtx, t_quat *q, float *out)
{
	if (!mtx || !q || !out)
		return (fperror("%s : missing params", __FUNCTION__));
	_mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, q->rot_mat, out);
	return (SIZE_MAX);
}

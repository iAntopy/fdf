/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotation_4x4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:02:38 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/12 15:39:55 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	__fill_roll_rotmat_4x4(float sin_ang, float cos_ang, float *arr)
{
	*(arr++) = cos_ang;
	*(arr++) = -sin_ang;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = sin_ang;
	*(arr++) = cos_ang;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 1;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 1;
}

static void	__fill_pitch_rotmat_4x4(float sin_ang, float cos_ang, float *arr)
{
	*(arr++) = cos_ang;
	*(arr++) = 0;
	*(arr++) = sin_ang;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 1;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = -sin_ang;
	*(arr++) = 0;
	*(arr++) = cos_ang;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 1;
}

static void	__fill_yaw_rotmat_4x4(float sin_ang, float cos_ang, float *arr)
{
	*(arr++) = 1;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = cos_ang;
	*(arr++) = -sin_ang;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = sin_ang;
	*(arr++) = cos_ang;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 1;
}

// Assumes that out mtx is 3x3.
void	__mtx_rotation_matrix_4x4(float rll, float pch, float yaw, float *out)
{
	float	arr1[16];
	float	arr2[16];

	__fill_roll_rotmat_4x4(sinf(rll), cos(rll), out);
	__fill_pitch_rotmat_4x4(sinf(pch), cos(pch), arr1);
	__mtx_dotf_nx4_4x4(4, out, arr1, arr2);
	__fill_yaw_rotmat_4x4(sinf(yaw), cos(yaw), arr1);
	__mtx_dotf_nx4_4x4(4, arr2, arr1, out);
}

t_mtx	*mtx_get_rotmat_4x4(float rll, float pch, float yaw, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (out && !(out->shape[0] == 4 && out->shape[1] == 4))
		return (MTX_ERROR("wrong output shape"));
	if (!ret)
	{
		ret = mtx_create_empty(4, 4, DTYPE_F);
		if (!ret)
			return (MTX_ERROR("malloc error"));
	}
	if (!rll && !pch && !yaw)
		__mtx_fill_identity_f(4, ret->arr);
	else
		__mtx_rotation_matrix_4x4(rll, pch, yaw, ret->arr);
	return (ret);	
}

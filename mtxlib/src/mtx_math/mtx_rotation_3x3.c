/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotation_3x3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:48:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:12:37 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	__fill_roll_rotmat_3x3(float sin_ang, float cos_ang, float *arr)
{
	*(arr++) = cos_ang;
	*(arr++) = -sin_ang;
	*(arr++) = 0;
	*(arr++) = sin_ang;
	*(arr++) = cos_ang;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 1;
}

static void	__fill_pitch_rotmat_3x3(float sin_ang, float cos_ang, float *arr)
{
	*(arr++) = cos_ang;
	*(arr++) = 0;
	*(arr++) = sin_ang;
	*(arr++) = 0;
	*(arr++) = 1;
	*(arr++) = 0;
	*(arr++) = -sin_ang;
	*(arr++) = 0;
	*(arr++) = cos_ang;
}

static void	__fill_yaw_rotmat_3x3(float sin_ang, float cos_ang, float *arr)
{
	*(arr++) = 1;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = 0;
	*(arr++) = cos_ang;
	*(arr++) = -sin_ang;
	*(arr++) = 0;
	*(arr++) = sin_ang;
	*(arr++) = cos_ang;
}

// Assumes that out mtx is 3x3.
void	__mtx_rotation_matrix_3x3(float rll, float pch, float yaw, float *out)
{
	float	arr1[9];
	float	arr2[9];

	__fill_roll_rotmat_3x3(sinf(rll), cos(rll), out);
	__fill_pitch_rotmat_3x3(sinf(pch), cos(pch), arr1);
	__mtx_dotf_nx3_3x3(3, out, arr1, arr2);
	__fill_yaw_rotmat_3x3(sinf(yaw), cos(yaw), arr1);
	__mtx_dotf_nx3_3x3(3, arr2, arr1, out);
}

t_mtx	*mtx_get_rotmat_3x3(float rll, float pch, float yaw, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (out && !(out->shape[0] == 3 && out->shape[1] == 3))
		return (MTX_ERROR("wrong output shape"));
	if (!ret)
	{
		ret = mtx_create_empty(3, 3, DTYPE_F);
		if (!ret)
			return (MTX_ERROR("malloc error"));
	}
	__mtx_rotation_matrix_3x3(rll, pch, yaw, ret->arr);
	return (ret);	
}

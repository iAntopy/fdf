/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:55:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/26 19:40:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__quat_init_rot_mtx(float r[4][4], float q[4])//, float scalars[3])
{
	float	w;
	float	x;
	float	y;
	float	z;

	w = q[0];
	x = q[1];
	y = q[2];
	z = q[3];
	r[0][0] = (1 - 2 * y * y - 2 * z * z);// * scalars[0];
	r[0][1] = (2 * x * y - 2 * w * z);// * scalars[1];
	r[0][2] = (2 * x * z + 2 * w * y);// * scalars[2];
	r[0][3] = 0;
	r[1][0] = (2 * x * y + 2 * w * z);// * scalars[0];
	r[1][1] = (1 - 2 * x * x - 2 * z * z);// * scalars[1];
	r[1][2] = (2 * y * z - 2 * w * x);// * scalars[2];
	r[1][3] = 0;
	r[2][0] = (2 * x * z - 2 * w * y);// * scalars[0];
	r[2][1] = (2 * y * z + 2 * w * x);// * scalars[1];
	r[2][2] = (1 - 2 * x * x - 2 * y * y);// * scalars[2];
	r[2][3] = 0;
	r[3][3] = 1;
}

void	_quat_update(t_quat *q, const float vect[3], float ang)
{
	float	x;
	float	y;
	float	z;
	float	mag;
	float	sin_ang;

	q->ang = ang;
	x = vect[0];
	y = vect[1];
	z = vect[2];
	sin_ang = sinf(ang / 2);
	mag = sqrtf(x * x + y * y + z * z);
	q->uv[0] = 0;
	q->uv[1] = (x / mag);
	q->uv[2] = (y / mag);
	q->uv[3] = (z / mag);
	q->q[0] = cosf(ang / 2);
	q->q[1] = q->uv[1] * sin_ang;
	q->q[2] = q->uv[2] * sin_ang;
	q->q[3] = q->uv[3] * sin_ang;
	__quat_init_rot_mtx(q->__rot_arr, q->q);//, q->scalars);
}

static void	__setup_quat(t_quat *q)
{
	static const int	slice_rot3[4] = {0, 0, 3, 3};
	static const int	slice_translation[4] = {3, 0, 4, 3};

	(q->__mtx).arr = (float *)q->__rot_arr;
	q->rot_mtx = &(q->__mtx);
	printf("__setup_quat : quat rot_mtx ptr %p\n", q->rot_mtx);
	mtx_shell(q->rot_mtx, 4, 4, DTYPE_F);
//im 	q->rot_mtx->swap = (float *)q->__rot_arr_swap;
	q->translation = &(q->__tr_view);
	q->rot3_mtx = &(q->__rot3_view);
//	q->scalars[0] = 1;
//	q->scalars[1] = 1;
//	q->scalars[2] = 1;
	mtx_slice_view(q->rot_mtx, (int *)slice_rot3, q->rot3_mtx);
	mtx_slice_view(q->rot_mtx, (int *)slice_translation, q->translation);
//	mtx_select_row(q->rot_mtx, 3, q->translation);
}

t_quat	*quat_create_empty(t_quat *out)
{
	static const float	default_vec[3] = {0, 0, 1};
	t_quat	*ret;

	ret = out;
	if (!ret && !ft_malloc_p(sizeof(t_quat), (void **)&ret))
		return (MTX_ERROR("malloc error"));
	ft_memclear(ret, sizeof(t_quat));
//	__mtx_fill_identity_f(4, (float *)ret->__rot_arr);
	__setup_quat(ret);
	_quat_update(out, default_vec, 0);
	return (ret);
}

t_quat	*quat_create(float ang, float x, float y, float z)
{
	t_quat	*q;

	if (!ft_malloc_p(sizeof(t_quat), (void **)&q))
		return (MTX_ERROR("malloc error"));
	ft_memclear(q, sizeof(t_quat));
	q->uv[1] = x;
	q->uv[2] = y;
	q->uv[3] = z;
	__setup_quat(q);
	_quat_update(q, q->uv + 1, ang);
	return (q);
}

t_quat	*quat_reset(t_quat *q)
{
	static const float	default_vec[3] = {0, 0, 1};
	
	if (!q)
		return (MTX_ERROR("missing input"));
//	__mtx_fill_zeros(q->rot_mtx);
//	__mtx_fill_identity_f(4, (float *)q->__rot_arr);
	_quat_update(q, default_vec, 0);
	return (q);
}

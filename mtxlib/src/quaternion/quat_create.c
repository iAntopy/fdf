/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:55:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/22 18:42:35 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__quat_init_rot_mtx(float r[4][4], float q[4], float s)
{
	float	x;
	float	y;
	float	z;

	x = q[1];
	y = q[2];
	z = q[3];
	r[0][0] = 1 - 2 * y * y - 2 * z * z;
	r[0][1] = 2 * x * y - 2 * s * z;
	r[0][2] = 2 * x * z + 2 * s * y;
	r[0][3] = 0;
	r[1][0] = 2 * x * y + 2 * s * z;
	r[1][1] = 1 - 2 * x * x - 2 * z * z;
	r[1][2] = 2 * y * z - 2 * s * x;
	r[1][3] = 0;
	r[2][0] = 2 * x * z - 2 * s * y;
	r[2][1] = 2 * y * z + 2 * s * x;
	r[2][2] = 1 - 2 * x * x - 2 * y * y;
	r[2][3] = 0;
//	r[3][0] = 0;
//	r[3][1] = 0;
//	r[3][2] = 0;
	r[3][3] = 1;
}

void	_quat_update(t_quat *q, float vect[3], float ang)
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
	__quat_init_rot_mtx(q->__rot_arr, q->q, q->q[0]);
}

static void	__setup_quat(t_quat *q)
{
	(q->__mtx).arr = (float *)q->__rot_arr;
	q->rot_mtx = &(q->__mtx);
	printf("__setup_quat : quat rot_mtx ptr %p\n", q->rot_mtx);
	mtx_shell(q->rot_mtx, 4, 4, DTYPE_F);
//im 	q->rot_mtx->swap = (float *)q->__rot_arr_swap;
	q->translation = &(q->__tr_view);
	mtx_select_row(q->rot_mtx, 3, q->translation);
}

t_quat	*quat_create_empty(t_quat *out)
{
	t_quat	*ret;

	ret = out;
	if (!ret && malloc_free_p(sizeof(t_quat), (void **)&ret))
		return (MTX_ERROR("malloc error"));
	ft_memclear(ret, sizeof(t_quat));
	__mtx_fill_identity_f(4, (float *)ret->__rot_arr);
	__setup_quat(ret);
	return (ret);
}

t_quat	*quat_create(float ang, float x, float y, float z)
{
	t_quat	*q;

	if (!malloc_free_p(sizeof(t_quat), (void **)&q))
		return (MTX_ERROR("malloc error"));
	ft_memclear(q, sizeof(t_quat));
	q->uv[1] = x;
	q->uv[2] = y;
	q->uv[3] = z;
	__setup_quat(q);
	_quat_update(q, q->uv + 1, ang);
	return (q);
}

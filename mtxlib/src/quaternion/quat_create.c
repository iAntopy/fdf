/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_quaternion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:55:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/19 01:27:24 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	__quat_init_rot_mtx(float r[4][4], float q[4], float s)
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
	r[3][0] = 0;
	r[3][1] = 0;
	r[3][2] = 0;
	r[3][3] = 1;
}

void	_quat_update_data(t_quat *q, float vect[3], float ang)
{
	float	s;
	float	mag;
	float	sin_ang;

	s = ang / 2;
	sin_ang = sinf(s);
	mag = sqrtf(x*x + y*y + z*z);
	q->uv[0] = 0;
	q->uv[1] = (vect[0] / mag);
	q->uv[2] = (vect[1] / mag);
	q->uv[3] = (vect[2] / mag);
	q->q[0] = cos(s);
	q->q[1] = q->uv[1] * sin_ang;
	q->q[2] = q->uv[2] * sin_ang;
	q->q[3] = q->uv[3] * sin_ang;
	__quat_init_rot_mtx(q->rot_mtx, q, q->q[0]);
}

t_quat	*quat_create(float ang, float x, float y, foat z)
{
	t_quat	*q;

	if (!malloc_free_p(sizeof(t_quat), (void **)&q)
		return (fperror("%s : malloc error", __FUNCTION__));
	q->uv[1] = x;
	q->uv[2] = y;
	q->uv[3] = z;
	_quat_update_data(q, q->uv + 1, ang);
	return (q);
}

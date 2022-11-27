/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_combine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:28:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/27 02:34:29 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Works inplace. w1 = q2->q[0]
static void	__quat_combine(float *q1, float *q2, t_quat *out)
{
	float	w;
	float	a;
	float	b;
	float	c;
	float	o[4];

	w = q1[0];
	a = q1[1];
	b = q1[2];
	c = q1[3];
	o[0] = w * q2[0] - a * q2[1] - b * q2[2] - c * q2[3];
	o[1] = w * q2[1] + a * q2[0] + b * q2[3] - c * q2[2];
	o[2] = w * q2[2] - a * q2[3] + b * q2[0] + c * q2[1];
	o[3] = w * q2[3] + a * q2[2] - b * q2[1] + c * q2[0];
	out->q[0] = o[0];
	out->q[1] = o[1];
	out->q[2] = o[2];
	out->q[3] = o[3];
	a = sinf(acosf(o[0]));
	out->ang = 2 * a;
	out->uv[1] = o[1] / a;
	out->uv[2] = o[2] / a;
	out->uv[3] = o[3] / a;
//	printf("__quat_combine : combined out->uv : (%f, %f, %f)\n", out->uv[0], out->uv[1], out->uv[2]);
}
/*
// Works inplace. w1 = q2->q[0]
static void	__quat_combine(t_quat *q1, t_quat *q2, t_quat *out, float w1)
{
	float	a;
	float	b;
	float	c;
	float	*q;
	float	o[4];

	q = q1->q;
	a = q2->q[1];
	b = q2->q[2];
	c = q2->q[3];
	o[0] = w1 * q[0] - a * q[1] - b * q[2] - c * q[3];
	o[1] = w1 * q[1] + a * q[0] + b * q[3] - c * q[2];
	o[2] = w1 * q[2] - a * q[3] + b * q[0] + c * q[1];
	o[3] = w1 * q[3] + a * q[2] - b * q[1] + c * q[0];
	out->q[0] = o[0]; //w * q[0] - a * q[1] - b * q[2] - c * q[3];
	out->q[1] = o[1]; //w * q[1] + a * q[0] + b * q[3] - c * q[2];
	out->q[2] = o[2]; //w * q[2] - a * q[3] + b * q[0] + c * q[1];
	out->q[3] = o[3]; //w * q[3] + a * q[2] - b * q[1] + c * q[0];
	w1 = sinf(acosf(o[0]));
	out->ang = 2 * w1;
	out->uv[1] = o[1] / w1;
	out->uv[2] = o[2] / w1;
	out->uv[3] = o[3] / w1;
}
*/

// Works in place. eg.: a = q1, b = q2, a = out.
t_quat	*quat_combine(t_quat *q1, t_quat *q2, t_quat *out)
{
	t_quat	*ret;

//	printf("quat combine : entered\n");
	if (!q1 || !q2)
		return (MTX_ERROR("missing params"));
	ret = out;
	if (!ret)
		ret = quat_create_empty(NULL);
	if (!ret)
		return (MTX_ERROR("malloc error"));
//	ret->scalars[0] = q1->scalars[0] * q2->scalars[0];
//	ret->scalars[1] = q1->scalars[1] * q2->scalars[1];
//	ret->scalars[2] = q1->scalars[2] * q2->scalars[2];
//	printf("quat combine : about to combine\n");
	__quat_combine(q1->q, q2->q, ret);
//	printf("quat combine : combine DONE. initializing rot mtx\n");
//	__quat_init_rot_mtx(ret->__rot_arr, ret->q + 1, ret->q[0]);
//	__quat_init_rot_mtx(ret->__rot_arr, ret->q);//, ret->scalars);
//	printf("quat combine : init rot mtx DONE. Applying dotf 4x4_4x4\n");
	__mtx_dotf_4x4_4x4(q1->rot_mtx->arr, q2->rot_mtx->arr, ret->rot_mtx->arr);
	return (ret);
}

// Adds to the rotation angle
t_quat	*quat_twist(t_quat *q, float delta_ang)
{
	if (!q)
		return (MTX_ERROR("missing params"));
	if (!delta_ang)
		return (q);
	_quat_update(q, q->uv + 1, q->ang + delta_ang);
	return (q);
}

t_quat	*quat_add(t_quat *q, float rll, float ptc, float yaw)
{
	t_quat	q2;
//	int		i;
//	float	*rads;
//	float	sin_ang;

	if (!q)
		return (MTX_ERROR("missing params"));
	if (!(rll || ptc || yaw))
		return (q);
//	quat_create_empty(&q2);
//	i = -1;
//	rads = &rll;
	if (rll)
	{
		q2.q[0] = cosf(rll / 2);
		q2.q[1] = sinf(rll / 2);
		q2.q[2] = 0;
		q2.q[3] = 0;
		__quat_combine(q->q, q2.q, q);
	}
	if (ptc)
	{
		q2.q[0] = cosf(ptc / 2);
		q2.q[1] = 0;
		q2.q[2] = sinf(ptc / 2);//_ang;
		q2.q[3] = 0;
		__quat_combine(q->q, q2.q, q);
	}
	if (yaw)
	{
		q2.q[0] = cosf(yaw / 2);
		q2.q[1] = 0;
		q2.q[2] = 0;
		q2.q[3] = sinf(yaw / 2);
		__quat_combine(q->q, q2.q, q);
	}

	__quat_init_rot_mtx(q->__rot_arr, q->q);//, q->scalars);
	return (q);
}

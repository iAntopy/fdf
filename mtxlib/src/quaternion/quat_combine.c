/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_combine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:28:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/17 05:38:36 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

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

// Works in place. eg.: a = q1, b = q2, a = out.
t_quat	*quat_combine(t_quat *q1, t_quat *q2, t_quat *out)
{
	t_quat	*ret;

	if (!q1 || !q2)
		return (MTX_ERROR("missing params"));
	ret = out;
	if (!ret)
		ret = quat_create_empty(NULL);
	if (!ret)
		return (MTX_ERROR("malloc error"));
	__quat_combine(q1, q2, ret, q2->q[0]);
	__quat_init_rot_mtx(ret->__rot_arr, ret->q + 1, ret->q[0]);
	return (ret);
}


t_quat	*quat_add(t_quat *q, float rll, float ptc, float yaw)
{
	t_quat	q2;
	int		i;
	float	*rads;
	float	sin_ang;

	if (!q)
		return (MTX_ERROR("missing params"));
	if (!(rll || ptc || yaw))
		return (q);
//	quat_create_empty(&q2);
	i = -1;
	rads = &rll;
	while (++i < 3)
	{
		if (rads[i])
		{
			sin_ang = sinf(rads[i] / 2);
			q2.q[0] = cosf(rads[i] / 2);
			q2.q[1] = (i == 0) * sin_ang;
			q2.q[2] = (i == 1) * sin_ang;
			q2.q[3] = (i == 2) * sin_ang;
			__quat_combine(q, &q2, q, q->q[0]);
		}
	}
	__quat_init_rot_mtx(q->__rot_arr, q->q, q->q[0]);
	return (q);
}

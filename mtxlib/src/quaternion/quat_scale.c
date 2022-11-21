/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:37:41 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/21 02:56:56 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"
/*
t_quat	*quat_scale(t_quat *q, float scalar, t_quat *out)
{
	t_quat	*ret;

	if (!q)
		return (MTX_ERROR("missing mtx or quaternion"));
	ret = out;
	if (!ret)
	{
		ret = quat_create_empty(NULL);
		if (!ret)
			return (MTX_ERROR("malloc error"));
	}
	ft_memcpy(ret, q, sizeof(t_quat));
	ret->scalars[0] *= scalar;
	ret->scalars[1] *= scalar;
	ret->scalars[2] *= scalar;
	__quat_init_rot_mtx(ret->__rot_arr, ret->q, ret->scalars);
	return (ret);
}

t_quat	*quat_iscale(t_quat *q, float scalar)
{
	if (!q)
		return (MTX_ERROR("missing mtx or quaternion"));
	q->scalars[0] *= scalar;
	q->scalars[1] *= scalar;
	q->scalars[2] *= scalar;
	__quat_init_rot_mtx(q->__rot_arr, q->q, q->scalars);
	return (q);
}

t_quat	*quat_scale_set(t_quat *q, float scalar, t_quat *out)
{
	t_quat	*ret;

	if (!q)
		return (MTX_ERROR("missing mtx or quaternion"));
	ret = out;
	if (!ret)
	{
		ret = quat_create_empty(NULL);
		if (!ret)
			return (MTX_ERROR("malloc error"));
	}
	ft_memcpy(ret, q, sizeof(t_quat));
	ret->scalars[0] = scalar;
	ret->scalars[1] = scalar;
	ret->scalars[2] = scalar;
	__quat_init_rot_mtx(ret->__rot_arr, ret->q, ret->scalars);
	return (ret);
}

t_quat	*quat_iscale_set(t_quat *q, float scalar)
{
	if (!q)
		return (MTX_ERROR("missing mtx or quaternion"));
	q->scalars[0] = scalar;
	q->scalars[1] = scalar;
	q->scalars[2] = scalar;
	__quat_init_rot_mtx(q->__rot_arr, q->q, q->scalars);
	return (q);
}
*/

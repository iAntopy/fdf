/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:37:41 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/18 01:44:41 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	__quat_apply_scaling(t_quat *q, float s)
{
	float	*arr;

	arr = (float *)_mtx_arr(q->rot_mtx);
	*(arr++) *= s;
	*(arr++) *= s;
	*(arr++) *= s;
	arr++;
	*(arr++) *= s;
	*(arr++) *= s;
	*(arr++) *= s;
	arr++;
	*(arr++) *= s;
	*(arr++) *= s;
	*(arr++) *= s;
}

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
//	((float *)_mtx_arr(ret->rot_mtx))[15] = 1 / scalar;
	ret->scalar *= scalar;
	__quat_apply_scaling(ret, scalar);
	return (ret);
}

t_quat	*quat_iscale(t_quat *q, float scalar)
{
	if (!q)
		return (MTX_ERROR("missing mtx or quaternion"));
//	((float *)_mtx_arr(q->rot_mtx))[15] = 1 / scalar;
	q->scalar *= scalar;
	__quat_apply_scaling(q, scalar);
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
//	((float *)_mtx_arr(ret->rot_mtx))[15] = 1 / scalar;
	ret->scalar = scalar;
	__quat_apply_scaling(ret, scalar);
	return (ret);
}

t_quat	*quat_iscale_set(t_quat *q, float scalar)
{
	if (!q)
		return (MTX_ERROR("missing mtx or quaternion"));
//	((float *)_mtx_arr(q->rot_mtx))[15] = 1 / scalar;
	q->scalar = scalar;
	__quat_apply_scaling(q, scalar);
	return (q);
}

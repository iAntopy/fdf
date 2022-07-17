/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_quaternion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:13:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/16 18:55:40 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MTX_QUATERNION_H
# define MTX_QUATERNION_H

# include "mtx_types.h"

// QUATERNION CREATE

t_quat	*quat_create(float ang, float x, float y, float z);
t_quat	*quat_create_empty(t_quat *q);// if q is NULL, mallocs and inits new quaternion. If declared t_quat on stack is passed as q, acts as mtx_shell().
void	_quat_update(t_quat *q, float vect[3], float ang);// DO NOT declare vect outside. Change q->uv x, y, z values in place and pass q->uv + 1 as vect[3]. q->uv will be normalized.
void	__quat_init_rot_mtx(float rot[4][4], float q[4], float w);

t_quat	*quat_combine(t_quat *q1, t_quat *q2, t_quat *out);

// QUATERNION ROTATION

t_mtx	*quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*quat_irotate(t_mtx *mtx, t_quat *q);
t_mtx	*_quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*_quat_irotate(t_mtx *mtx, t_quat *q);

// QUATERNION TRANSLATION (quaternion can also produce translation if desired. The translation is done post-rotation)
t_quat	*_quat_translation_set(t_quat *q, float x, float y, float z)
t_quat	*_quat_translation_move(t_quat *q, float dx, float dy, float dz)
t_quat	*quat_translation_set(t_quat *q, t_mtx *pos)
t_quat	*quat_translation_set(t_quat *q, t_mtx *delta)

#endif



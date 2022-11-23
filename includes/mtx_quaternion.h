/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_quaternion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:13:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/22 05:02:33 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MTX_QUATERNION_H
# define MTX_QUATERNION_H

# include "mtx_types.h"

// QUATERNION CREATE

t_quat	*quat_create(float ang, float x, float y, float z);
t_quat	*quat_create_empty(t_quat *q);// if q is NULL, mallocs and inits new quaternion. If declared t_quat on stack is passed as q, acts as mtx_shell().
void	_quat_update(t_quat *q, const float vect[3], float ang);// DO NOT declare vect outside. Change q->uv x, y, z values in place and pass q->uv + 1 as vect[3]. q->uv will be normalized
void	quat_clear(t_quat **q);
t_quat	*quat_reset(t_quat *q);
void	quat_display_info(t_quat *q);
void	__quat_init_rot_mtx(float rot[4][4], float q[4]);//, float scalars[3]);

t_quat	*quat_combine(t_quat *q1, t_quat *q2, t_quat *out);
t_quat	*quat_add(t_quat *q, float rll, float ptc, float yaw);
t_quat	*quat_twist(t_quat *q, float delta_ang);	// adds to the angle of rotation

// QUATERNION ROTATION
t_mtx	*quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*quat_irotate(t_mtx *mtx, t_quat *q);
t_mtx	*_quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*_quat_irotate(t_mtx *mtx, t_quat *q);
t_mtx	*quat_rotate3(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*quat_irotate3(t_mtx *mtx, t_quat *q);
t_mtx	*_quat_rotate3(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*_quat_irotate3(t_mtx *mtx, t_quat *q);

// QUATERNION TRANSLATION (quaternion can also produce translation if desired. The translation is done post-rotation)
t_quat	*_quat_translation_set(t_quat *q, float x, float y, float z);
t_quat	*_quat_translation_move(t_quat *q, float dx, float dy, float dz);
t_quat	*quat_translation_set(t_quat *q, t_mtx *pos);
t_quat	*quat_translation_set(t_quat *q, t_mtx *delta);

// QUATERNION ROTATION
t_quat	*quat_scale(t_quat *q, float scalar, t_quat *out);
t_quat	*quat_iscale(t_quat *q, float scalar);
t_quat	*quat_scale_set(t_quat *q, float scalar, t_quat *out);
t_quat	*quat_iscale_set(t_quat *q, float scalar);
t_quat	*quat_iscale_xyz(t_quat *q, float sx, float sy, float sz);
t_quat	*quat_iscale_set_xyz(t_quat *q, float sx, float sy, float sz);

#endif

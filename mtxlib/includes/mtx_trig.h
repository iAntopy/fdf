/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_trig.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:28:50 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/29 03:09:43 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MTX_TRIG_H
# define MTX_TRIG_H

# include "mtx_types.h"

// TRIG OPS
t_mtx	*mtx_sin(t_mtx *a, t_mtx *out);
t_mtx	*mtx_cos(t_mtx *a, t_mtx *out);
t_mtx	*mtx_tan(t_mtx *a, t_mtx *out);
t_mtx	*mtx_asin(t_mtx *a, t_mtx *out);
t_mtx	*mtx_acos(t_mtx *a, t_mtx *out);
t_mtx	*mtx_atan(t_mtx *a, t_mtx *out);
t_mtx	*mtx_sinh(t_mtx *a, t_mtx *out);
t_mtx	*mtx_cosh(t_mtx *a, t_mtx *out);
t_mtx	*mtx_tanh(t_mtx *a, t_mtx *out);
t_mtx	*mtx_asinh(t_mtx *a, t_mtx *out);
t_mtx	*mtx_acosh(t_mtx *a, t_mtx *out);
t_mtx	*mtx_atanh(t_mtx *a, t_mtx *out);


// ROTATION FUNCTIONS
//t_mtx	*mtx_trig(t_mtx *mtx, float (*func)(float));
t_mtx	*mtx_get_rotmat_4x4(float rll, float pch, float yaw, t_mtx *out);
t_mtx	*mtx_get_rotmat_3x3(float rll, float pch, float yaw, t_mtx *out);
t_mtx	*mtx_get_rotmat_2x2(float ang, t_mtx *out);
void	__mtx_rotation_matrix_YXZ(float rll, float pch, float yaw, float *out);
void	__mtx_rotation_matrix_4x4(float rll, float pch, float yaw, float *out);
void	__mtx_rotation_matrix_3x3(float rll, float pch, float yaw, float *out);
void	__mtx_rotation_matrix_2x2(float ang, float *out);

void	__mtx_rotation_matrix_YXZ(float rll, float pch, float yaw, float *out);
#endif

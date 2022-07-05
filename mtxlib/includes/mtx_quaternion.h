/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_quaternion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:13:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/26 23:15:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MTX_QUATERNION_H
# define MTX_QUATERNION_H

# include "mtx_types.h"

// QUATERNION CREATE

t_quat	*quat_create(float ang, float x, float y, float z);
void	_quat_update(t_quat *q, float vect[3], float ang);

// QUATERNION ROTATION

void	*quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out);
void	*quat_irotate(t_mtx *mtx, t_quat *q);
void	_quat_rotate(t_mtx *mtx, t_quat *q, float *out);
void	_quat_irotate(t_mtx *mtx, t_quat *q);

#endif



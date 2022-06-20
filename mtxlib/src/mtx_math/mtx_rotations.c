/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:02:38 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 16:19:14 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_rotation_2x2(float rad, float *out)
{
	*(out++) = cos(rad);
	*(out++) = sin(rad);
	*(out++) = -sin(rad);
	*(out++) = cos(rad);
}

void	__mtx_rotation_3x3(float rll, float pch, float yaw, float *out)
{
	*(out++) = cos(rad);
	*(out++) = sin(rad);
	*(out++) = -sin(rad);
	*(out++) = cos(rad);
}

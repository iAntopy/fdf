/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_dot_nx3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:49:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 01:21:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Not usable with view output
void	__mtx_dotf_3x3_3x3(float *a, float *b, float *out)
{
	*(out++) = a[0] * b[0] + a[1] * b[3] + a[2] * b[6];
	*(out++) = a[0] * b[1] + a[1] * b[4] + a[2] * b[7];
	*(out++) = a[0] * b[2] + a[1] * b[5] + a[2] * b[8];
 	*(out++) = a[3] * b[0] + a[4] * b[3] + a[5] * b[6];
	*(out++) = a[3] * b[1] + a[4] * b[4] + a[5] * b[7];
	*(out++) = a[3] * b[2] + a[4] * b[5] + a[5] * b[8];
	*(out++) = a[6] * b[0] + a[7] * b[3] + a[8] * b[6];
	*(out++) = a[6] * b[1] + a[7] * b[4] + a[8] * b[7];
	*(out++) = a[6] * b[2] + a[7] * b[5] + a[8] * b[8];
}

// Not usable with view output
void	__mtx_dotf_nx3_3x3(int n, float *a, float *b, float *out)
{
	float	a0;
	float	a1;
	float	a2;

	while (n--)
	{
		a0 = *(a++);
		a1 = *(a++);
		a2 = *(a++);
		*(out++) = a0 * b[0] + a1 * b[3] + a2 * b[6];
		*(out++) = a0 * b[1] + a1 * b[4] + a2 * b[7];
		*(out++) = a0 * b[2] + a1 * b[5] + a2 * b[8];
	}
}

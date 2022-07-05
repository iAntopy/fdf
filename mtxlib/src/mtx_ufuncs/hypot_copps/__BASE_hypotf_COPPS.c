/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_hypotf_COPPS.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:33:43 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 21:10:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_hypotf_init(float *a, float *out)
{
	UNUSED(a);
	*out = 0;
}

void	__mtx_hypotf_cumul(float *a, float *out)
{
	*out += powf(*a, 2);
}

void	__mtx_hypotf_post(float *out, int n)
{
	UNUSED(n);
	*out = sqrtf(*out);
}

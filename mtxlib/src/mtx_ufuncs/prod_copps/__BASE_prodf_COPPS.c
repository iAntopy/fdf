/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_prodf_COPPS.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:55:24 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_prodf_init(float *a, float *out)
{
	UNUSED(a);
	*out = 1;
}

void	__mtx_prodf_cumul(float *a, float *out)
{
	*out *= *a;
}

void	__mtx_prodf_post(float *out, int n)
{
	UNUSED(out);
	UNUSED(n);
	return ;
}

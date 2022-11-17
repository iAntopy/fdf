/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_pow_OPPS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:05:11 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/25 21:46:29 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_powi(int *v1, int *v2, int *out)
{
	*out = pow(*v1, *v2);
}

void	__mtx_std_powf(float *v1, float *v2, float *out)
{
	*out = pow(*v1, *v2);
}

void	__mtx_std_rpowf(float *v1, float *v2, float *out)
{
	*out = pow(*v2, *v1);
}

void	__mtx_std_rpowi(int *v1, int *v2, int *out)
{
	*out = pow(*v2, *v1);
}

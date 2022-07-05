/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_div_OPPS.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:41:12 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/23 23:00:21 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_divi(int *v1, int *v2, int *out)
{
	*out = *v1 / *v2;
}

void	__mtx_std_divf(float *v1, float *v2, float *out)
{
	*out = *v1 / *v2;
}

void	__mtx_std_rdivf(float *v1, float *v2, float *out)
{
	*out = *v2 / *v1;
}

void	__mtx_std_rdivi(int *v1, int *v2, int *out)
{
	*out = *v2 / *v1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_sub_OPPS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:35:25 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/23 22:59:29 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_subi(int *v1, int *v2, int *out)
{
	*out = *v1 - *v2;
}

void	__mtx_std_subf(float *v1, float *v2, float *out)
{
	*out = *v1 - *v2;
}

void	__mtx_std_rsubf(float *v1, float *v2, float *out)
{
	*out = *v2 - *v1;
}

void	__mtx_std_rsubi(int *v1, int *v2, int *out)
{
	*out = *v2 - *v1;
}

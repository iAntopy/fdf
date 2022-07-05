/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_mul_OPPS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:37:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/23 22:59:13 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_muli(int *v1, int *v2, int *out)
{
	*out = *v1 * (*v2);
}

void	__mtx_std_mulf(float *v1, float *v2, float *out)
{
	*out = *v1 * (*v2);
}

void	__mtx_std_rmulf(float *v1, float *v2, float *out)
{
	*out = *v2 * (*v1);
}

void	__mtx_std_rmuli(int *v1, int *v2, int *out)
{
	*out = *v2 * (*v1);
}

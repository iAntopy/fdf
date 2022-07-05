/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_add_OPPS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:05:11 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/23 22:50:07 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_addi(int *v1, int *v2, int *out)
{
	*out = *v1 + *v2;
}

void	__mtx_std_addf(float *v1, float *v2, float *out)
{
	*out = *v1 + *v2;
}

void	__mtx_std_raddf(float *v1, float *v2, float *out)
{
	*out = *v2 + *v1;
}

void	__mtx_std_raddi(int *v1, int *v2, int *out)
{
	*out = *v2 + *v1;
}

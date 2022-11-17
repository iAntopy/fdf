/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_sumf_COPPS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:50:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_sumf_init(float *a, float *out)
{
	UNUSED(a);
	*out = 0;
}

void	__mtx_sumf_cumul(float *a, float *out)
{
	*out += *a;
}

void	__mtx_sumf_post(float *out, int n)
{
	UNUSED(out);
	UNUSED(n);
	return ;
}

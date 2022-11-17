/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_maxi_COPPS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:58:17 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_maxi_init(int *a, int *out)
{
	UNUSED(a);
	*out = INT_MIN;
}

void	__mtx_maxi_cumul(int *a, int *out)
{
	if (*a > *out)
		*out = *a;
}

void	__mtx_maxi_post(int *out, int n)
{
	UNUSED(n);
	UNUSED(out);
	return ;
}

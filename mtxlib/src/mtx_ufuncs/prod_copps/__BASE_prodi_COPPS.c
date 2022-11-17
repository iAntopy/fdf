/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_prodi_COPPS.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:51:44 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_prodi_init(int *a, int *out)
{
	UNUSED(a);
	*out = 1;
}

void	__mtx_prodi_cumul(int *a, int *out)
{
	*out *= *a;
}

void	__mtx_prodi_post(int *out, int n)
{
	UNUSED(out);
	UNUSED(n);
	return ;
}

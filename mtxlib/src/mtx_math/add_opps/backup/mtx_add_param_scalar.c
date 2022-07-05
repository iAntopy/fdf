/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_add_param_scalar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 21:17:36 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_iaddf_pscalar(t_mtx *a, float b)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(float);
	mb.arr = &b;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(a, &mb, a, __mtx_std_addf);
}

void	_mtx_addf_pscalar(t_mtx *a, float b, t_mtx *out)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(float);
	mb.arr = &b;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(a, &mb, out, __mtx_std_addf);
}

void	_mtx_iaddi_pscalar(t_mtx *a, int b)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(int);
	mb.arr = &b;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(a, &mb, a, __mtx_std_addi);
}

void	_mtx_addi_pscalar(t_mtx *a, int b, t_mtx *out)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(int);
	mb.arr = &b;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(a, &mb, out, __mtx_std_addi);
}

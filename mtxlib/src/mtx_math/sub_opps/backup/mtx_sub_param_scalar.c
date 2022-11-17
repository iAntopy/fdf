/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sub_param_scalar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 21:16:24 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_isubf_pscalar(t_mtx *a, float b)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(float);
	mb.arr = &b;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(a, &mb, a, __mtx_std_subf);
}

void	_mtx_subf_pscalar(t_mtx *a, float b, t_mtx *out)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(float);
	mb.arr = &b;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(a, &mb, out, __mtx_std_subf);
}

void	_mtx_isubi_pscalar(t_mtx *a, int b)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(int);
	mb.arr = &b;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(a, &mb, a, __mtx_std_subi);
}

void	_mtx_subi_pscalar(t_mtx *a, int b, t_mtx *out)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(int);
	mb.arr = &b;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(a, &mb, out, __mtx_std_subi);
}

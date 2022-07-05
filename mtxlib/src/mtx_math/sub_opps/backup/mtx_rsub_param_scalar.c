/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rsub_param_scalar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 21:16:52 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_risubf_pscalar(float a, t_mtx *b)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(float);
	mb.arr = &a;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(b, &ma, b, __mtx_std_rsubf);
}

void	_mtx_rsubf_pscalar(float a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(float);
	mb.arr = &a;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(b, &ma, out, __mtx_std_rsubf);
}

void	_mtx_risubi_pscalar(int a, t_mtx *b)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(int);
	mb.arr = &a;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(b, &ma, a, __mtx_std_rsubi);
}

void	_mtx_rsubi_pscalar(int a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(int);
	mb.arr = &a;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(b, &ma, out, __mtx_std_rsubi);
}

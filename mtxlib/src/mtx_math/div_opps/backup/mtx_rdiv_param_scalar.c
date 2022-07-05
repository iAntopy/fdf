/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rdiv_param_scalar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 21:19:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_ridivf_pscalar(float a, t_mtx *b)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(float);
	mb.arr = &a;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(b, &ma, b, __mtx_std_rdivf);
}

void	_mtx_rdivf_pscalar(float a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(float);
	mb.arr = &a;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(b, &ma, out, __mtx_std_rdivf);
}

void	_mtx_ridivi_pscalar(int a, t_mtx *b)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(int);
	mb.arr = &a;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(b, &ma, a, __mtx_std_rdivi);
}

void	_mtx_rdivi_pscalar(int a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	__mtx_setup_1d(&ma, 1, 1, sizeof(int);
	mb.arr = &a;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(b, &ma, out, __mtx_std_rdivi);
}

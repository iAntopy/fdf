/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_mul_param_scalar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 21:18:07 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_imulf_pscalar(t_mtx *a, float b)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(float);
	mb.arr = &b;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(a, &mb, a, __mtx_std_mulf);
}

void	_mtx_mulf_pscalar(t_mtx *a, float b, t_mtx *out)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(float);
	mb.arr = &b;
	mb.dtype = DTYPE_F;
	__mtx_opp_scalar(a, &mb, out, __mtx_std_mulf);
}

void	_mtx_imuli_pscalar(t_mtx *a, int b)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(int);
	mb.arr = &b;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(a, &mb, a, __mtx_std_muli);
}

void	_mtx_muli_pscalar(t_mtx *a, int b, t_mtx *out)
{
	t_mtx	mb;

	__mtx_setup_1d(&mb, 1, 1, sizeof(int);
	mb.arr = &b;
	mb.dtype = DTYPE_I;
	__mtx_opp_scalar(a, &mb, out, __mtx_std_muli);
}

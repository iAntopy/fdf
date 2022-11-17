/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_add_param_scalar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/29 20:10:58 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_iaddf_pscalar(t_mtx *a, float b)
{
	t_mtx	mb;

	mb.arr = &b;
	mtx_shell(&mb, 1, 1, DTYPE_F);
	_mtx_opp_scalar(a, &mb, a, __mtx_std_addf);
}

void	_mtx_addf_pscalar(t_mtx *a, float b, t_mtx *out)
{
	t_mtx	mb;

	mb.arr = &b;
	mtx_shell(&mb, 1, 1, DTYPE_F);
	_mtx_opp_scalar(a, &mb, out, __mtx_std_addf);
}

void	_mtx_iaddi_pscalar(t_mtx *a, int b)
{
	t_mtx	mb;

	mb.arr = &b;
	mtx_shell(&mb, 1, 1, DTYPE_I);
	_mtx_opp_scalar(a, &mb, a, __mtx_std_addi);
}

void	_mtx_addi_pscalar(t_mtx *a, int b, t_mtx *out)
{
	t_mtx	mb;

	mb.arr = &b;
	mtx_shell(&mb, 1, 1, DTYPE_I);
	_mtx_opp_scalar(a, &mb, out, __mtx_std_addi);
}

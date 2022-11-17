/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ratan2_param_scalar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/29 20:14:37 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_riatan2f_pscalar(float a, t_mtx *b)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_F);
	_mtx_opp_scalar(b, &ma, b, __mtx_std_ratan2f);
}

void	_mtx_ratan2f_pscalar(float a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_F);
	_mtx_opp_scalar(b, &ma, out, __mtx_std_ratan2f);
}

void	_mtx_riatan2i_pscalar(int a, t_mtx *b)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_I);
	_mtx_opp_scalar(b, &ma, b, __mtx_std_ratan2i);
}

void	_mtx_ratan2i_pscalar(int a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_I);
	_mtx_opp_scalar(b, &ma, out, __mtx_std_ratan2i);
}

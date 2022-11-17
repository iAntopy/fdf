/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rmul_param_scalar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:38:08 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/29 20:14:37 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_rimulf_pscalar(float a, t_mtx *b)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_F);
	_mtx_opp_scalar(b, &ma, b, __mtx_std_rmulf);
}

void	_mtx_rmulf_pscalar(float a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_F);
	_mtx_opp_scalar(b, &ma, out, __mtx_std_rmulf);
}

void	_mtx_rimuli_pscalar(int a, t_mtx *b)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_I);
	_mtx_opp_scalar(b, &ma, b, __mtx_std_rmuli);
}

void	_mtx_rmuli_pscalar(int a, t_mtx *b, t_mtx *out)
{
	t_mtx	ma;

	ma.arr = &a;
	mtx_shell(&ma, 1, 1, DTYPE_I);
	_mtx_opp_scalar(b, &ma, out, __mtx_std_rmuli);
}

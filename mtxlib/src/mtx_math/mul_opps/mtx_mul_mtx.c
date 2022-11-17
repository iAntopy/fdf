/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_mul_mtx.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:45:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 22:59:51 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_muli_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_muli);
}

void	_mtx_imuli_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_muli);
}

void	_mtx_mulf_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_mulf);
}

void	_mtx_imulf_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_mulf);
}

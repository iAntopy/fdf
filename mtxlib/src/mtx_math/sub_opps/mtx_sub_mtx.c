/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sub_mtx.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:45:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 22:59:51 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_subi_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_subi);
}

void	_mtx_isubi_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_subi);
}

void	_mtx_subf_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_subf);
}

void	_mtx_isubf_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_subf);
}

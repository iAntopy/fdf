/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rsub_scalar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:13:46 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 20:28:42 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_ridivf_scalar(t_mtx *a, t_mtx *b)
{
	__mtx_opp_scalar(a, b, a, __mtx_rstd_divf);
}

void	_mtx_rdivf_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	__mtx_opp_scalar(a, b, out, __mtx_rstd_divf);
}

void	_mtx_ridivi_scalar(t_mtx *a, t_mtx *b)
{
	__mtx_opp_scalar(a, b, a, __mtx_rstd_divi);
}

void	_mtx_rdivi_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	__mtx_opp_scalar(a, b, out, __mtx_rstd_divi);
}

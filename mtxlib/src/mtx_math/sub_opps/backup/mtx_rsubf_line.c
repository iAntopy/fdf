/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rsubf_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:25:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 19:26:04 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_rsubf_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_row(a, b, out, __mtx_std_rsubf);
}

void	_mtx_risubf_line_rowwise(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_row(a, b, a, __mtx_std_rsubf);
}

void	_mtx_rsubf_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_col(a, b, out, __mtx_std_rsubf);
}

void	_mtx_risubf_line_colwise(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_col(a, b, a, __mtx_std_rsubf);
}

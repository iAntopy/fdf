/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_raddf_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:25:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 23:52:48 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_raddf_line_r(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_row(a, b, out, __mtx_std_raddf);
}

void	_mtx_riaddf_line_r(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_row(a, b, a, __mtx_std_raddf);
}

void	_mtx_raddf_line_c(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_col(a, b, out, __mtx_std_raddf);
}

void	_mtx_riaddf_line_c(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_col(a, b, a, __mtx_std_raddf);
}

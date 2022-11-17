/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_divi_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:31:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 23:05:21 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_divi_line_r(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_row(a, b, out, __mtx_std_divi);
}

void	_mtx_idivi_line_r(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_row(a, b, a, __mtx_std_divi);
}

void	_mtx_divi_line_c(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_col(a, b, out, __mtx_std_divi);
}

void	_mtx_idivi_line_c(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_col(a, b, a, __mtx_std_divi);
}

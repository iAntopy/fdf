/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rsubi_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:28:19 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 20:27:38 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_rdivi_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_row(a, b, out, __mtx_std_rdivi);
}

void	_mtx_ridivi_line_rowwise(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_row(a, b, a, __mtx_std_rdivi);
}

void	_mtx_rdivi_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_col(a, b, out, __mtx_std_rdivi);
}

void	_mtx_ridivi_line_colwise(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_col(a, b, a, __mtx_std_rdivi);
}

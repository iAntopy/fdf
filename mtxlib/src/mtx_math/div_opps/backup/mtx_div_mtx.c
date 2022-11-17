/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_div_mtx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:45:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 02:00:17 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_divi_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_divi);
}

void	_mtx_idivi_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_divi);
}

void	_mtx_divf_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_divf);
}

void	_mtx_idivf_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_divf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_std_mopps_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:32:42 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 00:33:39 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_opp_scalar(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)())
{
	t_mopp	mo;
	
	__mtx_init_math_opp(&mo, a, b, out);
	mo.opp = opp;
	__mtx_std_scalar(&mo);
}

void	_mtx_opp_line_row(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)())
{
	t_mopp	mo;
	
	__mtx_init_math_opp(&mo, a, b, out);
	mo.opp = opp;
	__mtx_std_line_row(&mo);
}

void	_mtx_opp_line_col(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)())
{
	t_mopp	mo;
	
	__mtx_init_math_opp(&mo, a, b, out);
	mo.opp = opp;
	__mtx_std_line_col(&mo);
}

void	_mtx_opp_mtx(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)())
{
	t_mopp	mo;
	
	__mtx_init_math_opp(&mo, a, b, out);
	mo.opp = opp;
	__mtx_std_mtx(&mo);
}

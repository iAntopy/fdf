/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_min_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:32:03 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:32:57 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_minf_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_minf_init;
	co.cumul_opp = __mtx_minf_cumul;
	co.post_opp = __mtx_minf_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_minf_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_minf_init;
	co.cumul_opp = __mtx_minf_cumul;
	co.post_opp = __mtx_minf_post;
	_mtx_copp_by_row(&co);
}

void	_mtx_mini_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_mini_init;
	co.cumul_opp = __mtx_mini_cumul;
	co.post_opp = __mtx_mini_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_mini_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_mini_init;
	co.cumul_opp = __mtx_mini_cumul;
	co.post_opp = __mtx_mini_post;
	_mtx_copp_by_row(&co);
}

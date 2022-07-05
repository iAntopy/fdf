/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_mean_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:32:03 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:32:57 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_meanf_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_meanf_init;
	co.cumul_opp = __mtx_meanf_cumul;
	co.post_opp = __mtx_meanf_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_meanf_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_meanf_init;
	co.cumul_opp = __mtx_meanf_cumul;
	co.post_opp = __mtx_meanf_post;
	_mtx_copp_by_row(&co);
}

void	_mtx_meani_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_meani_init;
	co.cumul_opp = __mtx_meani_cumul;
	co.post_opp = __mtx_meani_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_meani_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_meani_init;
	co.cumul_opp = __mtx_meani_cumul;
	co.post_opp = __mtx_meani_post;
	_mtx_copp_by_row(&co);
}

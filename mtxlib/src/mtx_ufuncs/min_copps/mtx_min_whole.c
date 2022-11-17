/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_min_whole.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:22:55 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:33:04 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_minf_whole(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_minf_init;
	co.cumul_opp = __mtx_minf_cumul;
	co.post_opp = __mtx_minf_post;
	_mtx_copp_whole(&co);
}

void	_mtx_mini_whole(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_mini_init;
	co.cumul_opp = __mtx_mini_cumul;
	co.post_opp = __mtx_mini_post;
	_mtx_copp_whole(&co);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_copp_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:47:17 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/04 02:07:09 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_copp_whole(t_copp *co)
{
	int	i;
	int	j;

	co->ov = _mtx_idx(co->o, co->os, 0, 0);
	co->init_opp(co->av, co->ov);
	i = -1;
	while (++i < co->r)
	{
		j = -1;
		while (++j < co->c)
		{
			co->av = _mtx_idx(co->a, co->as, i, j);
			co->cumul_opp(co->av, co->ov);
		}
	}
	co->post_opp(co->ov, co->r * co->c);
}

void	_mtx_copp_by_row(t_copp *co)
{
	int	i;
	int	j;

	i = -1;
	while (++i < co->r)
	{
		j = -1;
		co->ov = _mtx_idx(co->o, co->os, i, 0);
		co->init_opp(co->av, co->ov);
		while (++j < co->c)
		{
			co->av = _mtx_idx(co->a, co->as, i, j);
			co->cumul_opp(co->av, co->ov);
		}
		co->post_opp(co->ov, co->c);
	}
}

void	_mtx_copp_by_col(t_copp *co)
{
	int	i;
	int	j;

	j = -1;
	while (++j < co->c)
	{
		i = -1;
		co->ov = _mtx_idx(co->o, co->os, j, 0);
		co->init_opp(co->av, co->ov);
		while (++i < co->r)
		{
			co->av = _mtx_idx(co->a, co->as, i, j);
			co->cumul_opp(co->av, co->ov);
		}
		co->post_opp(co->ov, co->r);
	}
}

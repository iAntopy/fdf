/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init_opp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:49:37 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 00:33:10 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_init_math_opp(t_mopp *mo, t_mtx *a, t_mtx *b, t_mtx *out)
{
//	printf("a->arr ptr %p vs _mtx_idx(_mtx_arr(a), strides, 0, 0) ptr %p\n", a->arr, _mtx_idx(_mtx_arr(a), a->strides, 0, 0));
//	printf("mopp init : a->arr == out->arr ? %d\n", a->arr == out->arr);
	mo->a = _mtx_arr(a);
	mo->b = _mtx_arr(b);
	mo->o = _mtx_arr(out);
//	printf("mopp init : mo->a == mo->o ? %d\n", mo->a == mo->o);

	mo->as = a->strides;
	mo->bs = b->strides;
	mo->os = out->strides;
	mo->r = a->shape[0];
	mo->c = a->shape[1];
	mo->av = NULL;//_mtx_idx(mo->a, mo->as, 0, 0);
	mo->bv = NULL;//_mtx_idx(mo->b, mo->bs, 0, 0);
	mo->ov = NULL;//_mtx_idx(mo->o, mo->os, 0, 0);
}

void	__mtx_execute_mopp(t_mopp *mo)
{
	mo->opp(mo->av, mo->bv, mo->ov);
}

void	__mtx_execute_unary_moppf(t_mopp *mo)
{
	*(float *)mo->ov = mo->oppf(*(float *)mo->av);
}

void	__mtx_execute_unary_moppi(t_mopp *mo)
{
	*(int *)mo->ov = mo->oppi(*(int *)mo->av);
}

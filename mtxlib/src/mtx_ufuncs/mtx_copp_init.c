/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init_copp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:10:29 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 17:11:07 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_init_cumul_opp(t_copp *co, t_mtx *a, t_mtx *out)
{
//	printf("a->arr ptr %p vs _mtx_idx(_mtx_arr(a), strides, 0, 0) ptr %p\n", a->arr, _mtx_idx(_mtx_arr(a), a->strides, 0, 0));
//	printf("copp init : a->arr == out->arr ? %d\n", a->arr == out->arr);
	co->a = _mtx_arr(a);
	co->o = _mtx_arr(out);
//	printf("copp init : mo->a == mo->o ? %d\n", mo->a == mo->o);

	co->as = a->strides;
	co->os = out->strides;
	co->r = a->shape[0];
	co->c = a->shape[1];
	co->av = NULL;//_mtx_idx(mo->a, mo->as, 0, 0);
	co->ov = NULL;//_mtx_idx(mo->o, mo->os, 0, 0);
}
/*
void	__mtx_execute_copp(t_mopp *mo)
{
	co->opp(co->av, co->ov);
}

void	__mtx_execute_unary_moppf(t_mopp *mo)
{
	*(float *)mo->ov = mo->oppf(*(float *)mo->av);
}

void	__mtx_execute_unary_moppi(t_mopp *mo)
{
	*(int *)mo->ov = mo->oppi(*(int *)mo->av);
}
*/

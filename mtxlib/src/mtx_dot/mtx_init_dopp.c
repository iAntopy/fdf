/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init_dopp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:05:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/12 20:05:35 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	mtx_print_dopp(t_dopp *dop)
{
	printf("@@~~~~~~~~~ DOT OPP STRUCT ~~~~~~~~~~@@\n");
	printf("@	a : %p,	b : %p,	o : %p\n", dop->a, dop->b, dop->o);
	printf("@	as : %d,	bs : %d,	os : %d\n", dop->as[0], dop->bs[0], dop->os[0]);
	printf("@	n : %d,	m : %d,	l : %d\n", dop->n, dop->m, dop->l);
	printf("@	pure ? %s,	inplc ? %s\n", (dop->is_pure)?"TRUE":"FALSE", (!!dop->inplace_mtx)?"TRUE":"FALSE");
	printf("@@~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~@@\n");
}

t_dopp	*__mtx_init_dopp(t_dopp *dop, t_mtx *a, t_mtx *b, t_mtx *out)
{
	dop->inplace_mtx = NULL;
	printf("init dopp : a->arr ptr : %p\n", *(a->view_ptr));
	printf("init dopp : b->arr ptr : %p\n", *(b->view_ptr));
	printf("init dopp : out->arr ptr : %p\n", *(out->view_ptr));
	if (*(a->view_ptr) == *(out->view_ptr))
		dop->inplace_mtx = a;
	else if (*(b->view_ptr) == *(out->view_ptr))
		dop->inplace_mtx = b;
	dop->is_pure = !(a->is_view || b->is_view
		|| mtx_istransposed(a) || mtx_istransposed(b));
	dop->a = _mtx_arr(a);
	dop->b = _mtx_arr(b);
	if (dop->inplace_mtx || out->is_view)
	{
		if (!mtx_malloc_swap(out))
			return (MTX_ERROR("malloc error"));
		dop->o = out->swap;
	}
	else
		dop->o = _mtx_arr(out);
	dop->as = a->strides;
	dop->bs = b->strides;
	dop->os = out->strides;
	dop->n = a->shape[0];
	dop->m = a->shape[1];
	dop->l = b->shape[1];
	return (dop);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_print_mopp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/29 18:55:13 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	mtx_print_mopp_f(t_mopp *mo)
{
	printf("@@~~~~~~ MATH OPP STRUCT FLOAT ~~~~~~~@@\n");
	printf("@	a : %p,	b : %p,	o : %p\n", mo->a, mo->b, mo->o);
	printf("@	as : %d,	bs : %d,	os : %d\n", mo->as[0], mo->bs[0], mo->os[0]);
	printf("@	r : %d,	c : %d\n", mo->r, mo->c);
	if (mo->av && mo->bv && mo->ov)
		printf("@	av : %f,	bv : %f,	ov : %f\n",
			*(float *)mo->av, *(float *)mo->bv, *(float *)mo->ov);
	printf("@@~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~@@\n");
}

void	mtx_print_mopp_i(t_mopp *mo)
{
	printf("@@~~~~~~ MATH OPP STRUCT INT ~~~~~~~@@\n");
	printf("@	a : %p,	b : %p,	o : %p\n", mo->a, mo->b, mo->o);
	printf("@	as : %d,	bs : %d,	os : %d\n", mo->as[0], mo->bs[0], mo->os[0]);
	printf("@	r : %d,	c : %d\n", mo->r, mo->c);
	if (mo->av && mo->bv && mo->ov)
		printf("@	av : %d,	bv : %d,	cv : %d\n",
			*(int *)mo->av, *(int *)mo->bv, *(int *)mo->ov);
	printf("@@~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~@@\n");
}
/*
void	mtx_print_mopp(t_mopp *mo)
{
	if (mo && mo->a && (mo->a->dtype == DTYPE_I))
		mtx_print_mopp_i(mo);
	else if (mo && mo->a && (mo->a->dtype == DTYPE_F))
		mtx_print_mopp_f(mo);
}
*/

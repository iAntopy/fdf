/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_unary_opps_apply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:12:37 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:15:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_apply_f(t_mopp *mo)
{
	int	i;
	int	j;

	printf("UNANIMITY !\n");
	i = -1;
	while (++i < mo->r)
	{
		j = -1;
		while (++j < mo->c)
		{
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
			__mtx_execute_unary_moppf(mo);
		}
	}
}

void	_mtx_apply_i(t_mopp *mo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mo->r)
	{
		j = -1;
		while (++j < mo->c)
		{
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
			__mtx_execute_unary_moppi(mo);
		}
	}
}

t_mtx	*mtx_apply_f(t_mtx *a, float (*func)(float), t_mtx *out)
{
	t_mopp	mo;
	t_mtx	*ret;

	printf("mtx_apply_f : STARTING APPLY\n");
	if (!a && a->dtype == DTYPE_F)
		return (MTX_ERROR("no input mtx or has wrong dtype"));
	ret = out;
	if (!ret && !mtx_dup_empty(a, &ret, DTYPE_F))
		return (MTX_ERROR("malloc error"));
	if (!mtx_are_same_type(a, ret, NULL) || !mtx_are_same_shape(a, ret))
		return (MTX_ERROR("a -> out shape or dtype mismatch"));

	printf("mtx_apply_f : INIT math opp\n");
	__mtx_init_math_opp(&mo, a, a, ret);
	printf("mtx_apply_f : INIT DONE\n"); 
	mo.oppf = func;
	printf("mtx_apply_f : starting apply_f\n"); 

	_mtx_apply_f(&mo);
	return (ret);
}

t_mtx	*mtx_apply_i(t_mtx *a, int (*func)(int), t_mtx *out)
{
	t_mopp	mo;
	t_mtx	*ret;

	if (!a && a->dtype == DTYPE_I)
		return (MTX_ERROR("no input mtx or has wrong dtype"));
	ret = out;
	if (!ret && !mtx_dup_empty(a, &ret, DTYPE_I))
		return (MTX_ERROR("malloc error"));
	else if (!mtx_are_same_type(a, out, NULL) || !mtx_are_same_shape(a, ret))
		return (MTX_ERROR("a -> out shape or dtype mismatch"));
	__mtx_init_math_opp(&mo, a, a, out);
	mo.oppi = func;
	_mtx_apply_i(&mo);
	return (ret);
}

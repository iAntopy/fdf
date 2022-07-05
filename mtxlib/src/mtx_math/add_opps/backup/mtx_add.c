/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:33:18 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 19:07:56 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	put_biggest_first(t_mtx **a, t_mtx **b)
{
	t_mtx	*temp;

	if (((*a)->ndims == 1 && (*b)->ndims == 2) || (*a)->shape[0] == 1)
	{	
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

static int	mtx_are_same_shape(t_mtx *a, t_mtx* b)
{
	return (a->shape[0] == b->shape[0] && a->ashpes[1] == b->shape[1]);
}

t_mtx	*mtx_add(t_mtx *a, t_mtx *b, t_mtx *out)
{
	static MOPP_FUNC	opps[4][2] = {
		{_mtx_addi_scalar, _mtx_addf_scalar},
		{_mtx_addi_line_row, _mtx_addf_line_row},
		{_mtx_addi_line_col, _mtx_addf_line_col},
		{_mtx_addi_mtx, _mtx_addf_mtx}}

	put_biggest_first(&a, &b);
	if (!out && !mtx_dup_empty(a, &out, dtype))
		return (fperror("%s: malloc error", __FUNCTION__));
	if (mtx_are_same_shape(a, b))
		opps[6][dtype](a, b, out);
	else if (b->ndims == 1)
	{
		if (b->shape[0] == 1)
			opps[0][mtx_dtype_out(a, b)](a, b, out);
		else if (b->shape[0] == a->shape[1])
			opps[2][mtx_dtype_out(a, b)](a, b, out);
		else if (b->shape[0] == a->shape[0])
			opps[4][mtxdtype_out(a, b)](a, b, out);
		else
			return (fperror("%s: mismatch shapes ", __FUNCTION__));
	}
	else
		return (fperror("%s: mismatch shapes ", __FUNCTION__));
	return (out);
}
/*
	if (b->shape[0] == 1)
		

	if (a->shape[0] == 1 || b->shape[0] == 1);// IS SCALAR OPP


	func_idx |= (a->shape[0] == 1 && b->shape[0] == 1) << 0;

	if ()
	if (!a || !b)
		return (fperror("%s: missing operand", __FUNCTION__));
	
	
}*/

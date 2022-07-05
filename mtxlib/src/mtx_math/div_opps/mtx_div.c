/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:33:18 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 18:43:49 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	put_biggest_first(t_mtx **a, t_mtx **b, int specs[2])
{
	t_mtx	*temp;

	specs[1] = 0;
	if (!specs[0] && ((*a == NULL) || ((*a)->shape[0] == 1)
			|| ((*a)->ndims == 1 && (*b)->ndims == 2)))
	{	
		temp = *a;
		*a = *b;
		*b = temp;
		if (*b != NULL)
			specs[1] = 1;
	}
}

static t_mtx	*route_opp(t_mtx *a, t_mtx *b, t_mtx *out, int specs[2])
{
	static MOPP_FUNC	opps[2][6] = {
		{_mtx_divi_scalar, _mtx_rdivi_scalar, _mtx_divi_line_r,
		_mtx_rdivi_line_r, _mtx_divi_line_c, _mtx_rdivi_line_c},
		{_mtx_divf_scalar, _mtx_rdivf_scalar, _mtx_divf_line_r,
		_mtx_rdivf_line_r, _mtx_divf_line_c, _mtx_rdivf_line_c}};
	int					rev;
	MOPP_FUNC			act_opp;

	printf("routing opp\n");
	rev = specs[1];
	act_opp = NULL;
	if (b->shape[0] == 1)
	{
		printf("Routing scalar opp\n");
		act_opp = opps[a->dtype == DTYPE_F][0 + rev];		
	}
	else if ((b->shape[0] == a->shape[1]) && !b->is_transposed)
	{
		printf("Routing line by row opp\n");
		act_opp = opps[a->dtype == DTYPE_F][2 + rev];
	}
	else if ((b->shape[0] == a->shape[0]) && b->is_transposed)
	{
		printf("Routing line by column opp\n");
		act_opp = opps[a->dtype == DTYPE_F][4 + rev];
	}
	if (act_opp)
		act_opp(a, b, out);
	else
		return (fperror("%s: mismatch shapes ", __FUNCTION__));
	return (out);
}

t_mtx	*mtx_div(t_mtx *a, t_mtx *b, t_mtx *out)
{
	t_mtx	*ret;
	int		same_shape;
	int		specs[2];
	int		out_null;

	out_null = !out;
	ret = out;
	printf("mtx_div entered\n");
	if (!(a || b) || !mtx_are_same_type(a, b, ret))
		return (fperror("%s: missing inputs or mismatch dtypes", __FUNCTION__));
	same_shape = mtx_are_same_shape(a, b);
	specs[0] = same_shape;
	printf("same_shape : %d\n", same_shape);
	put_biggest_first(&a, &b, specs);
	if (!ret && !mtx_dup_empty(a, &ret, a->dtype))
		return (fperror("%s: malloc error", __FUNCTION__));
	printf("ret is valid\n");
	if (same_shape && (a->dtype == DTYPE_F))
		_mtx_divf_mtx(a, b, ret);
	else if (same_shape && (a->dtype == DTYPE_I))
		_mtx_divi_mtx(a, b, ret);
	else if (!route_opp(a, b, ret, specs))
	{
		if (out_null)
			mtx_clear(&ret);
		ret = NULL;
	}
	return (ret);
}

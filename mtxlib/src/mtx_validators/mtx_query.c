/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_query.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:37:02 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/26 22:43:58 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	mtx_istransposed(t_mtx *mtx)
{
	return (mtx->is_transposed);
}

int mtx_are_same_type(t_mtx *a, t_mtx *b, t_mtx *out)
{
	if (out)
		return ((a->dtype == b->dtype) && (out->dtype == a->dtype));
	else
		return (a->dtype == b->dtype);
}

int	mtx_are_same_shape(t_mtx *a, t_mtx* b)
{
	return (a->shape[0] == b->shape[0] && a->shape[1] == b->shape[1]);
}

int	mtx_isvalid_dtype(int dtype)
{
	return ((dtype == DTYPE_I) || (dtype == DTYPE_F));
}

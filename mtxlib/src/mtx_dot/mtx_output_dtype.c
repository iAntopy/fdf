/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_output_dtype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:22:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 16:26:32 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

//TODO : implement mismatching dtypes promotion.
int	mtx_dtype_out(t_mtx *a, t_mtx *b)
{
	if (a->dtype == b->dtype)
		return (a->dtype);
	if (a->dtype == DTYPE_F || b->dtype == DTYPE_F)
		return (DTYPE_F);
	else
		return (DTYPE_I);
}

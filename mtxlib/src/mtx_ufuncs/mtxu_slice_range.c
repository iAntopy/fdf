/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_slice_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:48:29 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/20 03:19:04 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

// Start inclusive. End exclusive.
t_mtx	*mtx_select_row_range(t_mtx *mtx, int start, int end, t_mtx *out)
{
	int	slice[4];

	slice[0] = start;
	slice[1] = 0;
	slice[2] = end;
	slice[3] = INT_MAX;
	return (mtx_slice_view(mtx, slice, out));
}

// Start inclusive. End exclusive.
t_mtx	*mtx_select_col_range(t_mtx *mtx, int start, int end, t_mtx *out)
{
	int	slice[4];

	slice[0] = 0;
	slice[1] = start;
	slice[2] = INT_MAX;
	slice[3] = end;
	return (mtx_slice_view(mtx, slice, out));
}

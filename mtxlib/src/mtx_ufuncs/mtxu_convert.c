/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 05:48:03 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/22 05:48:20 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	convert_f_to_i(int *iarr, float *farr, size_t n_elem)
{
	while (n_elem--)
	{
		*iarr = 1;
		*(iarr++) *= *(farr++);
	}
}

static void	convert_i_to_f(float *farr, int *iarr, size_t n_elem)
{
	while (n_elem--)
	{
		*farr = 1;
		*(farr++) *= *(iarr++);
	}
}

void	mtx_convert_arr_type(t_mtx *new, t_mtx *old)
{
	if (old->dtype == DTYPE_F && new->dtype == DTYPE_I)
		convert_f_to_i(new->arr, old->arr, mtx_sizeof_array(new));
	else if (old->dtype == DTYPE_I && new->dtype == DTYPE_F)
		convert_i_to_f(new->arr, old->arr, mtx_sizeof_array(new));
}

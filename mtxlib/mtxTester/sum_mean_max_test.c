/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_mean_max_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 06:53:25 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/04 02:10:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"
	
const float	arr_f[4][3] = {{10, 20, 90},{40, 50, 60},{70, 80, 90},{900, 600, 300}};
const int	arr_i[4][3] = {{10, 20, 90},{40, 50, 60},{70, 80, 90},{900, 600, 300}};

int	main()
{
	t_mtx		*mtx;
	t_mtx		*mtx_view;
	const int	slice[4] = {0, 0, 3, INT_MAX};
	t_mtx		*out_row;
	t_mtx		*out_col;
	t_mtx		*out_scalar;

	int			is_INT_TEST = 0;
	if (is_INT_TEST)
	{
		mtx = mtx_create_array((int *)arr_i, 4, 3, DTYPE_I);
		mtx_print(mtx);
		out_scalar = mtx_sum(mtx, WHOLE, NULL);
		printf("sum of full array :\n");
		mtx_print(out_scalar);
	}
	else
	{
		mtx = mtx_create_array((float *)arr_f, 4, 3, DTYPE_F);
		mtx_print(mtx);
		out_scalar = mtx_sum(mtx, WHOLE, NULL);
		printf("sum of full array :\n");
		mtx_print(out_scalar);
	}

	printf("PASSED create array\n");
	out_row = mtx_sum(mtx, ROWWISE, NULL);
	printf("ROWWISE sum output : \n");
	mtx_print(out_row);
	out_col = mtx_sum(mtx, COLWISE, NULL);
	printf("COLWISE sum output : \n");
	mtx_print(out_col);

	mtx_mean(mtx, ROWWISE, out_row);
	printf("ROWWISE mean output : \n");
	mtx_print(out_row);
	mtx_mean(mtx, COLWISE, out_col);
	printf("COLWISE mean output : \n");
	mtx_print(out_col);

	mtx_view = mtx_slice_view(mtx, slice);
	printf("view slice : \n");
	mtx_print(mtx_view);
	mtx_display_info(mtx_view);

	mtx_sum(mtx_view, ROWWISE, out_row);
	printf("ROWWISE sum through view :\n");
	mtx_print(out_row);
	mtx_sum(mtx_view, COLWISE, out_row);
	printf("COLWISE sum through view :\n");
	mtx_print(out_row);
	
	mtx_mean(mtx_view, ROWWISE, out_row);
	printf("ROWWISE mean through view :\n");
	mtx_print(out_row);
	mtx_mean(mtx_view, COLWISE, out_row);
	printf("COLWISE mean through view :\n");
	mtx_print(out_row);

	mtx_transpose(mtx_view);
	printf("Transposed view : \n");
	mtx_print(mtx_view);
	mtx_display_info(mtx_view);

	printf("COLWISE sum through transposed view :\n");
	mtx_sum(mtx_view, COLWISE, out_row);
	mtx_print(out_row);

	mtx_clear_list(4, mtx, out_row, out_col, mtx_view);
	return (0);
}

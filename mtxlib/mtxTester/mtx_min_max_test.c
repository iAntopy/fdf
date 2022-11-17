/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_min_max_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 03:06:17 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 21:17:33 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

float	arr_f[4][3] = {{11, 2, 99},{44, 5, 6},{77, 8, 9},{987, 654, 321}};
int		arr_i[4][3] = {{11, 2, 99},{44, 5, 6},{77, 8, 9},{987, 654, 321}};

int	main()
{
	t_mtx	*mtx;
	t_mtx	*mtx_view;
	const int	slice[4] = {0, 0, 3, INT_MAX};
	t_mtx	*out_scalar;
	t_mtx	*out_row;
	t_mtx	*out_col;

	int		is_INT_TEST = 1;
	if (is_INT_TEST)
	{
		printf("It's alright !\n");
		mtx = mtx_create_array(arr_i, 4, 3, DTYPE_I);
		printf("It's NOT alright\n");
		mtx_print(mtx);
		out_scalar = mtx_min(mtx, WHOLE, NULL);
		printf("whole min scalar_result : \n");
		mtx_print(out_scalar);
	}
	else
	{
		mtx = mtx_create_array(arr_f, 4, 3, DTYPE_I);
		mtx_print(mtx);
		out_scalar = mtx_min(mtx, WHOLE, NULL);
		printf("whole min scalar_result : \n");
		mtx_print(out_scalar);
	}

	out_row = mtx_min(mtx, ROWWISE, NULL);
	printf("ROWWISE min output : \n");
	mtx_print(out_row);
	out_col = mtx_min(mtx, COLWISE, NULL);
	printf("COLWISE min output : \n");
	mtx_print(out_col);

	mtx_max(mtx, ROWWISE, out_row);
	printf("ROWWISE max output : \n");
	mtx_print(out_row);
	mtx_max(mtx, COLWISE, out_col);
	printf("COLWISE max output : \n");
	mtx_print(out_col);

	mtx_view = mtx_slice_view(mtx, slice);
	printf("view slice : \n");
	mtx_print(mtx_view);
	mtx_display_info(mtx_view);
	mtx_min(mtx_view, ROWWISE, out_row);
	printf("ROWWISE min through view :\n");
	mtx_print(out_row);
	mtx_min(mtx_view, COLWISE, out_row);
	printf("COLWISE min through view :\n");
	mtx_print(out_row);
	
	mtx_max(mtx_view, ROWWISE, out_row);
	printf("ROWWISE max through view :\n");
	mtx_print(out_row);
	mtx_max(mtx_view, COLWISE, out_row);
	printf("COLWISE max through view :\n");
	mtx_print(out_row);

	mtx_transpose(mtx_view);
	printf("Transposed view : \n");
	mtx_print(mtx_view);
	mtx_display_info(mtx_view);
	printf("COLWISE min through transposed view :\n");
	mtx_min(mtx_view, COLWISE, out_row);
	mtx_print(out_row);

	mtx_clear_list(4, mtx, out_row, out_col, mtx_view);
	return (0);
}

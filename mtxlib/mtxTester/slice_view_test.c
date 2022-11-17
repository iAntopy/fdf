/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice_view_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:57:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 05:57:04 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

float	arr[3][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};

int	main()
{
	t_mtx			*mtx;
	t_mtx			*view;
	t_mtx			*sub_view;
	const int		slice[4] = {1, 1, 3, 4};
	const int		sub_slice[4] = {0, 0, 1, 2};
	const float		fill_value = M_PI;

	mtx = mtx_create_array(arr, 3, 4, DTYPE_F);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("\n---SLICING---\n");
	view = mtx_slice_view(mtx, slice);
	mtx_print(view);
	mtx_display_info(view);

	printf("\n---TRANSPOSING VIEW---\n");
	mtx_transpose(view);
	mtx_print(view);
	mtx_display_info(view);

	printf("\n---SUB VIEW OF TRASPOSED VIEW---\n");
	sub_view = mtx_slice_view(view, sub_slice);
	mtx_print(sub_view);
	mtx_display_info(sub_view);

	printf("\n---PIMPIN' ME DATA ---\n");
	mtx_fill(sub_view, &fill_value);
	printf("\nsub_view post fill : \n");
	mtx_print(sub_view);
	mtx_display_info(sub_view);
	printf("\noriginal mtx post fill : \n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	mtx_clear(&mtx);
	mtx_clear(&view);
	mtx_clear(&sub_view);
	return (0);
}

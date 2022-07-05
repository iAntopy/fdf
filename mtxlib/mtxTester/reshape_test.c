/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reshape_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:45:32 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 19:02:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	main()
{
	t_mtx	*mtx;
	t_mtx	*line3;
	t_mtx	*out;


	printf("mtx :\n");
	mtx = mtx_arange(60, 72, DTYPE_I);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("line3 :\n");
	line3 = mtx_arange(2, 5, DTYPE_I);
	mtx_print(line3);
	mtx_display_info(line3);

	out = mtx_mul(mtx, line3, mtx);
	printf("out ptr : %p\n", out);
	if (out)
		printf("mtx_mul with <%d x %d> and <%d x %d> "GREEN_C"SUCCESS\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);
	else
		printf("mtx_mul with <%d x %d> and <%d x %d> "RED_C"FAILURE\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);
	
	mtx_reshape(mtx, 2, 6);
	mtx_print(mtx);
	mtx_display_info(mtx);

	mtx_reshape(mtx, 4, 3);
	mtx_print(mtx);
	mtx_display_info(mtx);
	
	out = mtx_mul(mtx, line3, mtx);
	if (out)
		printf("mtx_mul with <%d x %d> and <%d x %d> "GREEN_C"SUCCESS\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);
	else
		printf("mtx_mul with <%d x %d> and <%d x %d> "RED_C"FAILURE\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("transposing line3 :\n");
	mtx_transpose(line3);
	mtx_print(line3);
	mtx_display_info(line3);

	printf("dividing mtx by line3 columnwise :\n");
	out = mtx_div(mtx, line3, mtx);
	if (out)
		printf("mtx_div with <%d x %d> and <%d x %d> "GREEN_C"SUCCESS\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);
	else
		printf("mtx_div with <%d x %d> and <%d x %d> "RED_C"FAILURE\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);

	printf("Reshaping mtx to <3 x 4> : \n");
	mtx_reshape(mtx, 3, 4);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("dividing mtx by line3 columnwise (RETRY):\n");
	out = mtx_div(mtx, line3, mtx);
	if (out)
		printf("mtx_div with <%d x %d> and <%d x %d> "GREEN_C"SUCCESS\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);
	else
		printf("mtx_div with <%d x %d> and <%d x %d> "RED_C"FAILURE\n"WHITE_C, mtx->shape[0], mtx->shape[1], line3->shape[0], line3->shape[1]);
	
	mtx_print(mtx);
	mtx_display_info(mtx);
	return (0);
}

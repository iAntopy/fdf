/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_opps_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:51:19 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 01:12:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	line_opps_test()
{
	float	arr[3][3] = {{10, 20, 30}, {-1.5, -4.5, -9.99}, {9000, 6000, 3000}};
	t_mtx	*mtx;
	t_mtx	*lmtx;
	t_mtx	*out;

	mtx = mtx_create_array(arr, 3, 3, DTYPE_F);
	mtx_print(mtx);
	mtx_display_info(mtx);

	lmtx = mtx_arange(2, 5, DTYPE_F);
	mtx_transpose(lmtx);
	mtx_print(lmtx);
	mtx_display_info(lmtx);

	out = mtx_sub(lmtx, mtx, NULL);
	mtx_print(out);
	mtx_display_info(out);

	mtx_clear_list(3, mtx, lmtx, out);

}


int	main()
{
	t_mtx	*eye;
	t_mtx	*out;
	t_mtx	*scalar;
	int		value;
	int		value2;

	line_opps_test();
/*
	out = NULL;
	eye = NULL;
	scalar = NULL;
	value = 2;
	value2 = 100;
	printf("value ptr : %p\n", &value);
	eye = mtx_identity(3, NULL,  DTYPE_I);
	mtx_print(eye);
	mtx_display_info(eye);
	printf("identity created.\n");
	
	scalar = mtx_create_scalar(&value, DTYPE_I);
	printf("Scalar mtx created.\n");
	mtx_print(scalar);
	mtx_display_info(scalar);
	
	out = mtx_mul(eye, scalar, NULL);
	printf("out ptr after create : %p\n", out);
	mtx_print(out);
	mtx_display_info(out);
	printf("Will the output display at last ?\n");

	printf("Add 20 to output\n");
	_mtx_iaddi_pscalar(out, 20);
	mtx_print(out);
	mtx_display_info(out);

	printf("Mul scalar * 100\n");
	_mtx_imuli_pscalar(scalar, 100);
	mtx_print(scalar);
	mtx_display_info(scalar);


	mtx_div(scalar, out, out);
//	_mtx_ridivi_scalar(out, scalar);

	printf("output after div par scalar :\n");
	mtx_print(out);
	mtx_display_info(out);

	printf("Reprint eye just in case\n");
	mtx_print(eye);
	mtx_display_info(eye);
	mtx_clear_list(3, eye, scalar, out);
*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:57:22 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 20:17:00 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	main()
{
	t_mtx	*mtx;
	t_mtx	*expos;
	int		range[2] = {1, 4};

	expos = mtx_arange(1, 4, DTYPE_I);
	mtx = mtx_randint(4, 3, range, NULL);
	printf("\nmtx : \n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("\nexpos :\n");
	mtx_print(expos);
	mtx_display_info(expos);

	printf("\nput mtx to expos rowwise :\n");
	mtx_pow(mtx, expos, mtx);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("\nreset randint mtx and transpose : \n");
	mtx_randint(4, 3, range, mtx);
	mtx_transpose(mtx);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("\nput transpose mtx to expos rowwise :\n");
	mtx_pow(mtx, expos, mtx);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("\nTranspose to original side, transpose expos and mtx_pow colwise :\n");
	mtx_transpose(mtx);
	mtx_transpose(expos);
	mtx_pow(mtx, expos, mtx);
	mtx_print(mtx);
	mtx_display_info(mtx);


	mtx_clear_list(2, mtx, expos);

	return (0);
}

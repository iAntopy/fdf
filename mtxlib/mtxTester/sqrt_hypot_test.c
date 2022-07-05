/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt_hypot_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:44:11 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/04 01:41:49 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

#define	TOTAL_EXECS 1000

float	arr_f[4][3] = {{3, 4, 0},{0, 1, 1},{2, 0, 2},{987, 654, 321}};

int	main()
{
	t_mtx		*mtx;
	t_mtx		*sqrt_res;
	const int	slice[4] = {0, 0, 3, INT_MAX};
	t_mtx		*out;

	int		nb_execs;
	int		i;
	ssize_t		temps_total;
	double		t_time;

	mtx = NULL;
	sqrt_res = NULL;
	out = NULL;
	mtx = mtx_create_array(arr_f, 4, 3, DTYPE_F);
	mtx_print(mtx);
	mtx_display_info(mtx);

	printf("Square root of mtx : \n");
	sqrt_res = mtx_sqrtf(mtx, NULL);
	printf("sqrt_res ptr : %p\n", sqrt_res);
	mtx_print(sqrt_res);
	mtx_display_info(sqrt_res);

	printf("hypots of mtx : \n");
	printf("WOOOWOWOWOWOWO!\n");
	out = mtx_create_empty(mtx->shape[0], 1, DTYPE_F);

	ft_timedelta_usec(NULL);
	printf("Starting timed tests\n");
	{
		i = -1;
		while (++i < TOTAL_EXECS)
		{
//			printf("test %d\n", i);
			mtx_hypot(mtx, COLWISE, out);
			//__mtx_hypot_nx3(mtx->arr, mtx->shape[0], out->arr);
		}
	}
	temps_total = ft_timedelta_usec("mtx_hypot");
	t_time = 1;
	t_time *= temps_total;
	t_time /= TOTAL_EXECS;
	printf("%d execs d'hypot pas vite en %zd usec, ou %f usec par exec\n", TOTAL_EXECS, temps_total, t_time);

	mtx_print(out);
	mtx_display_info(out);

	mtx_clear_list(3, mtx, out, sqrt_res);
	return (0);
}

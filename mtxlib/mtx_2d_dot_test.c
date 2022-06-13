/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_2d_dot_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:30:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/12 22:40:41 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	init_arr[2] =	{1, 2};

int	init_arr2[2][2] =	{{1, 2},
						{3, 4}};

int	init_arr3[4][2] =	{{1, 2},
						{3, 4},
						{5, 6},
						{7, 8}};

int	main(void)
{
	t_mtx	*mtx;

	printf("pre creation.\n");
	mtx = mtx_create_nx2_i(4, (int *)init_arr3);
	printf("Creation SUCCESS. mtx ptr %p\n", mtx);
	printf("mtx arr ptr %p\n", mtx->arr);
	printf("pre mtx_print\n");
	mtx_print(mtx);
	printf("pre clear.\n");
	mtx_clear(&mtx);
	printf("Clear SUCCESS");

	return (0);
}

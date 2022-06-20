/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_dot_tester.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:23:50 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 19:38:55 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

float	arr[4][3] = {{1, 2, 3}, {5, 6, 7}, {9, 8, 7}, {6, 5, 4}};

int main()
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;


	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	mtx_print(mtx);
	mtx_display_info(mtx);
	
	eye = mtx_identity(3, DTYPE_F);
	*(float *)mtx_index(eye, 2, 2) = 10;
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_dot(mtx, eye, NULL);

	mtx_print(res);
	mtx_display_info(res);
	
	mtx_clear(&mtx);
	mtx_clear(&eye);
	mtx_clear(&res);
	return (0);
}

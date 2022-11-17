/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:24:14 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/07 15:44:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	main()
{
	t_mtx	mtx;
	float	arr[16];
	
	mtx.arr = arr;
	mtx_shell(&mtx, 4, 4, DTYPE_F);
	mtx_print(&mtx);

	__mtx_rotation_matrix_4x4(M_PI / 2, 0, 0, arr);
	mtx_print(&mtx);
	return (0);
}

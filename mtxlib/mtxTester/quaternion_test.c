/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:49:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/07 17:49:59 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	main()
{
	t_quat	*quat;

	quat = quat_create(M_PI / 2, 10000000, 0, 0);
	mtx_print(quat->mtx);
	quat->uv[1] = 0;
	quat->uv[2] = 1;
	quat->uv[3] = 0;
	_quat_update(quat, quat->uv, M_PI / 4);
	mtx_print(quat->mtx);


	return (0);
}

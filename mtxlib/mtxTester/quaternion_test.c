/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:49:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/20 03:03:56 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

float	p[4] = {0, 1, 0, 1};

int	main()
{
	t_mtx	*vect;
	t_quat	*quat;
	t_quat	*quat2;
	t_quat	comb;
	t_mtx	*rvect;
	
	vect = mtx_create_array(p, 4, 1, DTYPE_F);
	printf("vector : \n");
	mtx_print(vect);

	//quaternion Rotatation 90° arounf x axis,
	quat = quat_create(M_PI / 2, 1, 0, 0);
	printf("\nQuaternion Rotation of 90° around X axis : ptr %p \n", quat->rot_mtx);
	mtx_print(quat->rot_mtx);
	return (0);
	quat->uv[1] = 0;
	quat->uv[2] = 1;
	quat->uv[3] = 0;
	_quat_update(quat, quat->uv, M_PI / 2);
	printf("\nUpdated quaternion. Rotation of 90° around Y axis :\n");
	mtx_print(quat->rot_mtx);

	quat2 = quat_create(M_PI / 2, 0, 1, 0);
	quat_create_empty(&comb);
	quat_combine(quat, quat2, &comb);

	printf("\nQuaternion combination of these quaternions :\n");
	printf("q1 : w %f, a %f, b %f c %f\n", quat->q[0], quat->q[1], quat->q[2], quat->q[3]);
	printf("q1 uv : x %f, y %f, z %f\n", quat->uv[1], quat->uv[2], quat->uv[3]);
	printf("q1 : ang %f\n", quat->ang);
	printf("q1 : rot_mtx :\n");
	mtx_print(quat->rot_mtx);

	printf("\nq2 : w %f, a %f, b %f c %f\n", quat2->q[0], quat2->q[1], quat2->q[2], quat2->q[3]);
	printf("q2 uv : x %f, y %f, z %f\n", quat2->uv[1], quat2->uv[2], quat2->uv[3]);
	printf("q2 : ang %f\n", quat2->ang);
	printf("q2 : rot_mtx :\n");
	mtx_print(quat2->rot_mtx);

	printf("\ncomb : w %f, a %f, b %f c %f\n", comb.q[0], comb.q[1], comb.q[2], comb.q[3]);
	printf("comb uv : x %f, y %f, z %f\n", comb.uv[1], comb.uv[2], comb.uv[3]);
	printf("comb : ang %f\n", comb.ang);
	printf("comb : rot_mtx :\n");
	mtx_print(comb.rot_mtx);

	rvect = quat_rotate(vect, &comb, NULL);
	printf("rotated vector : \n");
	mtx_print(rvect);

	mtx_clear_list(2, vect, rvect);
	free(quat);
	free(quat2);
	return (0);
}

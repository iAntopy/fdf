/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 05:20:09 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/17 06:02:44 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	quat_display_info(t_quat *q)
{
	printf("\n@@____________( Quaternion %p )__________@@\n", q);
	printf("@@\n@@	- angle : %f\n", q->ang);
	printf("@@	- unit vect : [ %f, %f, %f, %f ]\n", q->uv[0], q->uv[1], q->uv[2], q->uv[3]);
	printf("@@	- quat (w, x, y, z) : ( %f, %f, %f, %f )\n", q->q[0], q->q[1], q->q[2], q->q[3]);
	printf("@@	- rot mat : \n");
	mtx_print(q->rot_mtx);
	printf("@@_________________________________________@@\n");
}

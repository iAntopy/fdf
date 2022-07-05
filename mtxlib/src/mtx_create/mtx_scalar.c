/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_scalar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:28:18 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/29 18:16:53 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_create_scalar(void *s, int dtype)
{
	t_mtx	*mtx;

	mtx = mtx_create_array(s, 1, 1, dtype);
	printf("mtx_create_scalar value in float/int: %f, %d\n", *(float *)mtx->arr, *(int *)mtx->arr);
	if (!mtx)
		return (NULL);
	return (mtx);
}

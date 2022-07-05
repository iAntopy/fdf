/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_transpose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:43:47 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 17:44:40 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_transpose(t_mtx *mtx)
{
	mtx->is_transposed = 1;
	if (mtx->ndims == 1)
		return (NULL);
	ft_swap_i(&mtx->shape[0], &mtx->shape[1]);
	ft_swap_i(&mtx->strides[0], &mtx->strides[1]);
	return (mtx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:22:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/12 22:40:44 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	mtx_print_i(t_mtx *mtx)
{
	int		*marr;
	int		i;
	int		j;

	if (!marr || !(mtx->arr) || mtx->dtype != DTYPE_I)
		return ;
	marr = mtx->arr;
	i = -1;
	if (mtx->ndims == 1)
	{
		printf("[ ");
		while (++i < mtx->shape[0] - 1)
			printf("%5d, ", marr[i]);
		printf("%5d ]\n", marr[i]);
	}
	else if (mtx->ndims == 2)
	{
		while (++i < mtx->shape[0])
		{
			j = -1;
			printf("[ ");
			while (++j < mtx->shape[1] - 1)
				printf("%5d, ", marr[i * mtx->shape[1] + j]);
			printf("%5d ]\n", marr[i * mtx->shape[1] + j]);
		}
	}
}

void	mtx_print_f(t_mtx *mtx)
{
	float	*marr;
	int		i;
	int		j;

	if (!marr || !(mtx->arr) || mtx->dtype != DTYPE_F)
		return ;
	marr = mtx->arr;
	i = -1;
	if (mtx->ndims == 1)
	{
		printf("[ ");
		while (++i < mtx->shape[0] - 1)
			printf("%6.3f, ", marr[i]);
		printf("%6.3f ]\n", marr[i]);
	}
	else if (mtx->ndims == 2)
	{
		printf("[ ");
		while (++i < mtx->shape[0])
		{
			j = -1;
			while (++j < mtx->shape[1] - 1)
				printf("%6.3f, ", marr[i * mtx->shape[1] + j]);
			printf("%6.3f\n", marr[i * mtx->shape[1] + j]);
		}
		printf(" ]\n");
	}
}

void	mtx_print(t_mtx *mtx)
{
	if (!mtx)
		return ;
	if (mtx->dtype == DTYPE_F)
		mtx_print_f(mtx);
	else if (mtx->dtype == DTYPE_I)
		mtx_print_i(mtx);
}

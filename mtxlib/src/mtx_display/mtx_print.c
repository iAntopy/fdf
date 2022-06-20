/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:22:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 19:36:59 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	mtx_print_i(t_mtx *mtx)
{
//	int		*marr;
	int		i;
	int		j;

//	marr = mtx->arr;
	if (!mtx || !(mtx->arr) || mtx->dtype != DTYPE_I)
		return ;
	i = -1;
	if (mtx->ndims == 1)
	{
		printf("[ ");
		while (++i < mtx->shape[0] - 1)
			printf("%5d, ", *(int *)_mtx_idx(mtx, i, 0));
//			printf("%5d, ", marr[i]);
		printf("%5d ]\n", *(int *)_mtx_idx(mtx, i, 0));
	}
	else if (mtx->ndims == 2)
	{
		printf("[");
		while (++i < mtx->shape[0])
		{
			j = -1;
			printf("%c[", " "[!i]);
			while (++j < mtx->shape[1] - 1)
				printf("%5d, ", *(int *)_mtx_idx(mtx, i, j));
			printf("%5d]%c", *(int *)_mtx_idx(mtx, i, j), "\n"[i == (mtx->shape[0] - 1)]);
		}
		printf("]\n");
	}
}

void	mtx_print_f(t_mtx *mtx)
{
//	float	*marr;
	int		i;
	int		j;

//	marr = mtx->arr;
	if (!mtx || !(mtx->arr) || mtx->dtype != DTYPE_F)
		return ;
	i = -1;
	if (mtx->ndims == 1)
	{
		printf("[ ");
	//	printf("mtx_print_f : pre over\n");
		while (++i < mtx->shape[0] - 1)
		{
//			mtx_display_info(mtx);
//			printf("mtx_print_f : indexing at ");
			printf("%6.3f, ", *(float *)_mtx_idx(mtx, i, 0));
//			printf("%6.3f, ", marr[i]);
		}

	//	printf("mtx_print_f : while over\n");
		printf("%6.3f ]\n", *(float *)_mtx_idx(mtx, i, 0));
	}
	else if (mtx->ndims == 2)
	{
		printf("[");
		while (++i < mtx->shape[0])
		{
			j = -1;
			printf("%c[ ", " "[!i]);
			while (++j < mtx->shape[1] - 1)
				printf("%6.3f, ", *(float *)_mtx_idx(mtx, i, j));
			printf("%6.3f ]%c", *(float *)_mtx_idx(mtx, i, j), "\n"[i == (mtx->shape[0] - 1)]);
		}
		printf("]\n");
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

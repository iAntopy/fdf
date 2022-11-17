/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_raw_whole_sum_prod.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:00:31 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 22:02:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

//works on full raw array, NOT on views.
int	__mtx_prod_i(int *arr, size_t n_elem)
{
	int	prod;

	prod = *(arr++);
	while (--n_elem)
		prod *= *(arr++);
	return (prod);
}

//works on full raw array, NOT on views.
float	__mtx_prod_f(float *arr, size_t n_elem)
{
	float	prod;

	prod = *(arr++);
	while (--n_elem)
		prod *= *(arr++);
	return (prod);
}

//works on full raw array, NOT on views.
int	__mtxu_sum_i(int *arr, size_t n_elem)
{
	int	sum;

	sum = *(arr++);
	while (--n_elem)
		sum += *(arr++);
	return (sum);
}

//works on full raw array, NOT on views.
float	__mtxu_sum_f(float *arr, size_t n_elem)
{
	float	sum;

	sum = *(arr++);
	while (--n_elem)
		sum += *(arr++);
	return (sum);
}

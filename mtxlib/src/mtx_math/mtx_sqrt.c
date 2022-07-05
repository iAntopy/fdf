/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:36:19 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:13:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// DOES NOT work with views
void	__mtx_isqrtf(float *arr, size_t n_elem)
{
	while (n_elem--)
	{
		*arr = sqrtf(*arr);
		arr++;
	}
}

// DOES NOT work with views
void	__mtx_sqrtf(float *arr, float *out, size_t n_elem)
{
	while (n_elem--)
	{
		*out = sqrtf(*arr);
		out++;
		arr++;
	}
}

t_mtx	*mtx_sqrtf(t_mtx *mtx, t_mtx *out)
{
	printf("Get in the weeds\n");
	return (mtx_apply_f(mtx, sqrtf, out));
}

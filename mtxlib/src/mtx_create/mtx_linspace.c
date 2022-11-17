/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_linspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:36:23 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:38:54 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_linspace(float start, float end, int n_divs, int w_end)
{
	t_mtx	*mtx;
	float	range;
	float	incr;
	int	i;
	float	*fptr;

	if (!n_divs || start == end)
		return (mtx_fperror("mtx_linspace : n_divs or range == 0"));
	n_divs += !!w_end;
	mtx = mtx_create_empty(n_divs, 1, DTYPE_F);
	if (!mtx)
		return (NULL);
	mtx_print(mtx);
	mtx_display_info(mtx);
	range = end - start;
	incr = range / (n_divs - !!w_end);
	i = -1;
	while (++i < n_divs)
	{
		fptr = mtx_index(mtx, i, 0);
		if (!fptr)
			return (mtx_clear(&mtx));
		*fptr = start;
		start += incr;
	}
	return (mtx);
}

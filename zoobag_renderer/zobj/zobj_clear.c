/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zobj_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:01:09 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/15 16:47:21 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoobag.h"

void	zb_clear_zobj(t_zobj **zo)
{
	if (zo->ncoords)
		mtx_clear(&(zo->ncoords));
	if (zo->wcoords)
		mtx_clear(&(zo->wcoords));
	if (zo->scoords)
		mtx_clear(&(zo->scoords));
	if (zo->indices)
		mtx_clear(&(zo->indices));
	malloc_free_p(0, (void **)zo);
}

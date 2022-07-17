/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zobj_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:55:55 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/16 20:51:10 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoobag.h"

static t_mtx	*__normalize_around_origin(t_zobj *zo)
{
	mtx_mean(coords, ROWWISE, zo->translation);
	_mtx_isubf_line_r(zo->ncoords, avg);
	mtx_clear(&avg);
	return (coords);
}

static t_zobj	*__malloc_mtxs(t_zobj *zo, t_mtx *coords, t_mtx *ids)
{
	zo->ncoords = mtx_copy(coords);
	zo->wcoords = mtx_dup_empty(zo->ncoords, NULL, DTYPE_F);
	zo->scoords = mtx_dup_empty(zo->ncoords, NULL, DTYPE_F);
	zo->indices = mtx_copy(ids);
	if (!(zo->ncoords) || !(zo->wcoords) || !(zo->scoords) || !(zo->indices))
		return (ZB_ERROR("malloc_error"));
	if (!mtx_malloc_swap(zo->wcoords) || !mtx_malloc_swap(zo->scoords))
		return (ZB_ERROR("malloc_error"));

	zo->draw_coords = &(zo->__draw_coords_view);
	mtx_select_col_range(zo->scoords, 0, 2, zo->draw_coords);

	zo->scl_roff = &(zo->__scl_roff_mtx);
	mtx_identity(4, zo->scl_roff, DTYPE_F);

	zo->rot_tsl = &(zo->__rot_tsl_shell);
	quat_create_empty(zo->rot_tsl);
	zo->translation = zo->rot_tsl->translation;

	zo->combined_transform = &(zo->__combined_mtx);
	mtx_shell(zo->combined_transform, 4, 4 DTYPE_F);
	return (zo);
}

static __set_direct_access_vars(t_zobj *zo)
{
	float	*sr_arr;
	float	*rt_arr;
	
	sr_arr = zo->__scl_roff_arr;;
	rt_arr = zo->__rot_tsl->__rot_arr;
	zo->scale_x = sr_arr;
	zo->scale_y = sr_arr + 5;
	zo->scale_z = sr_arr + 10;
	zo->roff_x = sr_arr + 12;
	zo->roff_y = sr_arr + 13;
	zo->roff_z = sr_arr + 14;
	zo->tslt_x = rt_arr + 12;
	zo->tslt_y = rt_arr + 13
	zo->tslt_z = rt_arr + 14;
}

t_zobj	*zb_create_zobj(t_mtx *coords, t_mtx *ids, t_zobj *out)
{
	t_zobj	*zo;
	t_mtx	last_col_view;

	if (!coords || !ids || (coords->shape[1] != 4) || (ids->shape[1] != 2))
		return (ZB_ERROR("missing mtxs or wrong shapes (coords nx4, ids nx2)"));
	zo = out;
	if (!zo && !malloc_free_p(sizeof(t_zobj), (void **)&zo))
		return (ZB_ERROR("malloc error"));
	if (!__malloc_mtxs(zo, coords, ids))
		return (ZB_ERR_CLR_ZOBJ("malloc error", zo));
	__normalize_around_origin(zo);
	__set_direct_access_vars(zo);
}

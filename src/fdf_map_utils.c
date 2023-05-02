/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:44:40 by iamongeo          #+#    #+#             */
/*   Updated: 2023/05/01 23:02:30 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fmap_update_transform(t_fmap *map)
{
	quat_rotate(map->scaling_tf, map->rotation_tf, map->transform);
}

static void	fmap_update_scaling(t_fmap *map, int update_transform)
{
	float	*sc;

	sc = (float *)map->__sc_arr;
	sc[0] = map->scalars[0];
	sc[5] = map->scalars[1];
	sc[10] = map->scalars[2];
	sc[15] = 1;
	if (update_transform)
		fmap_update_transform(map);
}

static void	fmap_update_rotation(t_fmap *map, int update_transform)
{
	quat_reset(map->rotation_tf);
	quat_add(map->rotation_tf, map->thetas[0], map->thetas[1], map->thetas[2]);
	if (update_transform)
		fmap_update_transform(map);
}

static void	fmap_update_translation(t_fmap *map, int update_transform)
{
	_quat_translation_set(map->rotation_tf, map->pos[0], map->pos[1], map->pos[2]);
	if (update_transform)
		fmap_update_transform(map);
}

int	fmap_update(t_fmap *map)
{
//	printf("fmap update : entered\n");
	if (!map)
		return (-1);
	fmap_update_scaling(map, 0);
//	printf("fmap update : scaling DONE\n");
	fmap_update_rotation(map, 0);
//	printf("fmap update : rotation DONE\n");
	fmap_update_translation(map, 1);
//	printf("fmap update : translation DONE\n");
	return (0);
}

int	fmap_init(t_fmap *map, int width, int height)
{
	if (!map)
		return (-1);
	ft_memclear(map, sizeof(t_fmap));

	map->w = width;
	map->h = height;
	
	map->transform = &map->__final_tf;
	map->scaling_tf = &map->__scaling_tf;
	map->rotation_tf = &map->__rotation_tf;
	map->homogenious_vect = &map->__homogenious_vect;

	map->transform->arr = map->__tf_arr;
	map->scaling_tf->arr = map->__sc_arr;

	mtx_shell(map->transform, 4, 4, DTYPE_F);
	mtx_shell(map->scaling_tf, 4, 4, DTYPE_F);
	quat_create_empty(map->rotation_tf);
	
	map->scalars[0] = 1;
	map->scalars[1] = 1;
	map->scalars[2] = 1;
	return (fmap_update(map));
}

void	fmap_rotate(t_fmap *map, float rx, float ry, float rz)
{
	map->thetas[0] += rx;
	map->thetas[1] += ry;
	map->thetas[2] += rz;
	fmap_update_rotation(map, 1);
}

void	fmap_set_rotation(t_fmap *map, float rx, float ry, float rz)
{
	map->thetas[0] = rx;
	map->thetas[1] = ry;
	map->thetas[2] = rz;
	fmap_update_rotation(map, 1);
}

void	fmap_move(t_fmap *map, float dx, float dy, float dz)
{
	map->pos[0] += dx;
	map->pos[1] += dy;
	map->pos[2] += dz;
	fmap_update_translation(map, 1);
}

void	fmap_set_position(t_fmap *map, float x, float y, float z)
{
	map->pos[0] = x;
	map->pos[1] = y;
	map->pos[2] = z;
	fmap_update_translation(map, 1);
}

void	fmap_scale(t_fmap *map, float sx, float sy, float sz)
{
	map->scalars[0] *= sx;
	map->scalars[1] *= sy;
	map->scalars[2] *= sz;
	fmap_update_scaling(map, 1);
}

void	fmap_set_scale(t_fmap *map, float sx, float sy, float sz)
{
	map->scalars[0] = sx;
	map->scalars[1] = sy;
	map->scalars[2] = sz;
	fmap_update_scaling(map, 1);
}

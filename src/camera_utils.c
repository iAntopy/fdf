/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:07:52 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/23 17:03:17 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	camo_update_transform(t_camo *cam)
{
	if (!cam || !cam->base_projection || !cam->rot || !cam->transform)
		return (-1);
	quat_rotate(cam->base_projection, cam->rot, cam->transform);
	return (0);
}

// base projection holds the camera position translation data
// Call this function anytime the camera position changes.
static void	camo_update_base_projection(t_camo *cam, int update_transform)
{
	float	rx;
	float	ry;
	float	rz;
	float	*arr;

	rx = cam->ortho_ratio_x;
	ry = cam->ortho_ratio_y;
	rz = cam->ortho_ratio_z;
	__mtx_fill_zeros(cam->base_projection);
	arr = (float *)_mtx_arr(cam->base_projection);
	arr[0] = rx;
	arr[5] = ry;
	arr[10] = rz;
	arr[12] = rx * cam->__pos_arr[0];
	arr[13] = rx * cam->__pos_arr[1];
	arr[14] = rx * cam->__pos_arr[2];
	arr[15] = 1;
	if (update_transform)
		camo_update_transform(cam);
}

// Holds the rotation transformation data. Call this function anytime
// the orientation changes in any direction.
static void	camo_update_rotation(t_camo *cam, int update_transform)
{
	quat_reset(cam->rot);
	quat_add(cam->rot, -cam->thetas[0], -cam->thetas[1], -cam->thetas[2]);
	if (update_transform)
		camo_update_transform(cam);
}

int	camo_update(t_camo *cam)
{
	if (!cam)
		return (-1);
	camo_update_base_projection(cam, 0);
	camo_update_rotation(cam, 1);
	return (0);
}

// Orthogonal camera utils
int	camo_init(t_camo *cam, const float *init_pos, const float *init_thetas)
{
	printf("camo init : entered\n");
	if (!cam)
		return (-1);
	printf("camo init : checked\n");
	cam->ortho_ratio_x = 2 / SCN_WIDTH;
	cam->ortho_ratio_y = 2 / SCN_HEIGHT;
	cam->ortho_ratio_z = 2 / SCN_WIDTH;
	
	cam->transform = cam->__mtx_pool;
	cam->base_projection = cam->__mtx_pool + 1;
	cam->pos = cam->__mtx_pool + 2;
	
	cam->pos->arr = cam->__pos_arr;
	cam->base_projection->arr = cam->__base_arr;
	cam->transform->arr = cam->__transform_arr;
	
	mtx_shell(cam->pos, 3, 1, DTYPE_F);
	mtx_shell(cam->base_projection, 4, 4, DTYPE_F);
	mtx_shell(cam->transform, 4, 4, DTYPE_F);
//	mtx_transpose(cam->pos);
	quat_create_empty(cam->rot);
	if (init_pos)
	{
		mtx_set_index_f(cam->pos, 0, 0, init_pos[0]);
		mtx_set_index_f(cam->pos, 1, 0, init_pos[1]);
		mtx_set_index_f(cam->pos, 2, 0, init_pos[2]);
	}
	if (init_thetas)
	{
		cam->thetas[0] = init_thetas[0];
		cam->thetas[1] = init_thetas[1];
		cam->thetas[2] = init_thetas[2];
	//	quat_add(cam->transform, -init_thetas[0], -init_thetas[1], -init_thetas[2]);
	}
	printf("camo init : before cam update\n");
	camo_update(cam);
	quat_display_info(cam->rot);
	printf("camo init : after cam update\n");
//	quat_rotate(cam->pos, cam->transform, cam->transform->translation);
//	mtx_set_index_f(cam->transform->translation, 3, 0, 1.0f);
	return (0);
}

// Changes camera state BUT DOES NOT UPDATE CAM TRANSFORM. Call cam_update() once
// after all modification are done.
void	camo_move(t_camo *cam, float dx, float dy, float dz)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	cam->__pos_arr[0] += dx;
	cam->__pos_arr[1] += dy;
	cam->__pos_arr[2] += dz;
}

// Changes camera state BUT DOES NOT UPDATE CAM TRANSFORM. Call cam_update() once
// after all modification are done.
void	camo_rotate(t_camo *cam, float rll, float ptc, float yaw)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	cam->thetas[0] += rll;
	cam->thetas[1] += ptc;
	cam->thetas[2] += yaw;
//	cam_update(cam);
}

void	camo_set_position(t_camo *cam, float x, float y, float z)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	cam->__pos_arr[0] = x;
	cam->__pos_arr[1] = y;
	cam->__pos_arr[2] = z;
}

void	camo_set_rotation(t_camo *cam, float rll, float ptc, float yaw)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	cam->thetas[0] = rll;
	cam->thetas[1] = ptc;
	cam->thetas[2] = yaw;
}
/*

void	camo_look_at(t_camo *cam, t_mtx *mtx)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	// TODO
}

// Change camera orientation so to look at point (x, y, z) from current 
// camera position.
void	camo_look_at_coord(t_camo *cam, float x, float y, float z)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
//	TODO
}
*/

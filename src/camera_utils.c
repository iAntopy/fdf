/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:07:52 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/29 00:19:15 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	camo_update_transform(t_camo *cam)
{
	if (!cam || !cam->base_projection || !cam->rot || !cam->transform)
		return (-1);

//	printf("camo update : base proj : \n");
//	mtx_print(cam->base_projection);
//	printf("camo update : rotation quaternion : \n");
//	quat_display_info(cam->rot);
//	__mtx_dotf_4x4_4x4((float *)cam->rot->__rot_arr, (float *)cam->__base_arr, (float *)cam->__transform_arr);
	__mtx_dotf_4x4_4x4((float *)cam->__base_arr, (float *)cam->rot->__rot_arr, (float *)cam->__transform_arr);
//	quat_rotate(cam->base_projection, cam->rot, cam->transform);
	return (0);
}

// base projection holds the camera position translation data
// Call this function anytime the camera position changes.
static void	camo_update_ortho_projection(t_camo *cam, int update_transform)
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
	arr[12] = rx * -cam->__pos_arr[0];
	arr[13] = ry * -cam->__pos_arr[1];
	arr[14] = rz * -cam->__pos_arr[2];
	arr[15] = 1;
	if (update_transform)
		camo_update_transform(cam);
}

static void	camo_init_perspective_projection(t_camo *cam, int update_transform)
{
	float	*arr;

	arr = cam->__base_arr;
	arr[0] = cam->pspct_ratio_x;
	arr[5] = cam->pspct_ratio_y;
	arr[10] = cam->pspct_ratio_z1;
	arr[11] = 1;
	arr[14] = cam->pspct_ratio_z2;
}

static void	camo_update_position(t_camo *cam)
{
	float	*rot;
	float	*pos;
	float	*rpos;

	rot = (float *)cam->rot->arr;
	rpos = rot + 12;
	pos = cam->__pos_arr;
	rot[12] = pos[0] * rot[0] + pos[1] * rot[4] + pos[2] * rot[8];
	rot[13] = pos[0] * rot[1] + pos[1] * rot[5] + pos[2] * rot[9];
	rot[14] = pos[0] * rot[2] + pos[1] * rot[6] + pos[2] * rot[10];
}

// Holds the rotation transformation data. Call this function anytime
// the orientation changes in any direction.
static void	camo_update_rotation(t_camo *cam, int update_transform)
{
	__mtx_rotation_matrix_YXZ(-cam->thetas[0], -cam->thetas[1], -cam->thetas[2], rot);
	camo_update_position(cam);

///	quat_reset(cam->rot);
//	quat_add(cam->rot, -cam->thetas[0], -cam->thetas[1], -cam->thetas[2]);
///	_quat_translation_set(cam->rot,
//		-cam->__pos_arr[0] * cam->ortho_ratio_x,
//		-cam->__pos_arr[1] * cam->ortho_ratio_y,
///		-cam->__pos_arr[2] * cam->ortho_ratio_z);
///	_quat_translation_set(cam->rot, -cam->__pos_arr[0], cam->__pos_arr[1], cam->__pos_arr[2]);
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
int	camo_init(t_camo *cam, const float *init_pos, const float *dims,
	   			const float farnear[2], const float *init_thetas, int cam_type)
{
	printf("camo init : entered\n");
	if (!cam)
		return (-1);
	printf("camo init : checked\n");
	cam->transform = cam->__mtx_pool;
	cam->base_projection = cam->__mtx_pool + 1;
	cam->pos = cam->__mtx_pool + 2;
	cam->rot = cam->__qpool;
	printf("camo init : checked 3\n");
	
	cam->pos->arr = cam->__pos_arr;
	cam->base_projection->arr = cam->__base_arr;
	cam->transform->arr = cam->__transform_arr;
	printf("camo init : checked 4\n");
	
	mtx_shell(cam->pos, 3, 1, DTYPE_F);
	mtx_shell(cam->base_projection, 4, 4, DTYPE_F);
	mtx_shell(cam->transform, 4, 4, DTYPE_F);
	printf("camo init : checked 5\n");
//	mtx_transpose(cam->pos);
	quat_create_empty(cam->rot);
	printf("camo init : shells and quats init\n");
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
	if (cam_type == CAM_ORTHO)
	{
		cam->dimentions[0] = dims[0];
		cam->dimentions[1] = dims[1];
	
		cam->ortho_ratio_x = 2.0f / dims[0];//SCN_WIDTH;
		cam->ortho_ratio_y = 2.0f / dims[1];//SCN_HEIGHT;
		cam->ortho_ratio_z = 1.0f / dims[1];//SCN_WIDTH;
		camo_init_ortho_projection(cam);
	}
	else if (cam_type == CAM_PERSPECTIVE)
	{
		cam->pspct_ratio_x = 1 / (ASPECT_RATIO * tan(VERT_FOV / 2));
		cam->pspct_ratio_y = 1 / (tan(VERT_FOV / 2));
		cam->pspct_ratio_z1 = farnear[0] / (farnear[0] - farnear[1]);
		cam->pspct_ratio_z2 = -n * cam->pspct_ratio_z1;
		camo_init_perspective_projection(cam);
	}

	printf("camo init : ortho ratios x y z : %f, %f, %f\n", cam->ortho_ratio_x, cam->ortho_ratio_y, cam->ortho_ratio_z);
	printf("camo init : init pos and thetas setup\n");
	printf("camo init : before cam update\n");
	camo_update(cam);

	printf("camo init : after cam update\n");
	printf("cam init : base projection :\n");
	mtx_print(cam->base_projection);
	printf("cam init : rotation quaternion info :\n");
	quat_display_info(cam->rot);
	printf("camo init : after cam update\n");

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
	printf("new cam position : (%f, %f, %f)\n", cam->__pos_arr[0], cam->__pos_arr[1], cam->__pos_arr[2]);
	camo_update_rotation(cam, 1);
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
	camo_update_rotation(cam, 1);
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
	printf("new cam position : (%f, %f, %f)\n", cam->__pos_arr[0], cam->__pos_arr[1], cam->__pos_arr[2]);
	camo_update_rotation(cam, 1);
//	camo_update_base_projection(cam, 1);
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
	camo_update_rotation(cam, 1);
}

void	camo_zoom(t_camo *cam, float factor)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	cam->dimentions[0] *= factor;
	cam->dimentions[1] *= factor;
	cam->ortho_ratio_x = 2.0f / cam->dimentions[0];//SCN_WIDTH;
	cam->ortho_ratio_y = 2.0f / cam->dimentions[1];//SCN_HEIGHT;
	cam->ortho_ratio_z = 2.0f / cam->dimentions[1];//SCN_WIDTH;
	camo_update_base_projection(cam, 1);
}
/*
// Combines the modelview matrix with cam transform then appies the
// transform to b = base_coords, and outputs the result in s = screen_coords
void	camo_apply_transform(t_camo *cam, t_fmap *model, t_mtx *b, t_mtx *s)
{
	float	final_tf[4][4];
	t_mtx	DELETE_ME;
	
	DELETE_ME.arr = (float *)final_tf;
	mtx_shell(&DELETE_ME, 4, 4, DTYPE_F);

	__mtx_dotf_4x4_4x4((float *)model->transform->__rot_arr, (float *)cam->transform->arr, (float *)final_tf);
	
	printf("camo apply : model transform\n");
	quat_display_info(model->transform);
	printf("camo apply : cam transform\n");
	mtx_print(cam->transform);
	printf("camo apply : final transform\n");
	mtx_print(&DELETE_ME);

	__mtx_dotf_nx4_4x4(model->w * model->h, (float *)b->arr, (float *)final_tf, (float *)s->arr);
}
*/
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

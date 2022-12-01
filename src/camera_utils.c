/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:07:52 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/30 19:51:47 by iamongeo         ###   ########.fr       */
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
	__mtx_dotf_4x4_4x4((float *)cam->rot->arr, (float *)cam->__base_arr, (float *)cam->__transform_arr);
//	if (cam->cam_type == CAM_PERSPECTIVE)
//		_mtx_idivf_pscalar
//	__mtx_dotf_4x4_4x4((float *)cam->__base_arr, (float *)cam->rot->__rot_arr, (float *)cam->__transform_arr);
//	quat_rotate(cam->base_projection, cam->rot, cam->transform);
	return (0);
}

// base projection holds the camera position translation data
// Call this function anytime the camera position changes.
static void	camo_init_ortho_projection(t_camo *cam, int update_transform)
{
	float	*arr;

	cam->far = 1000;//farnear[0];
	cam->near = 0.1;//farnear[1];
	cam->top = cam->dimentions[1] / 2;//cam->near * tan(cam->fov / 2);
	cam->bottom = -cam->top;
	cam->right = cam->dimentions[0] / 2;//cam->aspect_ratio * cam->top;
	cam->left = -cam->right;
	cam->ortho_ratio_x = 1.0f / cam->right;//2.0f / dims[0];//SCN_WIDTH;
	cam->ortho_ratio_y = 1.0f / cam->top;//dims[1];//SCN_HEIGHT;
	cam->ortho_ratio_z = 1.0f / (cam->far - cam->near);//dims[1];//SCN_WIDTH;
//	__mtx_fill_zeros(cam->base_projection);
	arr = (float *)_mtx_arr(cam->base_projection);
	arr[0] = cam->ortho_ratio_x;
	arr[5] = cam->ortho_ratio_y;
	arr[10] = cam->ortho_ratio_z;
	arr[12] = cam->ortho_ratio_x;
	arr[13] = cam->ortho_ratio_y;
	arr[14] = cam->ortho_ratio_z;
	arr[15] = 1;
	if (update_transform)
		camo_update_transform(cam);
}

static void	camo_init_perspective_projection(t_camo *cam, int update_transform)
{
	float	*arr;

	cam->top = cam->near * tan(cam->fov / 2);
	cam->bottom = -cam->top;
	cam->right = cam->aspect_ratio * cam->top;
	cam->left = -cam->right;
	cam->pspct_ratio_x = cam->near / cam->right;//1 / (cam->aspect_ratio * tan(cam->fov / 2));
	cam->pspct_ratio_y = cam->near / cam->top;//1 / (tan(cam->fov / 2));
	cam->pspct_ratio_z1 = cam->far / (cam->far - cam->near);//farnear[0] / (farnear[0] - farnear[1]);
	cam->pspct_ratio_z2 = -cam->near * cam->pspct_ratio_z1;
	arr = cam->__base_arr;
	arr[0] = cam->pspct_ratio_x;
	arr[5] = cam->pspct_ratio_y;
	arr[10] = cam->pspct_ratio_z1;
	arr[11] = 1;
	arr[14] = cam->pspct_ratio_z2;
//	arr[0] = 1 / (cam->aspect_ratio * tan(cam->fov / 2));//cam->pspct_ratio_x;
//	arr[5] = 1 / (tan(cam->fov / 2));//cam->pspct_ratio_y;
//	arr[10] = cam->far / (cam->far - cam->near);//cam->pspct_ratio_z1;
//	arr[11] = 1;
//	arr[14] = -(cam->far * cam->near) / (cam->far - cam->near);//cam->pspct_ratio_z2;

	printf("init perspective : post init data : fov, aspect ratio, (far, near), (top, bottom), (left, right) : %f, %f, (%f, %f), (%f, %f), (%f, %f)\n", 
		cam->fov, cam->aspect_ratio,cam->far, cam->near, cam->top, cam->bottom, cam->left, cam->right);
	if (update_transform)
		camo_update_transform(cam);
}

static void	camo_update_position(t_camo *cam, int update_transform)
{
	float	*rot;
	float	*p;
	float	pos[3];
	
	rot = (float *)cam->rot->arr;
	p = (float *)cam->__pos_arr;
	pos[0] = p[0] - cam->__off_arr[0];
	pos[1] = p[1] - cam->__off_arr[1];
	pos[2] = p[2] - cam->__off_arr[2];
	rot[12] = pos[0] * rot[0] + pos[1] * rot[4] + pos[2] * rot[8];
	rot[13] = pos[0] * rot[1] + pos[1] * rot[5] + pos[2] * rot[9];
	rot[14] = pos[0] * rot[2] + pos[1] * rot[6] + pos[2] * rot[10];
//	printf("camo update pos : pos updated, updating transform ?\n");
	if (update_transform)
		camo_update_transform(cam);
}

// Holds the rotation transformation data. Call this function anytime
// the orientation changes in any direction.
static void	camo_update_rotation(t_camo *cam, int update_transform)
{
	__mtx_rotation_matrix_YXZ(-cam->thetas[0], -cam->thetas[1], -cam->thetas[2], cam->rot->arr);
	camo_update_position(cam, update_transform);

///	quat_reset(cam->rot);
//	quat_add(cam->rot, -cam->thetas[0], -cam->thetas[1], -cam->thetas[2]);
///	_quat_translation_set(cam->rot,
//		-cam->__pos_arr[0] * cam->ortho_ratio_x,
//		-cam->__pos_arr[1] * cam->ortho_ratio_y,
///		-cam->__pos_arr[2] * cam->ortho_ratio_z);
///	_quat_translation_set(cam->rot, -cam->__pos_arr[0], cam->__pos_arr[1], cam->__pos_arr[2]);
//	if (update_transform)
//		camo_update_transform(cam);
}

int	camo_update(t_camo *cam)
{
	if (!cam)
		return (-1);
	if (cam->cam_type == CAM_ORTHO)
		camo_init_ortho_projection(cam, 0);
	else
		camo_init_perspective_projection(cam, 0);
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
	cam->pos = cam->__mtx_pool;
	cam->offset = cam->__mtx_pool + 1;//cam->__qpool;
	cam->rot = cam->__mtx_pool + 2;//cam->__qpool;
	cam->base_projection = cam->__mtx_pool + 3;
	cam->transform = cam->__mtx_pool + 4;
	printf("camo init : checked 3, cam->rot : %p\n", cam->rot);
	
	cam->pos->arr = cam->__pos_arr;
	cam->offset->arr = cam->__off_arr;
	cam->rot->arr = cam->__rot_arr;
	cam->base_projection->arr = cam->__base_arr;
	cam->transform->arr = cam->__transform_arr;
	printf("camo init : checked 4\n");
	
	mtx_shell(cam->pos, 3, 1, DTYPE_F);
	mtx_shell(cam->offset, 3, 1, DTYPE_F);
	mtx_shell(cam->rot, 4, 4, DTYPE_F);
	mtx_shell(cam->base_projection, 4, 4, DTYPE_F);
	mtx_shell(cam->transform, 4, 4, DTYPE_F);
	printf("camo init : checked 5\n");
//	mtx_transpose(cam->pos);
//	quat_create_empty(cam->rot);
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
	cam->aspect_ratio = ASPECT_RATIO;
	cam->fov = VERT_FOV;
	if (cam_type == CAM_ORTHO)
	{
		if (!dims)
			return (-1);
		cam->dimentions[0] = dims[0];
		cam->dimentions[1] = dims[1];
//		camo_init_ortho_projection(cam, 0);
		cam->cam_type = CAM_ORTHO;
	}
	else if (cam_type == CAM_PERSPECTIVE)
	{
		if (!farnear)
			return (-1);
		cam->far = farnear[0];
		cam->near = farnear[1];
//		camo_init_perspective_projection(cam, 0);
		cam->cam_type = CAM_PERSPECTIVE;
	}

	printf("camo init : ortho ratios x y z : %f, %f, %f\n", cam->ortho_ratio_x, cam->ortho_ratio_y, cam->ortho_ratio_z);
	printf("camo init : init pos and thetas setup\n");
	printf("camo init : before cam update\n");
	camo_update(cam);

	printf("camo init : after cam update\n");
	printf("cam init : base projection :\n");
	mtx_print(cam->base_projection);
	printf("cam init : init rotation mtx : \n");
	mtx_print(cam->rot);
	printf("cam init : init transform mtx : \n");
	mtx_print(cam->transform);
//	printf("cam init : rotation quaternion info :\n");
//	quat_display_info(cam->rot);
	printf("camo init : after cam update\n");

	return (0);
}

void	camo_move_absolute(t_camo *cam, float dx, float dy, float dz)
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
//	camo_update_rotation(cam, 1);
	camo_update_position(cam, 1);
}

void	camo_move(t_camo *cam, float dx, float dy, float dz)
{
	float	*rot;

	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	rot = (float *)cam->rot->arr;
//	rvect[0] = dx * rot[0] + dy * rot[1] + dz * rot[2];
//	rvect[1] = dx * rot[4] + dy * rot[5] + dz * rot[6];
//	rvect[2] = dx * rot[8] + dy * rot[9] + dz * rot[10];
	cam->__pos_arr[0] += dx * rot[0] + dy * rot[1] + dz * rot[2];
	cam->__pos_arr[1] += dx * rot[4] + dy * rot[5] + dz * rot[6];
	cam->__pos_arr[2] += dx * rot[8] + dy * rot[9] + dz * rot[10];
//	cam->__pos_arr[0] += rvect[0];
//	cam->__pos_arr[1] += rvect[1];
//	cam->__pos_arr[2] += rvect[2];

//	printf("cam move raw : (%f, %f, %f)\n", dx, dy, dz);
//	printf("cam move transformed : (%f, %f, %f)\n", rvect[0], rvect[1], rvect[2]);
//	printf("new cam position : (%f, %f, %f)\n", cam->__pos_arr[0], cam->__pos_arr[1], cam->__pos_arr[2]);
//	mtx_print(cam->rot);
//	camo_update_rotation(cam, 1);
	camo_update_position(cam, 1);
}

void	camo_rotate_absolute(t_camo *cam, float rll, float ptc, float yaw)
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

void	camo_rotate(t_camo *cam, float rll, float ptc, float yaw)
{
	float	r[16];
	float	cosx;
	float	*curr;
	float	*out;
//	t_mtx	DELETE_ME;

//	DELETE_ME.arr = r;
//	mtx_shell(&DELETE_ME, 4, 4, DTYPE_F);
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	if (!(rll || ptc || yaw))
		return ;

//	printf("cam rotation : curr rot mtx : \n");
//	mtx_print(cam->rot);

	__mtx_rotation_matrix_YXZ(-rll, -ptc, -yaw, r);
//	printf("cam rotation : delta rot mtx : \n");
//	mtx_print(&DELETE_ME);
	
	out = cam->__rot_arr + (cam->__rot_arr2 - cam->__rot_arr) * (cam->rot->arr == cam->__rot_arr);
	curr = cam->__rot_arr2 + (cam->__rot_arr - cam->__rot_arr2) * (cam->rot->arr == cam->__rot_arr);
	
//	printf("cam rotation : rot->arr %p, curr %p, out %p\n", cam->rot->arr, curr, out);
	__mtx_dotf_4x4_4x4(curr, r, out);

//	printf("cam rotate : requested rotation : (%f, %f, %f) \n", rll, ptc, yaw);
//	printf("cam rotate : old thetas : (%f, %f, %f) \n", cam->thetas[0], cam->thetas[1], cam->thetas[2]);
	cam->rot->arr = out;
	cam->thetas[0] = -asin(out[6]);
	cosx = cos(cam->thetas[0]);
	cam->thetas[2] += asin(out[4] / cosx);
	cam->thetas[1] += asin(out[2] / cosx);
//	printf("cam rotate : new thetas : (%f, %f, %f) \n", cam->thetas[0], cam->thetas[1], cam->thetas[2]);
///	printf("cam rotation : new rot mtx : \n");
//	mtx_print(cam->rot);
	camo_update_position(cam, 1);
//	camo_update_rotation(cam, 1);
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
	camo_update_position(cam, 1);
//	camo_update_rotation(cam, 1);
//	camo_update_base_projection(cam, 1);
}

void	camo_set_offset(t_camo *cam, float x, float y, float z)
{
	if (!cam)
	{
		ft_eprintf("fdf cam : missing input\n");
		return ;
	}
	cam->__off_arr[0] = x;
	cam->__off_arr[1] = y;
	cam->__off_arr[2] = z;
	camo_update_position(cam, 1);
//	camo_update_rotation(cam, 1);
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
	if (cam->cam_type == CAM_ORTHO)
	{
		cam->dimentions[0] *= factor;
		cam->dimentions[1] *= factor;
		camo_init_ortho_projection(cam, 1);
	}
	else
	{
		cam->fov = fmod(cam->fov * factor, 2 * M_PI);
		camo_init_perspective_projection(cam, 1);
	}
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

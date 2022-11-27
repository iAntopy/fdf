/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:31:54 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/27 05:54:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_viewport_init_transform(t_viewp *vp)
{
	float	*tr;

	tr = vp->__t_arr;
	tr[0] = vp->ratio_x;
	tr[5] = vp->ratio_y;
	tr[10] = 1;
	tr[12] = vp->mid[0];
	tr[13] = vp->mid[1];
	tr[15] = 1;
}

int	viewport_init(t_viewp *vp, const int pos[2], const int size[2])
{
	if (!vp || !pos || !size)
		return (-1);
	ft_memclear(vp, sizeof(t_viewp));
	vp->offset[0] = pos[0];
	vp->offset[1] = pos[1];
	vp->mid[0] = pos[0] + (size[0] / 2);
	vp->mid[1] = pos[1] + (size[1] / 2);
	vp->size[0] = size[0];
	vp->size[1] = size[1];
	vp->w = size[0];
	vp->h = size[1];
	vp->limit[0] = pos[0] + size[0];
	vp->limit[1] = pos[1] + size[1];
	vp->ratio_x = vp->w / 2;
	vp->ratio_y = vp->h / 2;
	vp->transform = &vp->__transform;
	vp->transform->arr = vp->__t_arr;
	mtx_shell(vp->transform, 4, 4, DTYPE_F);
	_viewport_init_transform(vp);
	printf("viewport init : transform after init :\n");
	mtx_print(vp->transform);
	return (0);
}

int	viewport_apply_all_transforms(t_fmap *model, t_camo *cam, t_viewp *vp, t_mtx *scoords)
{
	float	model_cam_tf[4][4];
	float	final_tf[4][4];
	t_mtx	DELETE_ME;
	
	DELETE_ME.arr = (float *)model_cam_tf;
	mtx_shell(&DELETE_ME, 4, 4, DTYPE_F);

	if (!model || !cam || !vp || !scoords)
		return (-1);
	
//	printf("viewp apply all : model to cam matrix before dot:\n");
//	mtx_print(&DELETE_ME);
	__mtx_dotf_4x4_4x4((float *)model->transform->arr, (float *)cam->transform->arr, (float *)model_cam_tf);
//	printf("viewp apply all : model to cam matrix after dot:\n");
//	mtx_print(&DELETE_ME);

	__mtx_dotf_4x4_4x4((float *)model_cam_tf, (float *)vp->transform->arr, (float *)final_tf);
//	DELETE_ME.arr = (float *)final_tf;
//	printf("viewp apply all : tf2 cam to viewport matrix :\n");
//	mtx_print(&DELETE_ME);

//	printf("viewp apply all : first row before final tf apply : [%f, %f, %f, %f]\n", ((float *)scoords->arr)[0], ((float *)scoords->arr)[1], ((float *)scoords->arr)[2], ((float *)scoords->arr)[3]);
	__mtx_dotf_nx4_4x4(model->w * model->h, (float *)model->coords->arr, (float *)final_tf, (float *)scoords->arr);
//	printf("viewp apply all : first row after final tf apply : [%f, %f, %f, %f]\n", ((float *)scoords->arr)[0], ((float *)scoords->arr)[1], ((float *)scoords->arr)[2], ((float *)scoords->arr)[3]);

/*
	printf("viewp apply all : model transform %p, arr %p :\n", model->transform, model->transform->arr);
	mtx_print(model->transform);
	printf("viewp apply all : cam base %p :\n", cam->base_projection);
	mtx_print(cam->base_projection);
	printf("viewp apply all : cam rot %p :\n", cam->rot);
	quat_display_info(cam->rot);
	printf("viewp apply all : viewport transform %p :\n", vp->transform);
	mtx_print(vp->transform);

	printf("viewp apply all : model cam transform :\n");
	mtx_print(&DELETE_ME);
	DELETE_ME.arr = (float *)final_tf;
	printf("viewp apply all : cam viewport transform :\n");
	mtx_print(&DELETE_ME);
*/
	return (0);
}
/*
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

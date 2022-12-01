/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_handlers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:08:15 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/30 17:53:36 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mouse_cam_rotate(t_fdf *fdf, int dx, int dy)
{
	static const float	redux = 0.005;
//	printf("mouse cam rotate : dx, dy = (%d, %d)\n", dx, dy);
//	printf("mouse cam rotate : y theta (dx / (asp * fov)), x theta (dy / fov) = (%f, %f)\n", (float)dx / (fdf->cam1.aspect_ratio * fdf->cam1.fov), (float)dy / fdf->cam1.fov);

	camo_rotate(&fdf->cam1, -redux * (float)dy / fdf->cam1.fov,
		redux * (float)dx / (fdf->cam1.aspect_ratio * fdf->cam1.fov), 0);
}

int	on_mouse_press(int button, int x, int y, void *fdf_p)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_p;
	if (fdf->is_cam_ctrl_active && button == 1)
	{
		fdf->last_mouse_coord[0] = x;
		fdf->last_mouse_coord[1] = y;
		fdf->is_mouse_pressed = 1;
	}
	return (0);
}

int	on_mouse_release(int button, int x, int y, void *fdf_p)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_p;
	if (fdf->is_cam_ctrl_active && button == 1)
	{
		mouse_cam_rotate(fdf, x - fdf->last_mouse_coord[0], y - fdf->last_mouse_coord[1]);
		fdf->is_mouse_pressed = 0;
	}
	return (0);
}

int	on_mouse_drag(int x, int y, void *fdf_p)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)fdf_p;
	if (fdf->is_cam_ctrl_active && fdf->is_mouse_pressed)
	{
		mouse_cam_rotate(fdf, x - fdf->last_mouse_coord[0], y - fdf->last_mouse_coord[1]);
		fdf->last_mouse_coord[0] = x;
		fdf->last_mouse_coord[1] = y;
	}
	return (0);
}

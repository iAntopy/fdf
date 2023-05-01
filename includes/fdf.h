/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 05:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/12/01 17:15:13 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define XK_MISCELLANY
# define XK_LATIN1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# include "mlx.h"
# include "mlxadds.h"
# include "keycodes.h"
# include "mtxlib.h"

# define FDF_ERROR(err) fdf_err((char *)__FUNCTION__, (char *)(err))
# define FDF_ERR_CLR_LST(err, l) fdf_e_clr_str_list((char *)__FUNCTION__, \
		(char *)(err), (t_lst *)(l))

# define SCN_WIDTH 1980
# define SCN_HEIGHT 1080
# define SCN_MID_X (SCN_WIDTH / 2)
# define SCN_MID_Y (SCN_HEIGHT / 2)
# define ASPECT_RATIO ((float)SCN_WIDTH / (float)SCN_HEIGHT) 
# define VERT_FOV (M_PI / 3)

# define WIN_TITLE "Fil de Fer"
# define ISO_Y_THETA 0.785398163397f
//# define ISO_X_THETA 0.785398163397
# define ISO_X_THETA 0.61547970867f

//# define BG_COL 0x31176e
# define BG_COL 0x0b1c5e
# define BG_COL2 0x322f2a

typedef struct	s_fdf_map
{
	int	w;
	int	h;
	t_mtx	*coords;
	t_mtx	*screen_coords;
	t_mtx	*homogenious_vect;	//view of last column of screen_coords

	t_mtx	*transform;
	t_mtx	*scaling_tf;
	t_quat	*rotation_tf;
	float	pos[3];
	float	scalars[3];
	float	thetas[3];
//	t_quat	*y_transform;
//	t_quat	*x_transform;
	t_mtx	__final_tf;
	t_mtx	__scaling_tf;
	t_quat	__rotation_tf;
	t_mtx	__homogenious_vect;

	float	__tf_arr[16];
	float	__sc_arr[16];
}	t_fmap;

typedef struct	s_fdf_camera
{
	float	dimentions[2];
	float	thetas[3];
	t_mtx	*pos;		// world position
	t_mtx	*offset;	// offset from center
	t_mtx	*transform;
	t_mtx	*rot;
	t_mtx	*base_projection;
	char	cam_type;
	float	fov;
	float	aspect_ratio;
	float	far;
	float	near;
	float	top;
	float	bottom;
	float	left;
	float	right;
	t_mtx	__mtx_pool[5];
	float	__pos_arr[4];
	float	__off_arr[4];
	float	__base_arr[16];
	float	__rot_arr[16];
	float	__rot_arr2[16];
	float	__transform_arr[16];
	float	ortho_ratio_x;
	float	ortho_ratio_y;
	float	ortho_ratio_z;
	float	pspct_ratio_x;
	float	pspct_ratio_y;
	float	pspct_ratio_z1;
	float	pspct_ratio_z2;
}	t_camo;

typedef struct	s_viewport
{
	t_mlx	*mlx;
	t_mtx	*transform;
	int		w;
	int		h;
	int		offset[2];
	int		mid[2];
	int		size[2];
	int		limit[2];
	float		ratio_x;
	float		ratio_y;
	t_mtx		__transform;
	float		__t_arr[16];
}	t_viewp;

typedef struct	s_fdf_data
{
	t_mlx		mlx;
	t_fmap		map;
	t_fmap		beacon;
	t_fmap		frame;
	t_camo		cam1;
	t_camo		cam2;
	t_camo		cam3;
	t_camo		cam4;
	t_viewp		vp1;
	t_viewp		vp2;
	t_viewp		vp3;
	t_viewp		vp4;
	int			bg_col;
	char		is_animation_active;
	char		is_cam_ctrl_active;

	char		is_mouse_pressed;
	int		last_mouse_coord[2];
}	t_fdf;

enum	e_cam_types
{
	CAM_ORTHO,
	CAM_PERSPECTIVE
};

// FDF INIT
int	fdf_load_map(char *map_name, t_fmap *map);
void	mlx_draw_line_z_shift(t_mlx *mlx, int start[3], int end[3]);

// FDF SWITCHS
int	fdf_modelmode_key_switch(int key, void *fdf_p);
int	fdf_cammode_key_switch(int key, void *fdf_p);

// FMAP TRANSFORM UTILS
int	fmap_init(t_fmap *map, int width, int height);
int	fmap_update(t_fmap *map);
void	fmap_rotate(t_fmap *map, float rx, float ry, float rz);
void	fmap_set_rotation(t_fmap *map, float rx, float ry, float rz);
void	fmap_move(t_fmap *map, float dx, float dy, float dz);
void	fmap_set_position(t_fmap *map, float x, float y, float z);
void	fmap_scale(t_fmap *map, float sx, float sy, float sz);
void	fmap_set_scale(t_fmap *map, float sx, float sy, float sz);

// CAMERA CONTROLS
int		camo_init(t_camo *cam, const float *init_pos, const float *dims,
				const float farnear[2], const float *init_thetas, int cam_type);
int		camo_update(t_camo *cam);
void	camo_move(t_camo *cam, float dx, float dy, float dz);
void	camo_set_position(t_camo *cam, float x, float y, float z);
void	camo_set_offset(t_camo *cam, float x, float y, float z);
void	camo_rotate(t_camo *cam, float rll, float ptc, float yaw);
void	camo_translate(t_camo *cam, float dx, float dy, float dz);
void	camo_set_rotation(t_camo *cam, float rll, float ptc, float yaw);
void	camo_zoom(t_camo *cam, float factor);
void	camo_look_at(t_camo *cam, t_mtx *pos);
void	camo_look_at_coord(t_camo *cam, float x, float y, float z);
void	camo_apply_transform(t_camo *cam, t_fmap *model, t_mtx *b, t_mtx *s);

// VIEWPORT UTILS
int	viewport_init(t_viewp *vp, const int pos[2], const int size[2]);
int	viewport_apply_all_transforms(t_fmap *model, t_camo *cam, t_viewp *vp, t_mtx *scoords);

// MOUSE EVETS
int	on_mouse_press(int button, int x, int y, void *fdf_p);
int	on_mouse_release(int button, int x, int y, void *fdf_p);
int	on_mouse_drag(int x, int y, void *fdf_p);

// ERROR HANDLING

void	*fdf_err(char *ori, char *err);
void	*fdf_e_clr_str_list(char *ori, char *err, t_lst *lst);
void	clear_str_tab(char **tab);

#endif


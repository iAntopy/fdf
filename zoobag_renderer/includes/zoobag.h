/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoobag.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:51 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/16 20:51:13 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOBAG_H
# define ZOOBAG_H

# include "mlx.h"
# include "mlxadds.h"
# include "mtxlib.h"

# define MAX_ZOBJS 1000
# define MAX_REG_COORDS 10000

# define ZB_ERROR(err) zb_err((char *)__FUNCTION__, (char *)(err))
# define ZB_ERR_CLR_ZOBJ(err, z) zb_e_clr_zobj((char *)__FUNCTION__, (char *)(err), (z))

// Physical object to be rendered on screen
typedef struct s_zoobag_obj
{
	t_mtx	*ncoords;	// Normalized coords around origin by mean coords. Scale is kept as original. MALLOCED. NO SWAP. COPY OF ORIGINAL. ORIGINAL NOT FREED. Should only be changed by rot_toffset if desired. Transform these coords into wcoords (world coords)
	t_mtx	*wcoords;	// World coordinates after transforms (rot_offset, scale, rotation and translation). MALLOCED. PRE MALLOC SWAP.
	t_mtx	*scoords;	// Screen coordinates. Final step before draw. This is set by camera transforms to represent where this obj should be relative to the camera. MALLOCED. PRE MALLOC SWAP.
	t_mtx	*draw_coords; // Sliced view matrix of (x, y) elements of scoords. Use this with idx matrix to determine which lines to draw on screen. NOT MALLOCED. Init with __draw_coords_view as t_mtx and set draw_coords as &(__draw_coords_view).
	t_mtx	*indices;	// matrix nx2 of indicies (int) representing which coordinates to draw lines between. eg.: if indices[2][0:2] = (6, 10), then draw third line (indices mtx at row index 2) between scoords at index 6 and index 10. MALLOCED. NO SWAP. COPY OF ORIGINAL. ORIGINAL NOT FREED.

	t_mtx	*scl_roff;	// Scaling and rotational offset transform matrix 4x4. NOT MALLOCED. Is an identity mtx mutilplied by [sx, sy, sz, 1] values for stretching zobj along axis. roff if the last row of this identity matrix where index 0 is the x value of pre rotation translation. index 1 = y offset, 2 = z offset. This is optional but allows for rotation around a given point in space.

	t_quat	*rot_tsl;	// Combined quaternion rotation to be applied to ncoords. NOT MALLOCED. Init with __quat_shell as mem space. Set rotation mamber as &(__quat_shell). Includes the post-rotation translation to world space. Use the [_]quat_translation_[move, set]() series of function to either set the translation transform or add delta 4x1 vector to it.
//	t_mtx	*rot_toffset; // Optional rotational translation offset, or pre rotation translation which allows for rotation around a point in space. NOT MALLOCED. NOT SWAP. By seperating the obj from the origin, the rotation (rot) will be offset and the rotation will happen around a point in space.

	t_mtx	*combined_transform;	// combined matrix of all transformations to be done to this object. This is the final matrix to apply to transform ncoords -> wcoords. NOT MALLOCED. It is a read-only array from the user side. It is the output to the transform pipeline.

	t_mtx	*translation;	// Only a copy of rot_tsl->translation. IS VIEW. Can be indexed to change translation.

	// Direct access variables. Pointers to the data in transform matrices.
	float	*scale_x;
	float	*scale_y;
	float	*scale_z;
	float	*roff_x;
	float	*roff_y;
	float	*roff_z;
	float	*tslt_x;
	float	*tslt_y;
	float	*tslt_z;

//	Inplace memory elements used to reduce heap allocation calls. 
	t_mtx	__draw_coords_view;
	t_quat	__rot_tsl_shell;
	t_quat	__rot_tsl_shell;

	t_mtx	__scl_roff_mtx;
	float	__scl_roff_arr[16];
	t_mtx	__combined_mtx;
	float	__combined_arr[16];
}	t_zobj;





typedef struct s_zoobag_core
{
	t_mlx	mlx;	// minilibx core data. Contains context/win ptrs.
	
//	world_objects array.
	int		lowest_free_zobj;	// index of lowest possible free obj ptr in array. Not garanteed free!
	int		zobj_count;
	t_zobj	*zobj_arr[MAX_ZOBJS]; //ZOBJs can be created and freed. Segmentation possible. All free space = NULL.

	void	*swap_ptr;	// generic ptr variable usable as temp ptr in swaps.
//	zoobag generic utils
	const t_mtx	eye;	// 4x4 identity matrix. MUST NOT CHANGE. Only used.
	t_quat		qr1;	// | 3 quaternion registers to be used as need for
	t_quat		qr2;	// | intermidiate calculations. There memory space is
	t_quat		qr3;	// | contained in t_zoo and do not need freeing.
	t_quat		qr4;	// |

	
	t_mtx	mtx_reg;	// | used as registrer space for internal calculations. Initialized with __farr_reg_coords
	t_mtx	vr1;		// | as array. vr? (view register) should be sliced views of mtx_reg initialized on stack.
	t_mtx	vr2;		// | View registers MUST NOT be overlapping.
	t_mtx	vr3;		// |
	t_mtx	vr4;		// |

	float	__farr_eye[4][4]; // used to init eye.
	float	__farr_mtx_reg[MAX_REG_COORDS][4]; // used as reg space for internal calculations.

}	t_zb;


// ERROR HANDLING
void	*zb_err(char *ori, char *err);

#endif

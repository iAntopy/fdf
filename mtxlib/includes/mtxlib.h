/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:32:39 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:49:49 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTXLIB_H
# define MTXLIB_H

# define MAX_DIMS 2

# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include <stdio.h>

# include "libft.h"
//# include "mtx_mem_utils.h"

# define SHAPE_STR(r, c) ({(c > 0) ? ("<"#r" x "#c">"):("<"#r" x 1>");})
# define MTX_ERROR(err) mtx_err((char *)__FUNCTION__, (char *)(err))
# define MTX_ERR_CLR(e, m) mtx_e_clr((char *)__FUNCTION__, (char *)(e), (m))
# define UNUSED(x) (void)(x)

# include "mtx_types.h"
# include "mtx_core.h"
# include "mtx_ufuncs.h"
# include "mtx_trig.h"
# include "mtx_arithmetic.h"	//AUTO_GENERATED
# include "mtx_cumul_ufuncs.h"	//AUTO GENERATED
# include "mtx_linalg.h"

#endif
/*
enum	mtx_data_types
{
	DTYPE_I = 0,
	DTYPE_F = 1
};

enum	mtx_axis_IDs
{
	WHOLE = -1,
	ROWWISE = 0,
	COLWISE = 1
};

typedef unsigned char U_CHAR;
typedef unsigned int U_INT;

typedef struct s_mtx_base
{
	int		ndims;
	int		dtype;
	int		shape[MAX_DIMS];
	int		strides[MAX_DIMS];
	void	*arr;
	void	*swap;
	void	**view_ptr;
	int		is_view;
	size_t	offset;
	int		is_transposed;
}	t_mtx;

typedef struct s_math_opp
{
	void	*a;	// mtx a offset arr ptr;
	void	*b;	// mtx b offset arr ptr;
	void	*o;	// mtx out offset arr ptr;
	int	*as;	// mtx a strides
	int	*bs;	// mtx b strides
	int	*os;	// mtx b strides
	int	r;	// mtx a nb of rows
	int	c;	// mtx b nb of cols
	void	*av;	// mtx a value ptr
	void	*bv;	// mtx b value ptr
	void	*ov;	// mtx out value ptr
	void (*opp)();	// math opp to execute
}	t_mopp;

typedef struct s_quaternion_base
{
	float	uv[4];
	float	q[4];
	float	rot_mtx[4][4];
}	t_quat;

typedef void (*UFUNC_SIDED)(t_mtx *, t_mtx *);
typedef void (*MOPP_FUNC)(t_mtx *, t_mtx *, t_mtx *);

// CREATE MTX FUNCTIONS
t_mtx	*mtx_create_empty(int rows, int cols, int dtype);
t_mtx	*mtx_create_zeros(int rows, int cols, int dtype);
t_mtx	*mtx_create_array(void *arr, int rows, int cols, int dtype);
t_mtx	*mtx_identity(int n, t_mtx *out, int dtype);
t_mtx	*mtx_arange(int a, int b, int dtype);
t_mtx	*mtx_linspace(float start, float end, int n_divs, int w_end);

// MEMORY MANAGEMENT
void	*mtx_clear(t_mtx **mtx);
void	*mtx_clear_list(int n, ...);
int	malloc_free_p(size_t size, void **ptr);
void	*malloc_free(size_t size, void **ptr);
size_t	mtx_get_dsize(int dtype);
size_t	mtx_sizeof_array(t_mtx *mtx);
void	*mtx_malloc_swap(t_mtx *mtx);

// INDEXING FUNCTIONS
void	*mtx_index(t_mtx *mtx, int row, int col);
//void	*_mtx_idx(t_mtx *mtx, int row, int col);
void	*_mtx_arr(t_mtx *mtx);
void	*_mtx_idx(void *arr, int *strides, int row, int col);
int	mtx_index_is_inbound(t_mtx *mtx, int row, int col);

// PRINT FUNCS
void	mtx_print(t_mtx *mtx);
void	mtx_print_f(t_mtx *mtx);
void	mtx_print_i(t_mtx *mtx);
void	mtx_display_info(t_mtx *mtx);

// VALIDATOR FUNCS
int	mtx_isvalid_broadcast_dot(t_mtx *m1, t_mtx *m2);
void	*mtx_isvalid_broadcast_to_dot(t_mtx *m1, t_mtx *m2, t_mtx *out);
int	mtx_isvalid_sided_ufunc(t_mtx *mtx, int axis, t_mtx *out, char *fname);
int	mtx_dtype_out(t_mtx *m1, t_mtx *m2);
int	mtx_are_same_shape(t_mtx *a, t_mtx *b);
int	mtx_istransposed(t_mtx *mtx);
*/
/*
// GENERIC UTILS
void	*mtxu_sum(t_mtx *mtx, void *out);
t_mtx	*mtx_sum_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	__mtxu_sum_i(int *arr, size_t n_elems);
int 	_mtxu_sum_i(t_mtx *mtx);
float 	__mtxu_sum_f(float *arr, size_t n_elems);
float 	_mtxu_sum_f(t_mtx *mtx);
void	_mtx_sum_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_sum_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_sum_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_sum_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtxu_prod(t_mtx *mtx, void *out);
t_mtx	*mtx_prod_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	__mtxu_prod_i(int *arr, size_t n_elems);
int 	_mtxu_prod_i(t_mtx *mtx);
float 	__mtxu_prod_f(float *arr, size_t n_elems);
float 	_mtxu_prod_f(t_mtx *mtx);
void	_mtx_prod_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_prod_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_prod_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_prod_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtxu_mean(t_mtx *mtx, void *out);
t_mtx	*mtx_mean_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	__mtxu_mean_i(int *arr, size_t n_elems);
int 	_mtxu_mean_i(t_mtx *mtx);
float 	__mtxu_mean_f(float *arr, size_t n_elems);
float 	_mtxu_mean_f(t_mtx *mtx);
void	_mtx_mean_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_mean_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_mean_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_mean_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtxu_max(t_mtx *mtx);
t_mtx	*mtx_max_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	*__mtxu_max_i(int *arr, size_t n_elems);
int 	*_mtxu_max_i(t_mtx *mtx);
float 	*__mtxu_max_f(float *arr, size_t n_elems);
float 	*_mtxu_max_f(t_mtx *mtx);
void	_mtx_max_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_max_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_max_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_max_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtxu_min(t_mtx *mtx);
t_mtx	*mtx_min_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	*__mtxu_min_i(int *arr, size_t n_elems);
int 	*_mtxu_min_i(t_mtx *mtx);
float 	*__mtxu_min_f(float *arr, size_t n_elems);
float 	*_mtxu_min_f(t_mtx *mtx);
void	_mtx_min_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_min_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_min_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_min_by_col_f(t_mtx *mtx, t_mtx *out);
*/
/*
void	mtx_fill(t_mtx *mtx, void *value);
void	mtx_convert_arr_type(t_mtx *new, t_mtx *old);
int		mtx_dtype_out(t_mtx *m1, t_mtx *m2);

t_mtx	*mtx_dup_struct(t_mtx *mtx, t_mtx **out);
t_mtx	*mtx_dup_empty(t_mtx *mtx, t_mtx **out, int dtype);
t_mtx	*mtx_copy(t_mtx *mtx, int dtype);

t_mtx	*mtx_slice_view(t_mtx *mtx, const int slice[4]);
t_mtx	*mtx_view(t_mtx *mtx, t_mtx	*out);
t_mtx	*mtx_select_row(t_mtx *mtx, int row);
t_mtx	*mtx_select_col(t_mtx *mtx, int col);
*/
/*
/////// ARITHMETIC OPS
//	STD_OPPS
void	__mtx_init_math_opp(t_mopp *mo, t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_execute_mopp(t_mopp *mo);
void	__mtx_std_mtx(t_mopp *mo);
void	__mtx_std_scalar(t_mopp *mo);
void	__mtx_std_line_row(t_mopp *mo);
void	__mtx_std_line_col(t_mopp *mo);
void	_mtx_opp_scalar(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)());
void	_mtx_opp_line_row(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)());
void	_mtx_opp_line_col(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)());
void	_mtx_opp_mtx(t_mtx *a, t_mtx *b, t_mtx *out, void (*opp)());
void	__mtx_std_addi(int *v1, int *v2, int *out);
void	__mtx_std_subi(int *v1, int *v2, int *out);
void	__mtx_std_muli(int *v1, int *v2, int *out);
void	__mtx_std_divi(int *v1, int *v2, int *out);
void	__mtx_std_addf(float *v1, float *v2, float *out);
void	__mtx_std_subf(float *v1, float *v2, float *out);
void	__mtx_std_mulf(float *v1, float *v2, float *out);
void	__mtx_std_divf(float *v1, float *v2, float *out);
void	__mtx_std_rsubi(int *v1, int *v2, int *out);
void	__mtx_std_rdivi(int *v1, int *v2, int *out);
void	__mtx_std_rsubf(float *v1, float *v2, float *out);
void	__mtx_std_rdivf(float *v1, float *v2, float *out);


//	NEW ADD OPPS
void	_mtx_addi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_addf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_raddi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riaddi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_addf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_iaddf_pscalar(t_mtx *a, float b);
void	_mtx_addi_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_iaddi_pscalar(t_mtx *a, int b);
void	_mtx_addf_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_addf_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_addi_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_addi_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_addi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_mtx(t_mtx *a, t_mtx *b);
void	_mtx_addf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_mtx(t_mtx *a, t_mtx *b);


//	NEW SUB OPPS
void	_mtx_subi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_subf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rsubi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_subf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_isubf_pscalar(t_mtx *a, float b);
void	_mtx_subi_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_isubi_pscalar(t_mtx *a, int b);
void	_mtx_rsubf_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_risubf_pscalar(float a, t_mtx *b);
void	_mtx_rsubi_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_pscalar(int a, t_mtx *b);
void	_mtx_subf_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubf_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_subf_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubf_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_rsubf_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubf_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_rsubf_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubf_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_subi_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_subi_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_rsubi_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_rsubi_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_subi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_mtx(t_mtx *a, t_mtx *b);
void	_mtx_subf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubf_mtx(t_mtx *a, t_mtx *b);

//	NEW MUL OPPS
void	_mtx_muli_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_scalar(t_mtx *a, t_mtx *b);
void	_mtx_mulf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imulf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rmuli_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rimuli_scalar(t_mtx *a, t_mtx *b);
void	_mtx_mulf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_imulf_pscalar(t_mtx *a, float b);
void	_mtx_muli_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_imuli_pscalar(t_mtx *a, int b);
void	_mtx_mulf_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imulf_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_mulf_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imulf_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_muli_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_muli_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_muli_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_mtx(t_mtx *a, t_mtx *b);
void	_mtx_mulf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imulf_mtx(t_mtx *a, t_mtx *b);

//	NEW DIV OPPS
void	_mtx_divi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_divf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rdivi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_divf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_idivf_pscalar(t_mtx *a, float b);
void	_mtx_divi_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_idivi_pscalar(t_mtx *a, int b);
void	_mtx_rdivf_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_ridivf_pscalar(float a, t_mtx *b);
void	_mtx_rdivi_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_pscalar(int a, t_mtx *b);
void	_mtx_divf_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivf_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_divf_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivf_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_rdivf_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivf_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_rdivf_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivf_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_divi_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_divi_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_rdivi_line_rowwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_line_rowwise(t_mtx *a, t_mtx *b);
void	_mtx_rdivi_line_colwise(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_line_colwise(t_mtx *a, t_mtx *b);
void	_mtx_divi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_mtx(t_mtx *a, t_mtx *b);
void	_mtx_divf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivf_mtx(t_mtx *a, t_mtx *b);
*/
/*
//	ADD OPS
void	_mtx_addf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_addf_line_rowwise(t_mtx *a, t_mtx*b, t_mtx *out);
void	_mtx_addf_line_rowwise(t_mtx *a, t_mtx*b);
void	_mtx_addf_line_colwise(t_mtx *a, t_mtx*b, t_mtx *out);
void	_mtx_addf_line_colwise(t_mtx *a, t_mtx*b);
void	_mtx_addf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_mtx(t_mtx *a, t_mtx *b);
void	_mtx_addi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_scalar(t_mtx *a, t_mtx * sc);
void	_mtx_addi_line_rowwise(t_mtx *a, t_mtx*b, t_mtx *out);
void	_mtx_faddi_line_rowwise(t_mtx *a, t_mtx*b);
void	_mtx_addi_line_colwise(t_mtx *a, t_mtx*b, t_mtx *out);
void	_mtx_faddi_line_colwise(t_mtx *a, t_mtx*b);
void	_mtx_addi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_mtx(t_mtx *a, t_mtx *b);

//	SUB OPS
void	_mtx_subf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_isubf_scalar(t_mtx *mtx, float sc);
void	_mtx_subf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_isubf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_subf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_isubf_mtx(t_mtx *m1, t_mtx *m2);
void	_mtx_rsubf_scalar(float sc, t_mtx *mtx, t_mtx *out);
void	_mtx_risubf_scalar(float sc, t_mtx *mtx);
void	_mtx_rsubf_line(t_mtx *line, t_mtx *mtx, t_mtx *out);
void	_mtx_risubf_line(t_mtx *line, t_mtx *mtx);
void	_mtx_subi_scalar(t_mtx *mtx, int sc, t_mtx *out);
void	_mtx_isubi_scalar(t_mtx *mtx, int sc);
void	_mtx_subi_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_isubi_line(t_mtx *mtx, t_mtx *line);
void	_mtx_subi_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_isubi_mtx(t_mtx *m1, t_mtx *m2);
void	_mtx_rsubi_scalar(int sc, t_mtx *mtx, t_mtx *out);
void	_mtx_risubi_scalar(int sc, t_mtx *mtx);
void	_mtx_rsubi_line(t_mtx *line, t_mtx *mtx, t_mtx *out);
void	_mtx_risubi_line(t_mtx *line, t_mtx *mtx);

//	MUL OPS
void	_mtx_mulf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_imulf_scalar(t_mtx *mtx, float sc);
void	_mtx_mulf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_imulf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_mulf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_imulf_mtx(t_mtx *m1, t_mtx *m2);
void	__mtx_imulf_mtx(float *m1, float *m2, size_t n_elem);
void	__mtx_mulf_mtx(float *m1, float *m2, float *out, size_t n_elem);
void	_mtx_muli_scalar(t_mtx *mtx, int sc, t_mtx *out);
void	_mtx_imuli_scalar(t_mtx *mtx, int sc);
void	_mtx_muli_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_imuli_line(t_mtx *mtx, t_mtx *line);
void	_mtx_muli_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_imuli_mtx(t_mtx *m1, t_mtx *m2);

//	DIV OPS
void	_mtx_divf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_idivf_scalar(t_mtx *mtx, float sc);
void	_mtx_divf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_idivf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_divf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_idivf_mtx(t_mtx *m1, t_mtx *m2);
void	_mtx_rdivf_scalar(float sc, t_mtx *mtx, t_mtx *out);
void	_mtx_ridivf_scalar(float sc, t_mtx *mtx);
void	_mtx_rdivf_line(t_mtx *line, t_mtx *mtx, t_mtx *out);
void	_mtx_ridivf_line(t_mtx *line, t_mtx *mtx);
void	_mtx_divi_scalar(t_mtx *mtx, int sc, t_mtx *out);
void	_mtx_idivi_scalar(t_mtx *mtx, int sc);
void	_mtx_divi_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_idivi_line(t_mtx *mtx, t_mtx *line);
void	_mtx_divi_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_idivi_mtx(t_mtx *m1, t_mtx *m2);
void	_mtx_rdivi_scalar(int sc, t_mtx *mtx, t_mtx *out);
void	_mtx_ridivi_scalar(int sc, t_mtx *mtx);
void	_mtx_rdivi_line(t_mtx *line, t_mtx *mtx, t_mtx *out);
void	_mtx_ridivi_line(t_mtx *line, t_mtx *mtx);
*/
/*
t_mtx	*mtx_sqrt(t_mtx *mtx, int inplace, t_mtx *out);
void	__mtx_isqrtf(float *arr, size_t n_elem);
void	__mtx_sqrtf(float *arr, float *out, size_t n_elem);
void	_mtx_isqrtf(t_mtx *mtx);
void	_mtx_sqrtf(t_mtx *mtx, t_mtx *out);

t_mtx	*mtx_hypot(t_mtx *mtx, t_mtx *out);
void	__mtx_hypot(float *arr, int r, int c, float *out);
void	__mtx_hypot_nx2(float *arr, int r, float *out);
void	__mtx_hypot_nx3(float *arr, int r, float *out);
void	__mtx_hypot_nx4(float *arr, int r, float *out);
*/

/*
// TRIG OPS
t_mtx	*mtx_trig(t_mtx *mtx, float (*func)(float));
t_mtx	*mtx_get_rotmat_4x4(float rll, float pch, float yaw, t_mtx *out);
t_mtx	*mtx_get_rotmat_3x3(float rll, float pch, float yaw, t_mtx *out);
t_mtx	*mtx_get_rotmat_2x2(float ang, t_mtx *out);
void	__mtx_rotation_matrix_4x4(float rll, float pch, float yaw, float *out);
void	__mtx_rotation_matrix_3x3(float rll, float pch, float yaw, float *out);
void	__mtx_rotation_matrix_2x2(float ang, float *out);
*/
/*
// LINALG OPS
t_mtx	*mtx_dot(t_mtx *m1, t_mtx *m2, t_mtx **out);
int	mtx_doti_1D(t_mtx *m1, t_mtx *m2);
int	mtx_dotf_1D(t_mtx *m1, t_mtx *m2);
void	__mtx_dotf_4x4_4x4(float *a, float *b, float *out);
void	__mtx_dotf_nx4_4x4(int n, float *a, float *b, float *out);
void	__mtx_dotf_3x3_3x3(float *a, float *b, float *out);
void	__mtx_dotf_nx3_3x3(int n, float *a, float *b, float *out);
// 171 functions by june 18 2022

//int	__mtx_dot_22o22(int *a1, int *a2, int *out);
//int	__mtx_dot_n2o22(int *a1, int *a2, int n, int *out);

#endif
*/

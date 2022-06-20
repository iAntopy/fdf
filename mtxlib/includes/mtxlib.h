/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:32:39 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/19 01:51:18 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTXLIB_H
# define MTXLIB_H

# define MAX_DIMS 2

# include <math.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

# include "libft.h"
//# include "mtx_mem_utils.h"

# define SHAPE_STR(r, c) ({(c > 0) ? ("<"#r" x "#c">"):("<"#r" x 1>");})


enum	mtx_data_types
{
	DTYPE_I = 1,
	DTYPE_F = 2
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
	void		*arr;
	void		*swap;
	int		is_view;
}	t_mtx;

typedef struct s_quaternion_base
{
	float	uv[4];
	float	q[4];
	float	rot_mtx[4][4];
}	t_quat;

typedef void (*UFUNC_SIDED)(t_mtx *, t_mtx *);

t_mtx	*mtx_create_empty(int rows, int cols, int dtype);
t_mtx	*mtx_create_zeros(int rows, int cols, int dtype);
t_mtx	*mtx_create_array(void *arr, int rows, int cols, int dtype);
t_mtx	*mtx_identity(int n, int dtype);
t_mtx	*mtx_arange(int a, int b, int dtype);
t_mtx	*mtx_linspace(float start, float end, int n_divs, int w_end);

// MEMORY MANAGEMENT
void	*mtx_clear(t_mtx **mtx);
void	*mtx_clear_list(int n, ...);
int		malloc_free_p(size_t size, void **ptr);
void	*malloc_free(size_t size, void **ptr);
size_t	get_dsize(int dtype);
size_t	mtx_sizeof_array(t_mtx *mtx);

// INDEXING FUNCTIONS
void	*mtx_index(t_mtx *mtx, int row, int col);
void	*_mtx_idx(t_mtx *mtx, int row, int col);
int		mtx_index_is_inbound(t_mtx *mtx, int row, int col);

// PRINT FUNCS
void	mtx_print(t_mtx *mtx);
void	mtx_print_f(t_mtx *mtx);
void	mtx_print_i(t_mtx *mtx);
void	mtx_display_info(t_mtx *mtx);

// VALIDATOR FUNCS
int		mtx_isvalid_broadcast_dot(t_mtx *m1, t_mtx *m2);
int		mtx_isvalid_broadcast_to_dot(t_mtx *m1, t_mtx *m2, t_mtx *out);
int		mtx_isvalid_sided_ufunc(t_mtx *mtx, int axis, t_mtx *out, char *fname);
int		mtx_dtype_out(t_mtx *m1, t_mtx *m2);

// GENERIC UTILS
int		mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols);
t_mtx	*mtx_transpose(t_mtx *mtx);

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


/////// ARITHMETIC OPS
//	ADD OPS
void	_mtx_addf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_iaddf_scalar(t_mtx *mtx, float sc);
void	_mtx_addf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_iaddf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_addf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_iaddf_mtx(t_mtx *m1, t_mtx *m2);
void	_mtx_addi_scalar(t_mtx *mtx, int sc, t_mtx *out);
void	_mtx_iaddi_scalar(t_mtx *mtx, int sc);
void	_mtx_addi_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_iaddi_line(t_mtx *mtx, t_mtx *line);
void	_mtx_addi_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_iaddi_mtx(t_mtx *m1, t_mtx *m2);

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


// TRIG OPS
t_mtx	*mtx_trig(t_mtx *mtx, float (*func)(float));

// LINALG OPS
t_mtx	*mtx_dot(t_mtx *m1, t_mtx *m2, t_mtx **out);
int		mtx_doti_1D(t_mtx *m1, t_mtx *m2);
int		mtx_dotf_1D(t_mtx *m1, t_mtx *m2);
void	_mtx_dotf_4x4_4x4(float *a, float *b, float *out);
void	_mtx_dotf_nx4_4x4(int n, float *a, float *b, float *out);
// 171 functions by june 18 2022

//int	__mtx_dot_22o22(int *a1, int *a2, int *out);
//int	__mtx_dot_n2o22(int *a1, int *a2, int n, int *out);

#endif

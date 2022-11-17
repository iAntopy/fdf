/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:18:46 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:39:50 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX_CORE_H
# define MTX_CORE_H

# include "mtx_types.h"

// LIMITS
# ifndef SIZE_MAX
#  define SIZE_MAX 0xffffffffffffffffULL
# endif

// CREATE MTX FUNCTIONS
t_mtx	*mtx_create_empty(int rows, int cols, int dtype);
t_mtx	*mtx_create_zeros(int rows, int cols, int dtype);
t_mtx	*mtx_create_array(void *arr, int rows, int cols, int dtype);
t_mtx	*mtx_create_scalar(void *s, int dtype);
t_mtx	*mtx_shell(t_mtx *mtx, int rows, int cols, int dtype);
t_mtx	*mtx_identity(int n, t_mtx *out, int dtype);
t_mtx	*mtx_arange(int a, int b, int dtype);
t_mtx	*mtx_linspace(float start, float end, int n_divs, int w_end);
t_mtx	*mtx_random(int rows, int cols, t_mtx *out);
t_mtx	*mtx_randint(int rows, int cols, int range[2], t_mtx *out);
void	__mtx_setup_1d(t_mtx *mtx, int rows, int cols, size_t stride);
void	__mtx_setup_2d(t_mtx *mtx, int rows, int cols, size_t stride);

// MEMORY MANAGEMENT
void	*mtx_clear(t_mtx **mtx);
void	*mtx_clear_list(int n, ...);
//int		mtx_malloc_free_p(size_t size, void **ptr);
//void	*mtx_malloc_free(size_t size, void **ptr);
size_t	mtx_get_dsize(int dtype);
size_t	mtx_get_nb_elems(t_mtx *mtx);
size_t	mtx_sizeof_array(t_mtx *mtx);
void	*mtx_malloc_swap(t_mtx *mtx);
int		mtx_swap_arrays(t_mtx *mtx);
void	_mtx_swap_arrays(t_mtx *mtx);
t_mtx	*__mtx_copy_view_swap_to_array_4bytes(t_mtx *view);

// INDEXING FUNCTIONS
void	*mtx_index(t_mtx *mtx, int row, int col);
//void	*_mtx_idx(t_mtx *mtx, int row, int col);
void	*_mtx_arr(t_mtx *mtx);
void	*_mtx_idx(void *arr, int *strides, int row, int col);
int		mtx_index_is_inbound(t_mtx *mtx, int row, int col);

// PRINT FUNCS
void	mtx_print(t_mtx *mtx);
void	mtx_print_f(t_mtx *mtx);
void	mtx_print_i(t_mtx *mtx);
void	mtx_print_mopp(t_mopp *mo);
void	mtx_print_mopp_i(t_mopp *mo);
void	mtx_print_mopp_f(t_mopp *mo);
void	mtx_display_info(t_mtx *mtx);

// VALIDATOR FUNCS
int		mtx_isvalid_broadcast_dot(t_mtx *m1, t_mtx *m2);
void	*mtx_isvalid_broadcast_to_dot(t_mtx *m1, t_mtx *m2, t_mtx *out);
//int		mtx_isvalid_sided_ufunc(t_mtx *mtx, int axis, t_mtx *out, char *fname);
int		mtx_dtype_out(t_mtx *m1, t_mtx *m2);
int		mtx_are_same_type(t_mtx *a, t_mtx *b, t_mtx *out);
int		mtx_are_same_shape(t_mtx *a, t_mtx *b);
int		mtx_isvalid_dtype(int dtype);
int		mtx_istransposed(t_mtx *mtx);

// CORE UTILITY
int		mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols);
t_mtx	*mtx_transpose(t_mtx *mtx);
t_mtx	*mtx_reshape(t_mtx *mtx, int rows, int cols);

t_mtx	*mtx_fill(t_mtx *mtx, void *value);
t_mtx	*__mtx_fill_zeros(t_mtx *mtx);
t_mtx	*_mtx_fill_zeros(t_mtx *mtx);
t_mtx	*__mtx_fill_int(t_mtx *mtx, int value); // DOES NOT WORK WITH VIEWS
t_mtx	*__mtx_fill_float(t_mtx *mtx, float value); // DOES NOT WORK WITH VIEWS
t_mtx	*_mtx_fill_int(t_mtx *mtx, int value); // WORKS WITH VIEWS
t_mtx	*_mtx_fill_float(t_mtx *mtx, float value); // WORKS WITH VIEWS
void	mtx_convert_arr_type(t_mtx *new, t_mtx *old);
int		mtx_dtype_out(t_mtx *m1, t_mtx *m2);

t_mtx	*mtx_dup_struct(t_mtx *mtx, t_mtx **out);
t_mtx	*mtx_dup_empty(t_mtx *mtx, t_mtx **out, int dtype);
t_mtx	*mtx_copy(t_mtx *mtx);//, int dtype);

t_mtx	*mtx_slice_view(t_mtx *mtx, int slice[4], t_mtx *out);
t_mtx	*mtx_select_row(t_mtx *mtx, int row, t_mtx *out);
t_mtx	*mtx_select_col(t_mtx *mtx, int col, t_mtx *out);
t_mtx	*mtx_select_row_range(t_mtx *mtx, int start, int end, t_mtx *out);
t_mtx	*mtx_select_col_range(t_mtx *mtx, int start, int end, t_mtx *out);
//t_mtx	*mtx_view(t_mtx *mtx, t_mtx	*out);

void	_mtx_fill_identity_i(t_mtx *arr);
void	_mtx_fill_identity_f(t_mtx *arr);
void	__mtx_fill_identity_i(int n, int *arr);
void	__mtx_fill_identity_f(int n, float *arr);

// ERROR HANDLING
void	*mtx_fperror(const char *msg, ...);
void	*mtx_err(char *origin, char *err);
void	*mtx_e_clr(char *origin, char *err, t_mtx **mtx);

#endif

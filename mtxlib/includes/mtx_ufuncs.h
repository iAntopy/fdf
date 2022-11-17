/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ufuncs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:22:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 19:55:08 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX_UFUNCS_H
# define MTX_UFUNCS_H

# include "mtx_types.h"

t_mtx	*mtx_apply_f(t_mtx *mtx, float (*func)(float), t_mtx *out);
t_mtx	*mtx_apply_i(t_mtx *mtx, int (*func)(int), t_mtx *out);

void	__mtx_isqrtf(float *arr, size_t n_elem);	// Unusable with views
void	__mtx_sqrtf(float *arr, float *out, size_t n_elem);	// Unusable with views
t_mtx	*mtx_sqrtf(t_mtx *mtx, t_mtx *out);

t_mtx	*mtx_normalize(t_mtx *mtx, t_mtx *out);
t_mtx	*mtx_inormalize(t_mtx *mtx);
void	_mtx_norm_apply(t_mtx *mtx, t_mtx *out, float len);
#endif
/*
void	*mtx_sum(t_mtx *mtx, void *out);
t_mtx	*mtx_sum_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	__mtx_sum_i(int *arr, size_t n_elems);
int 	_mtx_sum_i(t_mtx *mtx);
float 	__mtx_sum_f(float *arr, size_t n_elems);
float 	_mtx_sum_f(t_mtx *mtx);
void	_mtx_sum_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_sum_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_sum_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_sum_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtx_prod(t_mtx *mtx, void *out);
t_mtx	*mtx_prod_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	__mtx_prod_i(int *arr, size_t n_elems);
void 	_mtx_prod_i(t_mtx *mtx, t_mtx *out);
float 	__mtx_prod_f(float *arr, size_t n_elems);
void	_mtx_prod_f(t_mtx *mtx, t_mtx *out);
void	_mtx_prod_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_prod_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_prod_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_prod_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtx_mean(t_mtx *mtx, void *out);
t_mtx	*mtx_mean_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	__mtx_mean_i(int *arr, size_t n_elems);
int 	_mtx_mean_i(t_mtx *mtx);
float 	__mtx_mean_f(float *arr, size_t n_elems);
float 	_mtx_mean_f(t_mtx *mtx);
void	_mtx_mean_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_mean_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_mean_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_mean_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtx_max(t_mtx *mtx);
t_mtx	*mtx_max_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	*__mtx_max_i(int *arr, size_t n_elems);
int 	*_mtx_max_i(t_mtx *mtx);
float 	*__mtx_max_f(float *arr, size_t n_elems);
float 	*_mtx_max_f(t_mtx *mtx);
void	_mtx_max_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_max_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_max_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_max_by_col_f(t_mtx *mtx, t_mtx *out);

void	*mtx_min(t_mtx *mtx);
t_mtx	*mtx_min_sided(t_mtx *mtx, int axis, t_mtx *out);
int 	*__mtx_min_i(int *arr, size_t n_elems);
int 	*_mtx_min_i(t_mtx *mtx);
float 	*__mtx_min_f(float *arr, size_t n_elems);
float 	*_mtx_min_f(t_mtx *mtx);
void	_mtx_min_by_row_i(t_mtx *mtx, t_mtx *out);
void	_mtx_min_by_row_f(t_mtx *mtx, t_mtx *out);
void	_mtx_min_by_col_i(t_mtx *mtx, t_mtx *out);
void	_mtx_min_by_col_f(t_mtx *mtx, t_mtx *out);

void	__mtx_isqrtf(float *arr, size_t n_elem);	// Unusable with views
void	__mtx_sqrtf(float *arr, float *out, size_t n_elem);	// Unusable with views
t_mtx	*mtx_sqrtf(t_mtx *mtx, t_mtx *out);

t_mtx	*mtx_hypot(t_mtx *mtx, t_mtx *out);
void	_mtx_hypot(t_mtx *mtx, t_mtx *out); //Can input/output from/to view
void	__mtx_hypot(float *arr, int r, int c, float *out); // Cannot be view
void	__mtx_hypot_nx2(float *arr, int n, float *out);
void	__mtx_hypot_nx3(float *arr, int n, float *out);
void	__mtx_hypot_nx4(float *arr, int n, float *out);

t_mtx	*mtx_normalize(t_mtx *mtx, t_mtx *out);
t_mtx	*mtx_inormalize(t_mtx *mtx);
void	_mtx_norm_apply(t_mtx *mtx, t_mtx *out, float len);
#endif
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_arithmetic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:13:21 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 18:17:20 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MTX_ARITHMETIC_H
# define MTX_ARITHMETIC_H

# include "mtx_types.h"

void	_mtx_opp_mtx(t_mtx *a, t_mtx *b, t_mtx *c, void (*f)());
void	_mtx_opp_scalar(t_mtx *a, t_mtx *b, t_mtx *c, void (*f)());
void	_mtx_opp_line_row(t_mtx *a, t_mtx *b, t_mtx *c, void (*f)());
void	_mtx_opp_line_col(t_mtx *a, t_mtx *b, t_mtx *c, void (*f)());

void	__mtx_init_math_opp(t_mopp *mo, t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_execute_mopp(t_mopp *mo);
void	__mtx_execute_moppi(t_mopp *mo);
void	__mtx_execute_moppf(t_mopp *mo);
void	__mtx_execute_unary_moppi(t_mopp *mo);
void	__mtx_execute_unary_moppf(t_mopp *mo);
void	__mtx_std_scalar(t_mopp *mo);
void	__mtx_std_mtx(t_mopp *mo);
void	__mtx_std_line_col(t_mopp *mo);
void	__mtx_std_line_row(t_mopp *mo);




//// ADD OPERATIONS
t_mtx	*mtx_add(t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_std_addi(int *v1, int *v2, int *out);
void	__mtx_std_addf(float *v1, float *v2, float *out);
void	__mtx_std_raddf(float *v1, float *v2, float *out);
void	__mtx_std_raddi(int *v1, int *v2, int *out);
void	_mtx_addi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_mtx(t_mtx *a, t_mtx *b);
void	_mtx_addf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_mtx(t_mtx *a, t_mtx *b);
void	_mtx_iaddf_pscalar(t_mtx *a, float b);
void	_mtx_addf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_iaddi_pscalar(t_mtx *a, int b);
void	_mtx_addi_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_iaddf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_addf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_addi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_addf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_addf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_addi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_addi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iaddi_line_c(t_mtx *a, t_mtx *b);
void	_mtx_riaddf_pscalar(float a, t_mtx *b);
void	_mtx_raddf_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_riaddi_pscalar(int a, t_mtx *b);
void	_mtx_raddi_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_riaddf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_raddf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riaddi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_raddi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_raddf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riaddf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_raddf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riaddf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_raddi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riaddi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_raddi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riaddi_line_c(t_mtx *a, t_mtx *b);


//// SUB OPERATIONS
t_mtx	*mtx_sub(t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_std_subi(int *v1, int *v2, int *out);
void	__mtx_std_subf(float *v1, float *v2, float *out);
void	__mtx_std_rsubf(float *v1, float *v2, float *out);
void	__mtx_std_rsubi(int *v1, int *v2, int *out);
void	_mtx_risubf_pscalar(float a, t_mtx *b);
void	_mtx_rsubf_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_pscalar(int a, t_mtx *b);
void	_mtx_rsubi_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_risubf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rsubf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rsubi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rsubf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rsubf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_rsubi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rsubi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_risubi_line_c(t_mtx *a, t_mtx *b);
void	_mtx_subi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_mtx(t_mtx *a, t_mtx *b);
void	_mtx_subf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubf_mtx(t_mtx *a, t_mtx *b);
void	_mtx_isubf_pscalar(t_mtx *a, float b);
void	_mtx_subf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_isubi_pscalar(t_mtx *a, int b);
void	_mtx_subi_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_isubf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_subf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_subi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_subf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_subf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_subi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_subi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_isubi_line_c(t_mtx *a, t_mtx *b);


//// MUL OPERATIONS
t_mtx	*mtx_mul(t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_std_muli(int *v1, int *v2, int *out);
void	__mtx_std_mulf(float *v1, float *v2, float *out);
void	__mtx_std_rmulf(float *v1, float *v2, float *out);
void	__mtx_std_rmuli(int *v1, int *v2, int *out);
void	_mtx_muli_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_mtx(t_mtx *a, t_mtx *b);
void	_mtx_mulf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imulf_mtx(t_mtx *a, t_mtx *b);
void	_mtx_imulf_pscalar(t_mtx *a, float b);
void	_mtx_mulf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_imuli_pscalar(t_mtx *a, int b);
void	_mtx_muli_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_imulf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_mulf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_scalar(t_mtx *a, t_mtx *b);
void	_mtx_muli_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_mulf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imulf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_mulf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imulf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_muli_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_line_r(t_mtx *a, t_mtx *b);
void	_mtx_muli_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_imuli_line_c(t_mtx *a, t_mtx *b);
void	_mtx_rimulf_pscalar(float a, t_mtx *b);
void	_mtx_rmulf_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_rimuli_pscalar(int a, t_mtx *b);
void	_mtx_rmuli_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_rimulf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rmulf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rimuli_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rmuli_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rmulf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rimulf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rmulf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rimulf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_rmuli_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rimuli_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rmuli_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rimuli_line_c(t_mtx *a, t_mtx *b);


//// DIV OPERATIONS
t_mtx	*mtx_div(t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_std_divi(int *v1, int *v2, int *out);
void	__mtx_std_divf(float *v1, float *v2, float *out);
void	__mtx_std_rdivf(float *v1, float *v2, float *out);
void	__mtx_std_rdivi(int *v1, int *v2, int *out);
void	_mtx_divi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_mtx(t_mtx *a, t_mtx *b);
void	_mtx_divf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivf_mtx(t_mtx *a, t_mtx *b);
void	_mtx_idivf_pscalar(t_mtx *a, float b);
void	_mtx_divf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_idivi_pscalar(t_mtx *a, int b);
void	_mtx_divi_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_idivf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_divf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_divi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_divf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_divf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_divi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_divi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_idivi_line_c(t_mtx *a, t_mtx *b);
void	_mtx_ridivf_pscalar(float a, t_mtx *b);
void	_mtx_rdivf_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_pscalar(int a, t_mtx *b);
void	_mtx_rdivi_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_ridivf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rdivf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rdivi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rdivf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rdivf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_rdivi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rdivi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ridivi_line_c(t_mtx *a, t_mtx *b);


//// POW OPERATIONS
t_mtx	*mtx_pow(t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_std_powi(int *v1, int *v2, int *out);
void	__mtx_std_powf(float *v1, float *v2, float *out);
void	__mtx_std_rpowf(float *v1, float *v2, float *out);
void	__mtx_std_rpowi(int *v1, int *v2, int *out);
void	_mtx_powi_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ipowi_mtx(t_mtx *a, t_mtx *b);
void	_mtx_powf_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ipowf_mtx(t_mtx *a, t_mtx *b);
void	_mtx_ipowf_pscalar(t_mtx *a, float b);
void	_mtx_powf_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_ipowi_pscalar(t_mtx *a, int b);
void	_mtx_powi_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_ipowf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_powf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ipowi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_powi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_powf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ipowf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_powf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ipowf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_powi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ipowi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_powi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ipowi_line_c(t_mtx *a, t_mtx *b);
void	_mtx_ripowf_pscalar(float a, t_mtx *b);
void	_mtx_rpowf_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_ripowi_pscalar(int a, t_mtx *b);
void	_mtx_rpowi_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_ripowf_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rpowf_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ripowi_scalar(t_mtx *a, t_mtx *b);
void	_mtx_rpowi_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_rpowf_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ripowf_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rpowf_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ripowf_line_c(t_mtx *a, t_mtx *b);
void	_mtx_rpowi_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ripowi_line_r(t_mtx *a, t_mtx *b);
void	_mtx_rpowi_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ripowi_line_c(t_mtx *a, t_mtx *b);


//// ATAN2 OPERATIONS
t_mtx	*mtx_atan2(t_mtx *a, t_mtx *b, t_mtx *out);
void	__mtx_std_atan2i(int *v1, int *v2, int *out);
void	__mtx_std_atan2f(float *v1, float *v2, float *out);
void	__mtx_std_ratan2f(float *v1, float *v2, float *out);
void	__mtx_std_ratan2i(int *v1, int *v2, int *out);
void	_mtx_atan2i_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iatan2i_mtx(t_mtx *a, t_mtx *b);
void	_mtx_atan2f_mtx(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iatan2f_mtx(t_mtx *a, t_mtx *b);
void	_mtx_iatan2f_pscalar(t_mtx *a, float b);
void	_mtx_atan2f_pscalar(t_mtx *a, float b, t_mtx *out);
void	_mtx_iatan2i_pscalar(t_mtx *a, int b);
void	_mtx_atan2i_pscalar(t_mtx *a, int b, t_mtx *out);
void	_mtx_iatan2f_scalar(t_mtx *a, t_mtx *b);
void	_mtx_atan2f_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iatan2i_scalar(t_mtx *a, t_mtx *b);
void	_mtx_atan2i_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_atan2f_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iatan2f_line_r(t_mtx *a, t_mtx *b);
void	_mtx_atan2f_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iatan2f_line_c(t_mtx *a, t_mtx *b);
void	_mtx_atan2i_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iatan2i_line_r(t_mtx *a, t_mtx *b);
void	_mtx_atan2i_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_iatan2i_line_c(t_mtx *a, t_mtx *b);
void	_mtx_riatan2f_pscalar(float a, t_mtx *b);
void	_mtx_ratan2f_pscalar(float a, t_mtx *b, t_mtx *out);
void	_mtx_riatan2i_pscalar(int a, t_mtx *b);
void	_mtx_ratan2i_pscalar(int a, t_mtx *b, t_mtx *out);
void	_mtx_riatan2f_scalar(t_mtx *a, t_mtx *b);
void	_mtx_ratan2f_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riatan2i_scalar(t_mtx *a, t_mtx *b);
void	_mtx_ratan2i_scalar(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_ratan2f_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riatan2f_line_r(t_mtx *a, t_mtx *b);
void	_mtx_ratan2f_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riatan2f_line_c(t_mtx *a, t_mtx *b);
void	_mtx_ratan2i_line_r(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riatan2i_line_r(t_mtx *a, t_mtx *b);
void	_mtx_ratan2i_line_c(t_mtx *a, t_mtx *b, t_mtx *out);
void	_mtx_riatan2i_line_c(t_mtx *a, t_mtx *b);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_cumul_ufuncs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:13:21 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/04 02:17:02 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MTX_CUMUL_UFUNCS_H
# define MTX_CUMUL_UFUNCS_H

# include "mtx_types.h"

void	__mtx_init_cumul_opp(t_copp *co, t_mtx *mtx, t_mtx *out);
void	_mtx_copp_whole(t_copp *co);
void	_mtx_copp_by_row(t_copp *co);
void	_mtx_copp_by_col(t_copp *co);




//// SUM OPERATIONS
t_mtx	*mtx_sum(t_mtx *mtx, int axis, t_mtx *out);
void	__mtx_sumf_init(float *a, float *out);
void	__mtx_sumf_cumul(float *a, float *out);
void	__mtx_sumf_post(float *out, int n);
void	__mtx_sumi_init(int *a, int *out);
void	__mtx_sumi_cumul(int *a, int *out);
void	__mtx_sumi_post(int *out, int n);
void	_mtx_sumf_row(t_mtx *mtx, t_mtx *out);
void	_mtx_sumf_col(t_mtx *mtx, t_mtx *out);
void	_mtx_sumi_row(t_mtx *mtx, t_mtx *out);
void	_mtx_sumi_col(t_mtx *mtx, t_mtx *out);
void	_mtx_sumf_whole(t_mtx *mtx, t_mtx *out);
void	_mtx_sumi_whole(t_mtx *mtx, t_mtx *out);


//// PROD OPERATIONS
t_mtx	*mtx_prod(t_mtx *mtx, int axis, t_mtx *out);
void	__mtx_prodf_init(float *a, float *out);
void	__mtx_prodf_cumul(float *a, float *out);
void	__mtx_prodf_post(float *out, int n);
void	__mtx_prodi_init(int *a, int *out);
void	__mtx_prodi_cumul(int *a, int *out);
void	__mtx_prodi_post(int *out, int n);
void	_mtx_prodf_row(t_mtx *mtx, t_mtx *out);
void	_mtx_prodf_col(t_mtx *mtx, t_mtx *out);
void	_mtx_prodi_row(t_mtx *mtx, t_mtx *out);
void	_mtx_prodi_col(t_mtx *mtx, t_mtx *out);
void	_mtx_prodf_whole(t_mtx *mtx, t_mtx *out);
void	_mtx_prodi_whole(t_mtx *mtx, t_mtx *out);


//// MIN OPERATIONS
t_mtx	*mtx_min(t_mtx *mtx, int axis, t_mtx *out);
void	__mtx_minf_init(float *a, float *out);
void	__mtx_minf_cumul(float *a, float *out);
void	__mtx_minf_post(float *out, int n);
void	__mtx_mini_init(int *a, int *out);
void	__mtx_mini_cumul(int *a, int *out);
void	__mtx_mini_post(int *out, int n);
void	_mtx_minf_row(t_mtx *mtx, t_mtx *out);
void	_mtx_minf_col(t_mtx *mtx, t_mtx *out);
void	_mtx_mini_row(t_mtx *mtx, t_mtx *out);
void	_mtx_mini_col(t_mtx *mtx, t_mtx *out);
void	_mtx_minf_whole(t_mtx *mtx, t_mtx *out);
void	_mtx_mini_whole(t_mtx *mtx, t_mtx *out);


//// MAX OPERATIONS
t_mtx	*mtx_max(t_mtx *mtx, int axis, t_mtx *out);
void	__mtx_maxf_init(int *a, int *out);
void	__mtx_maxf_cumul(int *a, int *out);
void	__mtx_maxf_post(int *out, int n);
void	__mtx_maxi_init(int *a, int *out);
void	__mtx_maxi_cumul(int *a, int *out);
void	__mtx_maxi_post(int *out, int n);
void	_mtx_maxf_row(t_mtx *mtx, t_mtx *out);
void	_mtx_maxf_col(t_mtx *mtx, t_mtx *out);
void	_mtx_maxi_row(t_mtx *mtx, t_mtx *out);
void	_mtx_maxi_col(t_mtx *mtx, t_mtx *out);
void	_mtx_maxf_whole(t_mtx *mtx, t_mtx *out);
void	_mtx_maxi_whole(t_mtx *mtx, t_mtx *out);


//// MEAN OPERATIONS
t_mtx	*mtx_mean(t_mtx *mtx, int axis, t_mtx *out);
void	__mtx_meani_init(int *a, int *out);
void	__mtx_meani_cumul(int *a, int *out);
void	__mtx_meani_post(int *out, int n);
void	__mtx_meanf_init(float *a, float *out);
void	__mtx_meanf_cumul(float *a, float *out);
void	__mtx_meanf_post(float *out, int n);
void	_mtx_meanf_row(t_mtx *mtx, t_mtx *out);
void	_mtx_meanf_col(t_mtx *mtx, t_mtx *out);
void	_mtx_meani_row(t_mtx *mtx, t_mtx *out);
void	_mtx_meani_col(t_mtx *mtx, t_mtx *out);
void	_mtx_meanf_whole(t_mtx *mtx, t_mtx *out);
void	_mtx_meani_whole(t_mtx *mtx, t_mtx *out);


//// HYPOT OPERATIONS
t_mtx	*mtx_hypot(t_mtx *mtx, int axis, t_mtx *out);
void	__mtx_hypotf_init(float *a, float *out);
void	__mtx_hypotf_cumul(float *a, float *out);
void	__mtx_hypotf_post(float *out, int n);
void	__mtx_hypoti_init(int *a, int *out);
void	__mtx_hypoti_cumul(int *a, int *out);
void	__mtx_hypoti_post(int *out, int n);
void	_mtx_hypotf_row(t_mtx *mtx, t_mtx *out);
void	_mtx_hypotf_col(t_mtx *mtx, t_mtx *out);
void	_mtx_hypoti_row(t_mtx *mtx, t_mtx *out);
void	_mtx_hypoti_col(t_mtx *mtx, t_mtx *out);
void	_mtx_hypotf_whole(t_mtx *mtx, t_mtx *out);
void	_mtx_hypoti_whole(t_mtx *mtx, t_mtx *out);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_linalg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:30:32 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/27 00:35:28 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MTX_LINALG_H
# define	MTX_LINALG_H

# include "mtx_types.h"

// LINALG OPS
t_mtx	*mtx_dot(t_mtx *m1, t_mtx *m2, t_mtx **out);
int	mtx_doti_1D(t_mtx *m1, t_mtx *m2);
int	mtx_dotf_1D(t_mtx *m1, t_mtx *m2);
void	__mtx_dotf_4x4_4x4(float *a, float *b, float *out);
void	__mtx_dotf_nx4_4x4(int n, float *a, float *b, float *out);
void	__mtx_dotf_3x3_3x3(float *a, float *b, float *out);
void	__mtx_dotf_nx3_3x3(int n, float *a, float *b, float *out);

#endif

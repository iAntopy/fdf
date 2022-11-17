/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_atan2_mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:45:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 22:59:51 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_atan2i_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_atan2i);
}

void	_mtx_iatan2i_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_atan2i);
}

void	_mtx_atan2f_mtx(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_mtx(a, b, out, __mtx_std_atan2f);
}

void	_mtx_iatan2f_mtx(t_mtx *a, t_mtx *b)
{
	_mtx_opp_mtx(a, b, a, __mtx_std_atan2f);
}

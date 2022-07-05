/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_trig2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:54:09 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/25 23:33:11 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_atan(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, atanf, out));
}

t_mtx	*mtx_sinh(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, sinhf, out));
}

t_mtx	*mtx_cosh(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, coshf, out));
}

t_mtx	*mtx_tanh(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, tanhf, out));
}

t_mtx	*mtx_asinh(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, asinhf, out));
}

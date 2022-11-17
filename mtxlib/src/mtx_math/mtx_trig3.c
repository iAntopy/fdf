/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_trig3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:57:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/25 23:01:36 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_acosh(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, acoshf, out));
}

t_mtx	*mtx_atanh(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, atanhf, out));
}

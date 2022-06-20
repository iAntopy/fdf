/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sided_ufuncs_validator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 06:32:34 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 07:48:55 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

int	mtx_isvalid_sided_ufunc(t_mtx *mtx, int axis, t_mtx *out, char *fname)
{
	if (!((axis == ROWWISE) || (axis == COLWISE))
		|| !((mtx->dtype == DTYPE_I) || (mtx->dtype == DTYPE_F)))
	{
		fperror("%s : invalid axis/mtx->dtype", fname);
		return (0);
	}
	else if (out && (((axis == ROWWISE) && (out->shape[0] != mtx->shape[1]))
			|| (axis == COLWISE && out->shape[0] != mtx->shape[0])
			|| !(mtx->dtype == out->dtype)))
	{
		fperror("%s : shape or type mismatch in/out", fname);
		return (0);
	}
	return (1);
}

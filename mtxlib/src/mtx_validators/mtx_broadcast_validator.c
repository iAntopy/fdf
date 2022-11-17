/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_broadcast_validator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:53:46 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/01 03:20:22 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	mtx_isvalid_broadcast_dot(t_mtx *m1, t_mtx *m2)
{
	int	shapes_match;
	int	dtype_match;

	shapes_match = m1->shape[m1->ndims - 1] == m2->shape[0];
	dtype_match = (m1->dtype == m2->dtype);
	if (dtype_match && shapes_match)
		return (1);
	else if (!shapes_match)
		fperror("broadcast error : shapes mismatch : (%d vs %d)", SHAPE_STR(m1->shape[0], m1->shape[1]), SHAPE_STR(m2->shape[0], m2->shape[1]));
	else if (!dtype_match)
		fperror("broadcast error : dtype error : (%s vs %s)", (m1->dtype == DTYPE_I)?"INT":"FLOAT", (m2->dtype == DTYPE_I)?"INT":"FLOAT");
	return (0);
}

// If valid returns the array ptr to output the results to. NULL if invalid.
void	*mtx_isvalid_broadcast_to_dot(t_mtx *m1, t_mtx *m2, t_mtx *out)
{
	int	shapes_match;
	int	dtype_match;
	int	output_match;

	shapes_match = m1->shape[m1->ndims - 1] == m2->shape[0];
	dtype_match = (m1->dtype == m2->dtype);
	output_match = (out->shape[0] == m1->shape[0])
	&& (out->shape[1] == m2->shape[1])
		&& (out->dtype == mtx_dtype_out(m1, m2));
	if (dtype_match && shapes_match && output_match)
		return (mtx_malloc_swap(out));
	else if (!shapes_match)
		fperror("broadcast err: shapes : (%d vs %d)", SHAPE_STR(m1->shape[0], m1->shape[1]), SHAPE_STR(m2->shape[0], m2->shape[1]));
	else if (!dtype_match)
		fperror("broadcast err: dtype  : (%s vs %s)", (m1->dtype == DTYPE_I)?"INT":"FLOAT", (m2->dtype == DTYPE_I)?"INT":"FLOAT");
	else if (!output_match)
		fperror("broadcast err: output : (%s vs %s)", (out->dtype == DTYPE_I)?"INT":"FLOAT", (mtx_dtype_out(m1, m2))?"INT":"FLOAT");
	return (NULL);
}

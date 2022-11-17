/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:50:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:40:34 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	*mtx_fperror(const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	ft_vprintf(fmt, &ap);
	perror(" ");
	va_end(ap);
	return (NULL);
}

void	*mtx_err(char *origin, char *err)
{
	fprintf(stderr, RED_BC"[=> MTX ERROR : %s : %s <=]\n"WHITE_C,
		origin, err);
	return (NULL);
}

void	*mtx_e_clr(char *origin, char *err, t_mtx **mtx)
{
	mtx_err(origin, err);
	mtx_clear(mtx);
	return (NULL);
}

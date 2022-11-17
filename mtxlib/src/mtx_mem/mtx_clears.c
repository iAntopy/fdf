/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_clears.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:14:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:41:05 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"
#include <stdarg.h>

void	*mtx_clear(t_mtx **mtx)
{
	if (!(mtx && *mtx))
		return (NULL);
	if (!(*mtx)->is_view && (*mtx)->arr)
		malloc_free_p(0, (void **)&((*mtx)->arr));
	if ((*mtx)->swap)
		malloc_free_p(0, (void **)&((*mtx)->swap));
	malloc_free_p(0, (void **)mtx);
	return (NULL);
}

// Provide list of (t_mtx *) to clear and free
void	*mtx_clear_list(int n, ...)
{
	va_list	args;
	t_mtx	*mtx;
	int	i;

	va_start(args, n);
	i = -1;
	while (++i < n)
	{
		mtx = (t_mtx *)va_arg(args, t_mtx *);
		mtx_clear(&mtx);
	}
	va_end(args);
	return (NULL);
}

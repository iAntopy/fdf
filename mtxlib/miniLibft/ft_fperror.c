/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fperror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:37:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/16 23:37:38 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"
//#include <stdarg.h>
//#include <errno.h>
//#include <stdio.h>
//#include "ft_printf.h"

void	*mtx_fperror(char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	ft_vprintf(fmt, &ap);
	perror(" ");
	va_end(ap);
	return (NULL);
}

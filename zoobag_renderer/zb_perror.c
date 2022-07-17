/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:50:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/15 16:39:31 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoobag.h"

void	*zb_err(char *ori, char *err)
{
	fprintf(stderr, RED_BC"@=> ZOOBAG ERROR : %s : %s <=@\n"WHITE_C, ori, err);
	return (NULL);
}

void	*zb_e_clr_zobj(char *origin, char *err, t_zobj **zobj)
{
	zb_err(origin, err);
	zb_clear_zobj(zobj);
	return (NULL);
}

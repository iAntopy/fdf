/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:18:13 by iamongeo          #+#    #+#             */
/*   Updated: 2023/05/02 12:17:12 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*fdf_err(char *ori, char *err)
{
	fprintf(stderr, RED_BC"@=> FdF ERROR : %s : %s <=@\n"WHITE_C, ori, err);
	return (NULL);
}

void	*fdf_e_clr_str_list(char *origin, char *err, t_lst *lst)
{
	zb_err(origin, err);
	ft_lstclear(lst, free);
	return (NULL);
}

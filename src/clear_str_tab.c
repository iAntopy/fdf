/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_str_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:17:35 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/21 18:19:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	clear_str_tab(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
		free(*(tab++));
}
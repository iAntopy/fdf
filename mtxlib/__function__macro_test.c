/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __function__macro_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 06:40:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/18 06:42:10 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	WOW_INCROYABLE(char ass)
{
	printf("Vous êtes dans la fonction nommer : %s\n", __FUNCTION__);
}

int	main()
{
	WOW_INCROYABLE('a');
	return (0);
}

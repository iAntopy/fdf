/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:05:41 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 17:15:24 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	main()
{	
	t_mtx	*mtx1;
	t_mtx	*mtx2;
	int		randint_range[2] = {0, 100};

	printf("first ft_random_pick : %f\n", ft_random());
	mtx1 = mtx_random(4, 4, NULL);
	mtx2 = mtx_randint(4, 4, randint_range, NULL);

	printf("random mtx : \n");
	mtx_print(mtx1);
	printf("\nrandint mtx : \n");
	mtx_print(mtx2);
	mtx_clear_list(2, mtx1, mtx2);
	return (0);
}

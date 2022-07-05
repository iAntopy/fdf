/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:35:05 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:19:43 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_dup_struct(t_mtx *mtx, t_mtx **out)
{
	t_mtx	*new;

	if (!mtx)
		return (MTX_ERROR("no input mtx"));
	if (!malloc_free_p(sizeof(t_mtx), (void **)&new))
		return (MTX_ERROR("malloc error"));
	ft_memcpy(new, mtx, sizeof(t_mtx));
	new->arr = NULL;
	new->swap = NULL;
	if (out)
		*out = new;
	return (new);
}

t_mtx	*mtx_dup_empty(t_mtx *mtx, t_mtx **out, int dtype)
{
	t_mtx	*new;
	size_t	arr_size;

	if (!mtx || (dtype && mtx_get_dsize(mtx->dtype) != mtx_get_dsize(dtype)))
		return (MTX_ERROR("no mtx or dsize mismatch"));
	if (!mtx_dup_struct(mtx, &new))
		return (MTX_ERROR("malloc error"));
	arr_size = mtx_sizeof_array(mtx);
	printf("dup empty : new->arr before malloc : %p\n", new->arr);
	if (!malloc_free_p(arr_size, (void **)&(new->arr)))
	{
		mtx_clear(&new);
		return (MTX_ERROR("malloc error "));
	}
	printf("dup empty : new->arr after malloc : %p\n", new->arr);
	new->dtype = dtype;
	new->view_ptr = &(new->arr);
	printf("dup empty : new->dtype, new->view_ptr : %d, %p\n", new->dtype, new->view_ptr);
	if (out)
	{
		printf("dup empty : set **out to ret\n");
		*out = new;
	}
	printf("dup empty : returning new\n");
	return (new);
}

t_mtx	*mtx_copy(t_mtx *mtx)//, int dtype)
{
	t_mtx	*new;
	size_t	arr_size;

	if (!mtx)
		return (MTX_ERROR("no intput mtx"));
	if (!mtx_dup_struct(mtx, &new))
		return (MTX_ERROR("malloc error"));
	arr_size = mtx_sizeof_array(mtx);
	if (!malloc_free_p(arr_size, (void **)&(new->arr)))
	{
		mtx_clear(&new);
		return (MTX_ERROR("malloc error"));
	}
	new->dtype = mtx->dtype;
	ft_memcpy(new->arr, mtx->arr, arr_size);
//	else
//	mtx_convert_arr_type(new, mtx);
	return (new);
}

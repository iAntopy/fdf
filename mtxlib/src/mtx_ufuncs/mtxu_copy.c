#include "mtxlib.h"

t_mtx	*mtx_dup_struct(t_mtx *mtx, t_mtx **out)
{
	t_mtx	*new;

	if (!mtx)
		return (fperror("%s : no input mtx ", __FUNCTION__));
	if (!malloc_free_p(sizeof(t_mtx), (void **)&new))
		return (fperror("%s : malloc error ", __FUNCTION__));
	ft_memcpy(new, mtx, sizeof(t_mtx));
	new->arr = NULL;
	new->out = NULL;
	if (out)
		*out = new;
	return (new);
}

t_mtx	*mtx_dup_empty(t_mtx *mtx, t_mtx **out, int dtype)
{
	t_mtx	*new;
	size_t	arr_size;

	if (!mtx || (dtype && get_dsize(mtx->dtype) != get_dsize(dtype)))
		return (fperror("%s : no mtx or dsize mismatch", __FUNCTION__));
	if (!mtx_dup_struct(mtx, &new))
		return (NULL);
	arr_size = mtx_sizeof_array(mtx);
	if (!malloc_free_p(arr_size, (void **)&(new->arr)))
	{
		mtx_clear(&new);
		return (fperror("%s : malloc error "));
	}
	mtx->dtype = dtype;
	if (out)
		*out = new;
	return (new);
}

t_mtx	*mtx_copy(t_mtx *mtx, int dtype)
{
	t_mtx	*new;
	size_t	arr_size;

	if (!mtx || (dtype && get_dsize(mtx->dtype) != get_dsize(dtype)))
		return (fperror("%s : no mtx or dsize mismatch", __FUNCTION__));
	if (!mtx_dup_struct(mtx, &new))
		return (NULL);
	arr_size = mtx_sizeof_array(mtx);
	if (!malloc_free_p(arr_size, (void **)&(new->arr)))
	{
		mtx_clear(&new);
		return (fperror("%s : malloc error ", __FUNCTION__));
	}
	new->dtype = dtype + (!dtype * mtx->dtype);
	if (dtype == mtx->dtype)
		ft_memcpy(new->arr, mtx->arr, arr_size);
	else
		mtx_convert_arr_type(new, mtx);
	return (new);

}

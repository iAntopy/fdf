/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:24:16 by iamongeo          #+#    #+#             */
/*   Updated: 2023/05/01 22:58:56 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_clear_str(t_lst **map)
{
	ft_lstclear(map, free);
	return (0);
}

static int	map_clear_strtab(t_lst **map)
{
	t_lst	*elem;
	t_lst	*elem_next;

	if (!map)
		return (0);
//	printf("map clear strtab : enetered and checked. *map : %p\n", *map);
	elem = *map;
	while (elem)
	{
		elem_next = elem->next;
//		printf("map clear strtab : elem->content : %p, elem->content[0] : %s\n", elem->content, ((char **)(elem->content))[0]);
		strtab_clear((char ***)&elem->content);
		ft_free_p((void **)&elem);
		elem = elem_next;
	}
//	printf("map clear strtab : enetered and checked. *map : %p\n", *map);
	*map = NULL;
	return (0);
}

static t_mtx	*convert_map_lst_to_mtx(t_fmap *fmap, int width, int height, t_lst *map_lst)
{
	int		i;
	int		j;
	t_lst	*row;
	float	*data;

//	printf("map loader convert : entered. <width x height> : <%d x %d>\n", width, height);
	fmap->coords = mtx_create_empty(width * height, 4, DTYPE_F);
//	printf("map loader convert : coords mtx created %p\n", fmap->coords);
	if (!fmap->coords)
		return (NULL);
	row = map_lst;
	j = -1;
	while (row && ++j < height)
	{
//		strtab_print((char **)row->content);
//		printf("row strtab ptr : %p\n", row->content);
		i = -1;
		while (++i < width)
		{
			data = (float *)mtx_index(fmap->coords, j * width + i, 0);
			*data = i;
			*(data + 1) = j;
//			printf("loader : (x, y) = z : (%d, %d) = %d, content[i] : %s\n", i, j, ft_atoi(((char **)row->content)[i]), ((char **)row->content)[i]);
			*(data + 2) = ft_atoi(((char **)row->content)[i]);
			*(data + 3) = 1;
		}
		row = row->next;
	}
	return (fmap->coords);
}

static int	split_validate(t_lst *map_lst)
{
	char	**strtab;
	t_lst	*elem;
	int		width;

//	printf("split validate : entered\n");
	width = 0;
	elem = map_lst;
	while (elem)
	{
		strtab = NULL;
		strtab = ft_split_space((char *)elem->content);
//		strtab_print(strtab);
		if (!strtab)
			return (-1);
		if (!width)
			width = strtab_len(strtab);
		else if (width > 0 && strtab_len(strtab) != width)
			width = -1;
		ft_free_p((void **)&elem->content);
//		printf("split validate : elem->content after ft_free_p : %p\n", elem->content);
		elem->content = (void *)strtab;
//		printf("strtab ptr : %p\n", strtab);
		elem = elem->next;
	}
	return (width);
}

static int	gather_map_lines(int fd, t_lst **map_lst)
{
	t_lst	*elem;
	char	*new_line;
	
//	printf("gather_map_lines starts : fd %d, map_list ptr %p\n", fd, map_lst);
	new_line = get_next_line(fd);
	while (new_line)
	{
//		printf(" - %s", new_line);
		elem = ft_lstnew(new_line);
		if (!elem)
			return (ft_free_p((void **)&new_line) - 1);
		ft_lstadd_back(map_lst, elem);
		new_line = get_next_line(fd);
	}
	return (0);
}

int	fdf_load_map(char *map_name, t_fmap *fmap)
{
	t_lst	*map_lst;
	int		fd;
	int		w;
	int		h;

//	printf("load_map : entered. map_name : %s, fmap ptr : %p\n", map_name, fmap);
	if (!map_name || !fmap)
		return (-1);
//	printf("load_map : checks passed\n");
	map_lst = NULL;
//	printf("opening map_name : %s\n", map_name);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		printf("load_map : file open failed\n");
		return (-1);
	}
//	printf("map loader : gathering map\n");
	if (gather_map_lines(fd, &map_lst) < 0)
		return (map_clear_str(&map_lst) - 1);
	close(fd);
//	printf("map loader : split validate\n");
	w = split_validate(map_lst);
	if (w < 0)
		return (map_clear_strtab(&map_lst) - 1);
	h = ft_lstsize(map_lst);
//	printf("map loader : fmap init. <w x h> : <%d x %d>\n", w, h);
	fmap_init(fmap, w, h);
//	printf("map loader : fmap init DONE\n");
	if (!convert_map_lst_to_mtx(fmap, w, h, map_lst))
		return (map_clear_strtab(&map_lst) - 1);
//	printf("map loader : about to copy coords\n");
	fmap->screen_coords = mtx_copy(fmap->coords);
	mtx_select_col(fmap->screen_coords, 3, fmap->homogenious_vect);
//	printf("map loader : homogenious coords : \n");
//	mtx_print(fmap->homogenious_vect);
	mtx_transpose(fmap->homogenious_vect);
	return (map_clear_strtab(&map_lst));
}
/*
int	main(int argc, char **argv)
{
	t_fmap	fmap;
	t_mtx	last_col;
	t_mtx	*mean;
	t_quat	*q1;
	t_quat	*q2;

	if (argc < 2)
		return (1);
	if (load_map(argv[1], &fmap) < 0)
	{
		ft_eprintf("fdf : load map failed\n");
		return (1);
	}
	mean = mtx_mean(fmap.coords, ROWWISE, NULL);
	mtx_sub(fmap.coords, mean, fmap.coords);
	mtx_clear(&mean);

	printf("fdf : selecting last col\n");
	ft_memclear(&last_col, sizeof(t_mtx));
	mtx_select_col(fmap.coords, 3, &last_col);
	mtx_display_info(&last_col);
	_mtx_iaddf_pscalar(&last_col, 1.0f);
	mtx_print(&last_col);
	mtx_print(fmap.coords);

	q1 = quat_create((float)M_PI / 4, 0, 1, 0);
	q2 = quat_create(atanf(sqrtf(2)), 1, 0, 0);
	quat_combine(q1, q2, q1);
	quat_clear(&q2);
	_quat_translation_set(q1, 100, 100, 0);
	quat_display_info(q1);
	quat_irotate(fmap.coords, q1);
	printf("fdf : print map rotated and translated in one go with combined quaternion\n");
	mtx_print(fmap.coords);

	quat_clear(&q1);
	mtx_clear(&fmap.coords);
	return (0);
}
*/

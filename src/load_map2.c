/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:24:16 by iamongeo          #+#    #+#             */
/*   Updated: 2022/11/17 00:23:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_clear_str(t_lst **map)
{
	ft_lstclear(map, free);
	return (0);
}

int	map_clear_strtab(t_lst **map)
{
	t_lst	*elem;

	if (!map)
		return (0);
	elem = *map;
	while (elem)
	{
		strtab_clear((char ***)&elem->content);
		elem = elem->next;
	}
	ft_free_p((void **)map);
	return (0);
}

static t_mtx	*convert_map_lst_to_mtx(t_fmap *fmap, t_lst *map_lst)
{
	int		i;
	int		j;
	t_lst	*row;
	float	*data;

	fmap->coords = mtx_create_empty(fmap->h * fmap->w, 4, DTYPE_F);
	if (!fmap->coords)
		return (NULL);
	row = map_lst;
	j = -1;
	while (row && ++j < fmap->h)
	{
		i = -1;
		while (++i < fmap->w)
		{
			data = (float *)mtx_index(fmap->coords, j * fmap->w + i, 0);
			*data = i;
			*(data + 1) = j;
			*(data + 2) = ft_atoi(((char **)row->content)[i]);
			*(data + 3) = 1;
		}
		row = map_lst->next;
	}
	return (fmap->coords);
}

static int	split_validate(t_lst *map_lst)
{
	char	**strtab;
	t_lst	*elem;
	int		width;
	int		cur_width;

	printf("split validate : entered\n");
	width = 0;
	elem = map_lst;
	while (elem)
	{
		printf("split validate : loop with elem : %p\n", elem);
		strtab = NULL;
		strtab = ft_split_space((char *)elem->content);
		if (!strtab)
			return (-1);
		printf("split validate : strtab : %p\n", strtab);
		if (!width)
		{
			width = strtab_len(strtab);
			printf("split validate : width : %d \n", width);
		}
		else
		{
			cur_width = strtab_len(strtab);
			printf("split validate : cur_width, width : %d, %d \n", cur_width, width);
			if (cur_width != width)
				return ((int)strtab_clear(&strtab) - 1);
			width = cur_width;
		}
		printf("split validate : if block passed \n");
		ft_free_p((void **)&elem->content);
		elem->content = strtab;
		elem = elem->next;
	}
	return (width);
}

static int	gather_map_lines(int fd, t_lst **map_lst)
{
	t_lst	*elem;
	char	*new_line;

	new_line = get_next_line(fd);
	while (new_line)
	{
		elem = ft_lstnew(new_line);
		if (!elem)
			return (ft_free_p((void **)&new_line) - 1);
		ft_lstadd_back(map_lst, elem);
		new_line = get_next_line(fd);
	}
	return (0);
}

int	load_map(char *map_name, t_fmap *fmap)
{
	t_lst	*map_lst;
	int		width;
	int		fd;

	printf("laod_map : entered. map_name : %s, fmap ptr : %p\n", map_name, fmap);
	if (!map_name || !fmap)
		return (-1);
	printf("laod_map : checks passed\n");
	map_lst = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd < -1)
	{
		printf("load_map : file open failed %d\n", fd);
		return (-1);
	}
	printf("laod_map : file opened\n");
	if (gather_map_lines(fd, &map_lst) < 0)
		return (map_clear_str(&map_lst) - 1);
	printf("laod_map : file read and put in list\n");
	fmap->w = split_validate(map_lst);;
	if (fmap->w < 0)
		return (map_clear_strtab(&map_lst) - 1);
	fmap->h = ft_lstsize(map_lst);
	printf("laod_map : map_list split and validated. (w, h) : (%d, %d)\n", fmap->w, fmap->h);
	if (!convert_map_lst_to_mtx(fmap, map_lst))
		return (map_clear_strtab(&map_lst) - 1);
	printf("laod_map : split map converted to mtx\n");
	return (map_clear_strtab(&map_lst));
}

int	main(int argc, char **argv)
{
	t_fmap	fmap;
	t_mtx	*mean;

	if (argc < 2)
		return (1);
	if (load_map(argv[1], &fmap) < 0)
	{
		ft_eprintf("fdf : load map failed\n");
		return (1);
	}
	mean = mtx_mean(fmap.coords, ROWWISE, NULL);
	mtx_sub(fmap.coords, mean, fmap.coords);

	mtx_print(fmap.coords);
	mtx_clear(&fmap.coords);
	mtx_clear(&mean);
	return (0);
}

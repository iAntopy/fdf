/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:38:46 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/21 19:53:10 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_str_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab && *tab)
		len++;
	return (len);
}

static t_mtx	*fdf_row_splitter(t_lst *rows, int *row_cnt, int *col_cnt)
{
	t_mtx	coords;
	char	**split_row;
	int		i;
	int		j;

	split_row = ft_split_space(rows->content);
	if (!split_row)
		return (NULL);
	*col_count = count_str_tab(tab);
	coords = mtx_create_empty((*row_cnt) * (*col_cnt), 4, DTYPE_F);
	i = -1;
	while (rows && (++i >= 0))
	{
		j = -1;
		while (split_row[++j])
			if (!fdf_parse_single_map_coord(coords, i, j, split_row[j]))
				// manage failed coord parsing
				return (NULL);
		if (j != *col_cnt)
			// manage uneven rows Error.
			return (NULL);
		


		split_row = ft_split_space(rows->content);
		if (!split_row)
			return ("");
		ncols = count_str_tab(split_row);
		rows = rows->next;
	}
}

static t_lst	*fdf_get_lines_table(int fd, int *row_cnt)
{
	t_lst	*row_list;
	t_lst	*last_elem;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (FDF_ERROR("get_next_line failed or empty map file"));
	while (line)
	{
		if (last_elem)
		{
			last_elem->next = ft_lstnew(line);
			last_elem = last_elem->next;
		}
		else
		{
			row_list = ft_lstnew(line);
			last_elem = row_list;
		}
		if (!last_elem)
			return (FDF_ERR_CLR_LST("malloc error", row_list));
		line = get_next_line(fd);
		(*row_cnt)++;
	}
	return (row_list);
}

// file must be opened prior
t_mtx	*fdf_map_loader(int fd)
{
	t_lst	*str_tab;
	t_mtx	*coords;
	int		row_count;
	int		col_count;

	str_tab = fdf_get_lines_table(fd, &row_count);
	if (!str_tab)
		return (FDF_ERROR("failed to load map"));

	coords = fdf_row_splitter(str_tab, &col_count);
	if (!coords)
		return (FDF_ERR_CLR_LST("row splitter failed"));

}

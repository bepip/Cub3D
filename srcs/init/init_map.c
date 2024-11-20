/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:13:09 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/20 17:44:09 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	set_map(t_file *file);
static int	set_map_param(t_file *file);
static int	get_temp_map(t_file *file);

int	init_map(t_file *file)
{
	if (get_temp_map(file))
		return (FAILURE);
	if (set_map_param(file))
		return (FAILURE);
	if (set_map(file))
		return (err_msg(MALLOC_ERROR, NULL), FAILURE);
	return (SUCCESS);
}

//TODO: free when calloc fails
static int	set_map(t_file *file)
{
	int		i;
	int		len;
	char	**map;

	i = -1;
	map = (char **)malloc(sizeof(char *) * (file->height + 1));
	if (!map)
		return (err_msg(MALLOC_ERROR, NULL), FAILURE);
	while (++i < file->height)
	{
		map[i] = ft_calloc(sizeof(char), file->width + 1);
		if (!map[i])
			return (FAILURE);
		ft_memset(map[i], ' ', file->width);
		len = ft_strlen(file->map[i]);
		while (--len >= 0)
			map[i][len] = file->map[i][len];
	}
	map[i] = NULL;
	ft_free_split(file->map);
	file->map = map;
	return (SUCCESS);
}

static int	set_map_param(t_file *file)
{
	int	height;
	int	width;
	int	len;

	height = -1;
	width = 0;
	while (file->map[++height])
	{
		len = ft_strlen(file->map[height]);
		if (width < len)
			width = len;
	}
	if (width < 3 && height < 3)
		return (FAILURE);
	file->height = height;
	file->width = width;
	return (SUCCESS);
}

static int	get_temp_map(t_file *file)
{
	char	**map;
	int		i;
	int		j;
	int		start;

	i = file->map_ind - 1;
	while (file->cp_file[++i])
		if (ft_strlen(file->cp_file[i]) > 1)
			break ;
	start = i;
	while (file->cp_file[i] && ft_strlen(file->cp_file[i]) > 1)
		++i;
	if (start == i)
		return (err_msg(MAPMISSING_ERROR, NULL), FAILURE);
	map = malloc ((i - start + 1) * sizeof(char *));
	if (!map)
		return (err_msg(MAPMISSING_ERROR, NULL), FAILURE);
	j = 0;
	while (file->cp_file[start] && start < i)
		map[j++] = ft_strtrim(file->cp_file[start++], "\n");
	map[j] = NULL;
	if (file->cp_file[start] != NULL)
		return (ft_free_split(map), err_msg(MAP_ERROR, NULL), FAILURE);
	return (file->map = map, SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:55:01 by laichoun          #+#    #+#             */
/*   Updated: 2024/11/19 17:14:15 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>
#include <unistd.h>

static int	get_file_lines(char *file);
int			init_game_data(t_game *gamep, t_file *data);
t_textures	*set_textures(t_file *data);
int		init_map(t_file *file);
int		get_temp_map(t_file *file);
int		is_valid_map(t_file *f);

//TODO: all the magic happens here
int initialize_data(t_game *gamep, char *filename)
{
	(void) gamep;
	t_file	file;

	if (init_file(&file))
		return (FAILURE);
	if (copy_file(filename, &file))
		return (free_file(&file), FAILURE);
	if (set_variable(&file))
		return (free_file(&file), FAILURE);
	if (check_file(&file))
		return (free_file(&file), FAILURE);
	if (init_game_data(gamep, &file))
		return (free_file(&file), FAILURE);
	return (free_file(&file), SUCCESS);
}


//TODO: check if all data are set and correct
//		add err msg
//		check if textures can be accessed
int check_file(t_file *d)
{
	if (!d)
		return (FAILURE);
	if (d->so != 1 || d->no != 1 || d->we != 1 || d->ea != 1 || d->f != 1 || d->c != 1)
		return (FAILURE);
	if (d->tex_so == NULL || d->tex_no == NULL || d->tex_ea == NULL || d->tex_we == NULL)
		return (FAILURE);
	if (d->f_rgb[0] < 0 || d->f_rgb[1] < 0 || d->f_rgb[2] < 0)
		return (FAILURE);
	if (d->c_rgb[0] < 0 || d->c_rgb[1] < 0 || d->c_rgb[2] < 0)
		return (FAILURE);
	if (d->f_rgb[0] > 255 || d->f_rgb[1] > 255 || d->f_rgb[2] > 255)
		return (FAILURE);
	if (d->c_rgb[0] > 255 || d->c_rgb[1] > 255 || d->c_rgb[2] > 255)
		return (FAILURE);
	/*if (is_valid_map(d))
		return (FAILURE);*/
	return (SUCCESS);
}

static void init_dim3_arr(int arr[3], int val)
{
	arr[0] = val;
	arr[1] = val;
	arr[2] = val;
}

int init_file(t_file *data)
{
	if (!data)
		return (FAILURE);
	data->cp_file = NULL;
	data->map = NULL;
	data->player = 0;
	data->so = 0;
	data->no = 0;
	data->ea = 0;
	data->we = 0;
	data->width = 0;
	data->height = 0;
	data->map_ind = 0;
	data->f = 0;
	data->c = 0;
	data->tex_no = NULL;
	data->tex_so = NULL;
	data->tex_ea = NULL;
	data->tex_we = NULL;
	init_dim3_arr(data->f_rgb, 0);
	init_dim3_arr(data->c_rgb, 0);
	return (SUCCESS);
}

int	copy_file(char *file, t_file *data_file)
{
	int		fd;
	int		i;
	int		len;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (err_msg(OPEN_ERROR, file), FAILURE);
	len = get_file_lines(file);
	if (len == -1)
		return (close(fd), FAILURE);
	data_file->cp_file = malloc((len + 1) * sizeof(char *));
	if (data_file->cp_file == NULL)
		return (err_msg(MALLOC_ERROR, NULL), FAILURE);
	while (++i < len)
		data_file->cp_file[i] = get_next_line(fd);
	data_file->cp_file[i] = NULL;
	return (close(fd), SUCCESS);	
}

static int	get_file_lines(char *file)
{
	int		fd;
	char	*line;
	int		length;

	length = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (err_msg(OPEN_ERROR, file), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		++ length;
		free(line);
		line = NULL;
	}
	close(fd);
	return (length);
}

int set_cardinal_points(t_file *data, char **tab)
{
	if (!data || !tab)
		return (ft_fprintf(2, "Error\n"), FAILURE);
	if (!ft_strcmp(tab[0], "NO"))
	{
		++data->no;
		data->tex_no = ft_strdup(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "SO"))
	{
		++data->so;
		data->tex_so = ft_strdup(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "EA"))
	{
		++data->ea;
		data->tex_ea = ft_strdup(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "WE"))
	{
		++data->we;
		data->tex_we = ft_strdup(tab[1]);
	}
	else
		return (ft_fprintf(2, "ERROR: Wrong Cardinals given\n"), FAILURE);
	return (SUCCESS);
}

int set_file_colors(t_file *data, char **tab)
{
	if (!data || !tab)
		return (ft_fprintf(2, "Error\n"), FAILURE);
	if (!ft_strcmp(tab[0], "F"))
	{
		++data->f;
		//TODO:check if is num and in range of 0-255
		data->f_rgb[0] = ft_atoi(tab[0]);
		data->f_rgb[1] = ft_atoi(tab[1]);
		data->f_rgb[2] = ft_atoi(tab[2]);
	}
	else if (!ft_strcmp(tab[0], "C"))
	{
		++data->c;
		//TODO:check if is num and in range of 0-255
		data->c_rgb[0] = ft_atoi(tab[0]);
		data->c_rgb[1] = ft_atoi(tab[1]);
		data->c_rgb[2] = ft_atoi(tab[2]);
	}
	else
		return (ft_fprintf(2, "ERROR: Wrong colors given\n"), FAILURE);
	return (SUCCESS);
}

int	set_variable(t_file *data)
{
	int	i;
    char    **tab;
	int	size;
	int count;

	i = -1;
	count = 0;
	while (data->cp_file[++i])
	{
		tab = ft_strtok(data->cp_file[i], " ,\n");
		if (!tab)
			return (err_msg(MALLOC_ERROR, NULL), FAILURE);
		size = ft_split_size(tab);
		if (size == 0)
		{
			ft_free_split(tab);
			continue;
		}
		if (size != 2 && size != 4)
			return (ft_free_split(tab), err_msg(MISSING_INFO_ERROR, 0), FAILURE);
		if (size == 2)
			if (set_cardinal_points(data, tab))
				return (ft_free_split(tab), FAILURE);
		if (size == 4)
			if (set_file_colors(data, tab))
				return (ft_free_split(tab), FAILURE);
		ft_free_split(tab);
		if (++count == 6)
			break;
	}
	if (count != 6)
		return (err_msg(MISSING_INFO_ERROR, NULL), FAILURE);
	data->map_ind = i + 1;
	init_map(data);
	if (!data->map)
		return (FAILURE);
	return (SUCCESS);
}

//TODO: add colors
int		init_game_data(t_game *gamep, t_file *data)
{
	if (!data)
			return (FAILURE);
	gamep->map = ft_dupsplit(data->map);
	gamep->row = data->width;
	gamep->col = data->height;
	gamep->textures = set_textures(data);
	if (!gamep->textures)
		return (err_msg(MALLOC_ERROR, NULL), FAILURE);
	return (SUCCESS);
}

t_textures	*set_textures(t_file *file)
{
	t_textures	*t;

	t = (t_textures*) malloc(sizeof(t_textures));
	if (!t)
		return (NULL);
	t->tex_we = ft_strdup(file->tex_we);
	t->tex_ea = ft_strdup(file->tex_ea);
	t->tex_no = ft_strdup(file->tex_no);
	t->tex_so = ft_strdup(file->tex_so);
	t->f_rgb[0] = file->f_rgb[0];
	t->f_rgb[1] = file->f_rgb[1];
	t->f_rgb[2] = file->f_rgb[2];
	t->c_rgb[0] = file->c_rgb[0];
	t->c_rgb[1] = file->c_rgb[1];
	t->c_rgb[2] = file->c_rgb[2];
	return (t);
}

int		get_temp_map(t_file *file)
{
	char	**map;
	int		i;
	int		j;
	int		start;

	i = file->map_ind - 1;
	while (file->cp_file[++i])
		if (ft_strlen(file->cp_file[i]) > 1)
			break;
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
		return (ft_free_split(map),err_msg(MAP_ERROR, NULL), FAILURE);
	return (file->map = map, SUCCESS);
}

int	set_map_param(t_file *f)
{
	int	height;
	int width;
	int	len;

	height = -1;
	width = 0;
	while (f->map[++height])
	{
		len = ft_strlen(f->map[height]);
		if (width < len)
			width = len;
	}
	if (width < 3 && height < 3)
		return (FAILURE);
	f->height = height;
	f->width = width;
	return (SUCCESS);
}

//TODO: free when calloc fails
int	set_map(t_file *file)
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
		while (--len)
			map[i][len] = file->map[i][len];
	}
	map[i] = NULL;
	ft_free_split(file->map);
	file->map = map;
	return (SUCCESS);
}

int	init_map(t_file *f)
{
	int		i;

	if (get_temp_map(f))
		return (FAILURE);
	if (set_map_param(f))
		return (FAILURE);
	i = 0;
	if (set_map(f))
		return (err_msg(MALLOC_ERROR, NULL), FAILURE);
	return (SUCCESS);
}

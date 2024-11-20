/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:55:01 by laichoun          #+#    #+#             */
/*   Updated: 2024/11/20 17:47:10 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>
#include <unistd.h>

int			init_game_data(t_game *gamep, t_file *file);
t_textures	*set_textures(t_file *file);

//TODO: all the magic happens here
int	init_game(t_game *gamep, char *filename)
{
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

//TODO:check if is num and in range of 0-255
int	set_file_colors(t_file *file, char **tab)
{
	if (!file || !tab)
		return (ft_fprintf(2, "Error\n"), FAILURE);
	if (!ft_strcmp(tab[0], "F"))
	{
		++file->f;
		file->f_rgb[0] = ft_atoi(tab[0]);
		file->f_rgb[1] = ft_atoi(tab[1]);
		file->f_rgb[2] = ft_atoi(tab[2]);
	}
	else if (!ft_strcmp(tab[0], "C"))
	{
		++file->c;
		file->c_rgb[0] = ft_atoi(tab[0]);
		file->c_rgb[1] = ft_atoi(tab[1]);
		file->c_rgb[2] = ft_atoi(tab[2]);
	}
	else
		return (ft_fprintf(2, "ERROR: Wrong colors given\n"), FAILURE);
	return (SUCCESS);
}

int	set_variable(t_file *file)
{
	int		i;
	char	**tab;
	int		size;
	int		count;

	i = -1;
	count = 0;
	while (file->cp_file[++i])
	{
		tab = ft_strtok(file->cp_file[i], " ,\n");
		if (!tab)
			return (err_msg(MALLOC_ERROR, NULL), FAILURE);
		size = ft_split_size(tab);
		if (size == 0)
		{
			ft_free_split(tab);
			continue ;
		}
		if (size != 2 && size != 4)
			return (ft_free_split(tab), err_msg(MISSING_INFO_ERROR, 0),
				FAILURE);
		if (size == 2)
			if (set_cardinal_points(file, tab))
				return (ft_free_split(tab), FAILURE);
		if (size == 4)
			if (set_file_colors(file, tab))
				return (ft_free_split(tab), FAILURE);
		ft_free_split(tab);
		if (++count == 6)
			break ;
	}
	if (count != 6)
		return (err_msg(MISSING_INFO_ERROR, NULL), FAILURE);
	file->map_ind = i + 1;
	init_map(file);
	if (!file->map)
		return (FAILURE);
	return (SUCCESS);
}

//TODO: add colors
int	init_game_data(t_game *gamep, t_file *file)
{
	if (!file)
		return (FAILURE);
	gamep->map = ft_dupsplit(file->map);
	gamep->row = file->width;
	gamep->col = file->height;
	gamep->textures = set_textures(file);
	if (!gamep->textures)
		return (err_msg(MALLOC_ERROR, NULL), FAILURE);
	return (SUCCESS);
}

t_textures	*set_textures(t_file *file)
{
	t_textures	*t;

	t = (t_textures *)malloc(sizeof(t_textures));
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

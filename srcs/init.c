/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:55:01 by laichoun          #+#    #+#             */
/*   Updated: 2024/11/18 17:50:22 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <unistd.h>

static int	length_file(char *file);

//TODO: all the magic happens here
int initialize_data(t_game *gamep, char *filename)
{
	t_file	file;
	int		err;

	err = init_file(&file);
	if (err)
		return (err);
	err = copy_file(filename, &file);
	if (err)
		return (free_file(&file), err);
	err = set_variable(&file);
	if (err)
		return (free_file(&file), err);
	err = init_game_data(gamep, &file);
	if (err)
		return (free_file(&file), err);
	return (SUCCESS);
}


//TODO: check if all data are set and correct
int check_file(t_file *data)
{
	return (SUCCESS);
}

//TODO: set all params to 0 or NULL
int init_file(t_file *data)
{
	return (SUCCESS);
}
int	copy_file(char *file, t_file *data_file)
{
	int		fd;
	int		i;
	int		len;
	char	*line;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (OPEN_ERROR);
	len = length_file(file);
	if (len == -1)
		return (close(fd), OPEN_ERROR);
	data_file->cp_file = malloc((len + 1) * sizeof(char *));
	if (data_file->cp_file == NULL)
		return (MALLOC_ERROR);
	while (++i < len)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_free_split(data_file->cp_file), MALLOC_ERROR);
		data_file->cp_file[i] = line;
	}
	data_file->cp_file[i] = NULL;
	return (close(fd), SUCCESS);	
}

static int	length_file(char *file)
{
	int		fd;
	char	*line;
	int		length;

	length = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (OPEN_ERROR);
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
	return (SUCCESS);
}

int set_colors(t_file *data, char **tab)
{
	return (SUCCESS);
}

int	set_variable(t_file *data)
{
	int	i;
	int	j;
    char    **tab;
	int	size;
	int count;

	i = -1;
	j = 0;
	count = 0;
	while (data->cp_file[++i])
	{
		tab = ft_strtok(data->cp_file[i], " ,\n");
		if (!tab)
			return (MALLOC_ERROR);
		size = ft_split_size(tab);
		if (size == 0)
		{
			ft_free_split(tab);
			continue;
		}
		if (size != 2 || size != 4)
			return (ft_free_split(tab), MISSING_INFO_ERROR);
		if (size == 2)
			if (set_cardinal_points(data, tab))
				return (ft_free_split(tab), CARDINAL_ERROR);
		if (size == 4)
			if (set_colors(data, tab))
				return (ft_free_split(tab), FLOOR_ERROR);
		ft_free_split(tab);
		if (++count == 6)
			break;
	}
	if (count != 6)
		return (MISSING_INFO_ERROR);
	//TODO: need function to add map to map param of t_file
	return (SUCCESS);
}

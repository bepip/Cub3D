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

int	length_file(char *file);

int	copy_file(char *file, t_file *data_file)
{
	int		fd;
	int		i;
	int		len;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_fprintf(2, "Error\nOpening file\n"), OPEN_ERROR);
	len = length_file(file);
	if (len == -1)
		return (close(fd), OPEN_ERROR);
	data_file->cp_file = malloc((len + 1) * sizeof(char *));
	while (++i < len)
		data_file->cp_file[i] = get_next_line(fd);
	data_file->cp_file[i] = NULL;
	close(fd);
	return (SUCCESS);	
}

int	length_file(char *file)
{
	int		fd;
	char	*line;
	int		length;

	length = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_fprintf(2, "Error\nOpening file\n"), OPEN_ERROR);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		length ++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (length);
}

int set_cardinal_points(t_file *data, char **tab)
{
	return (0);
}

int set_colors(t_file *data, char **tab)
{
	return (0);
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
		size = ft_split_size(tab);
		if (size == 0)
		{
			ft_free_split(tab);
			continue;
		}
		if (size != 2 || size != 4)
			return (ft_free_split(tab), ERROR);
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
	//TODO: need function to add map to map param of t_file
	return (0);
}

//TODO: check if all data are set and correct
int check_file(t_file *data)
{
	return (0);
}

//TODO: set all params to 0 or NULL
int init_file(t_file *data)
{
	return (0);
}

//TODO: all the magic happens here
int initialize_data(t_game *game, char *filename)
{
	t_file data;

	init_file(&data);

	copy_file(filename, &data);
	return (0);
}

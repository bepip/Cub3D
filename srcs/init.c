/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:55:01 by laichoun          #+#    #+#             */
/*   Updated: 2024/11/18 16:07:37 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	length_file(char *file);

char	**copy_file(char *file, t_file *data_file)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_fprintf(2, "Error\nOpening file\n");
		return (NULL);
	}
	data_file->cp_file = malloc((length_file(file) + 1) * sizeof(char *));
	while (1)
	{
		data_file->cp_file[i] = get_next_line(fd);
		if (data_file->cp_file[i] == NULL)
			break;
		i ++;	
	}
	close(fd);
	data_file->cp_file[i] = NULL;
	return (data_file->cp_file);	
}

int	length_file(char *file)
{
	int		fd;
	char	*line;
	int		length;

	length = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_fprintf(2, "Error\nOpening file\n");
		return (-1);
	}
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

int	set_variable(t_file *data_file)
{
	int	i;
	int	j;
    char    **tab;

	i = 0;
	j = 0;
	while (data_file->cp_file[i])
	{
		tab = ft_strtok(data_file->cp_file[i], " ,\n");
        while (tab[j])
        {
            
        }
	}
}



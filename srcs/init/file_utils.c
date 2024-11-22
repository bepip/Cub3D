/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:17:41 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/20 17:43:17 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_file_lines(char *file);
static void	init_dim3_arr(int arr[3], int val);

int	init_file(t_file *file)
{
	if (!file)
		return (ft_fprintf(2, "Error\n"), FAILURE);
	file->cp_file = NULL;
	file->map = NULL;
	file->player = 0;
	file->so = 0;
	file->no = 0;
	file->ea = 0;
	file->we = 0;
	file->width = 0;
	file->height = 0;
	file->map_ind = 0;
	file->f = 0;
	file->c = 0;
	file->tex_no = NULL;
	file->tex_so = NULL;
	file->tex_ea = NULL;
	file->tex_we = NULL;
	init_dim3_arr(file->f_rgb, 0);
	init_dim3_arr(file->c_rgb, 0);
	return (SUCCESS);
}

int	copy_file(char *file, t_file *file_p)
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
	file_p->cp_file = malloc((len + 1) * sizeof(char *));
	if (file_p->cp_file == NULL)
		return (err_msg(MALLOC_ERROR, NULL), FAILURE);
	while (++i < len)
		file_p->cp_file[i] = get_next_line(fd);
	file_p->cp_file[i] = NULL;
	return (close(fd), SUCCESS);
}

static void	init_dim3_arr(int arr[3], int val)
{
	arr[0] = val;
	arr[1] = val;
	arr[2] = val;
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
			break ;
		++length;
		free(line);
		line = NULL;
	}
	close(fd);
	return (length);
}

//if texutres are duplicated we get leaks
int	set_cardinal_points(t_file *file, char **tab)
{
	if (!file || !tab)
		return (ft_fprintf(2, "Error\n"), FAILURE);
	if (!ft_strcmp(tab[0], "NO"))
	{
		++file->no;
		file->tex_no = ft_strdup(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "SO"))
	{
		++file->so;
		file->tex_so = ft_strdup(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "EA"))
	{
		++file->ea;
		file->tex_ea = ft_strdup(tab[1]);
	}
	else if (!ft_strcmp(tab[0], "WE"))
	{
		++file->we;
		file->tex_we = ft_strdup(tab[1]);
	}
	else
		return (ft_fprintf(2, "ERROR: Wrong Cardinals given\n"), FAILURE);
	return (SUCCESS);
}

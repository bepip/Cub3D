/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:27:01 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 11:27:02 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	set_param(char **texture, char *filename, int *count);

int	check_textures(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		err_msg(ERROR_OPEN, str);
		close(fd);
		return (FAILURE);
	}
	if (check_extension(str, "xpm"))
		return (close(fd), FAILURE);
	close(fd);
	return (SUCCESS);
}

int	set_cardinal_points(t_file *file, char **tab)
{
	if (!file || !tab)
		return (err_msg(0, NULL), FAILURE);
	if (!ft_strcmp(tab[0], "NO"))
	{
		if (set_param(&(file->tex_no), tab[1], &(file->no)))
			return (FAILURE);
	}
	else if (!ft_strcmp(tab[0], "SO"))
	{
		if (set_param(&(file->tex_so), tab[1], &(file->so)))
			return (FAILURE);
	}
	else if (!ft_strcmp(tab[0], "EA"))
	{
		if (set_param(&(file->tex_ea), tab[1], &(file->ea)))
			return (FAILURE);
	}
	else if (!ft_strcmp(tab[0], "WE"))
	{
		if (set_param(&(file->tex_we), tab[1], &(file->we)))
			return (FAILURE);
	}
	else
		return (err_msg(ERROR_WRONG_CARDINAL, NULL), FAILURE);
	return (SUCCESS);
}

static int	set_param(char **texture, char *filename, int *count)
{
	if (check_textures(filename))
		return (FAILURE);
	++(*count);
	if (*count != 1)
		return (err_msg(ERROR_CARDINAL_DUP_MISS, NULL), FAILURE);
	*texture = ft_strdup(filename);
	return (SUCCESS);
}

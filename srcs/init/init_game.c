#include "../../includes/cub3d.h"

int		init_game_data(t_game *gamep, t_file *file);
int		check_extension(char *filename, char *ext);
int		set_textures(t_game *game, t_file *file);
void	init_blank_game(t_game *gamp);

int	init_game(t_game *gamep, char *filename)
{
	t_file	file;

	if (check_extension(filename, "cub"))
		return (FAILURE);
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

int	set_file_colors(t_file *file, char **tab)
{
	if (!file || !tab)
		return (ft_fprintf(2, "Error: set_file_colors\n"), FAILURE);
	if (!ft_strcmp(tab[0], "F"))
	{
		if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2]) || !ft_isnumber(tab[3]))
			return (ft_fprintf(2, "Error: Color code is not a number"), FAILURE);
		++file->f;
		file->f_rgb[0] = ft_atoi(tab[1]);
		file->f_rgb[1] = ft_atoi(tab[2]);
		file->f_rgb[2] = ft_atoi(tab[3]);
	}
	else if (!ft_strcmp(tab[0], "C"))
	{
		if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2]) || !ft_isnumber(tab[3]))
			return (ft_fprintf(2, "Error: Color code is not a number\n"), FAILURE);
		++file->c;
		file->c_rgb[0] = ft_atoi(tab[1]);
		file->c_rgb[1] = ft_atoi(tab[2]);
		file->c_rgb[2] = ft_atoi(tab[3]);
	}
	else
		return (ft_fprintf(2, "ERROR: Invalid color identifier.\n"), FAILURE);
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
			return (err_msg(ERROR_MALLOC, NULL), FAILURE);
		size = ft_split_size(tab);
		if (size == 0)
		{
			ft_free_split(tab);
			continue ;
		}
		if (size != 2 && size != 4)
			return (ft_free_split(tab), err_msg(ERROR_MISSING_INFO, 0),
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
		return (err_msg(ERROR_MISSING_INFO, NULL), FAILURE);
	file->map_ind = i + 1;
	if (init_map(file))
		return (FAILURE);
	return (SUCCESS);
}

int	init_game_data(t_game *gamep, t_file *file)
{
	init_blank_game(gamep);
	if (!file)
		return (FAILURE);
	gamep->map = ft_dupsplit(file->map);
	gamep->row = file->width;
	gamep->col = file->height;
	set_textures(gamep, file);
	if (init_mlx(gamep, file))
		return (free_game(gamep), FAILURE);
	return (SUCCESS);
}

int		set_textures(t_game *game, t_file *file)
{
	game->textures.f_rgb[0] = file->f_rgb[0];
	game->textures.f_rgb[1] = file->f_rgb[1];
	game->textures.f_rgb[2] = file->f_rgb[2];
	game->textures.c_rgb[0] = file->c_rgb[0];
	game->textures.c_rgb[1] = file->c_rgb[1];
	game->textures.c_rgb[2] = file->c_rgb[2];
	return (SUCCESS);
}

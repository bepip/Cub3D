
#include "../../includes/cub3d.h"

static int	set_param(char **texture, char *filename, int *count);

int	check_textures(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_fprintf(2, "Error\nOn opening the file : %s\n", str);
		close(fd);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

// if texutres are duplicated we get leaks
int	set_cardinal_points(t_file *file, char **tab)
{
	if (!file || !tab)
		return (ft_fprintf(2, "Error\n"), FAILURE);
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
		return (ft_fprintf(2, "ERROR: Wrong Cardinals given\n"), FAILURE);
	return (SUCCESS);
}

static int	set_param(char **texture, char *filename, int *count)
{
	if (check_textures(filename))
		return (FAILURE);
	++(*count);
	*texture = ft_strdup(filename);
	return (SUCCESS);
}

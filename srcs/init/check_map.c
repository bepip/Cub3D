// 1) check de la première ligne c'est forcément que des 1 avec ou sans les des espaces
// 2) check de la dernière ligne avec ou sans les espaces

#include "../../includes/cub3d.h"

int	is_map_valid(t_file *file);
int	is_valid_row(t_file *file);
int	is_valid_col(t_file *file);
int	check_player(t_file *file);

int	is_map_valid(t_file *file)
{
	if ((is_valid_row(file) == SUCCESS && is_valid_col(file) == SUCCESS
			&& check_player(file) == SUCCESS))
        return (SUCCESS);
    return (FAILURE);
}

int	check_player(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->height)
	{
		j = 0;
		while (j < file->width)
		{
			if (file->map[i][j] == 'N' || file->map[i][j] == 'S'
				|| file->map[i][j] == 'W' || file->map[i][j] == 'E')
				file->player++;
			j++;
		}
		i++;
	}
	if (file->player != 1)
	{
        err_msg(ERROR_PLAYER, NULL);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	is_valid_row(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->height)
	{
		j = 0;
		while (j < file->width)
		{
			while (j < file->width && file->map[i][j] == 32)
				j++;
			if (j < file->width && file->map[i][j] != '1')
                return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			while (j < file->width && file->map[i][j] != 32)
				j++;
			if (file->map[i][j - 1] != '1' && file->map[i][j - 1] != ' ')
                return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	is_valid_col(t_file *file)
{
	int	i;
	int	j;

	j = 1;
	while (j < file->width)
	{
		i = 0;
		while (i < file->height)
		{
			while (i < file->height && file->map[i][j] == 32)
				i++;
			if (i < file->height && file->map[i][j] != '1')
                return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			while (i < file->height && file->map[i][j] != 32)
				i++;
			if (file->map[i - 1][j] != '1' && file->map[i - 1][j] != ' ')
                return (err_msg(ERROR_NOT_SURROUNDED, NULL), FAILURE);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}

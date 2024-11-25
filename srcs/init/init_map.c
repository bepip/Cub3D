#include "../../includes/cub3d.h"

static int	set_map(t_file *file);
static int	set_map_param(t_file *file);
static int	get_temp_map(t_file *file);
static void	free_interrupt(char **tab, int ind);

int	init_map(t_file *file)
{
	if (get_temp_map(file))
		return (FAILURE);
	if (set_map_param(file))
		return (FAILURE);
	if (set_map(file))
		return (FAILURE);
	return (SUCCESS);
}

static int	set_map(t_file *file)
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
			return (free_interrupt(map, i), err_msg(MALLOC_ERROR, 0), FAILURE);
		ft_memset(map[i], ' ', file->width);
		len = ft_strlen(file->map[i]);
		while (--len >= 0)
			map[i][len] = file->map[i][len];
	}
	map[i] = NULL;
	ft_free_split(file->map);
	file->map = map;
	return (SUCCESS);
}

static int	set_map_param(t_file *file)
{
	int	height;
	int	width;
	int	len;

	height = -1;
	width = 0;
	while (file->map[++height])
	{
		len = ft_strlen(file->map[height]);
		if (width < len)
			width = len;
	}
	if (width < 3 || height < 3)
		return (ft_fprintf(2, "Error: Map dimension too small.\n"), FAILURE);
	file->height = height;
	file->width = width;
	return (SUCCESS);
}

int	ft_isempty_line(char *s);
static int	get_temp_map(t_file *file)
{
	char	**map;
	int		i;
	int		j;
	int		start;

	i = file->map_ind;
	skip_newlines(file, &i);
	start = i;
	while (file->cp_file[i] && ft_isempty_line(file->cp_file[i]) == 0)
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
	skip_newlines(file, &start);
	if (file->cp_file[start] != NULL)
		return (ft_free_split(map), err_msg(MAP_ERROR, NULL), FAILURE);
	return (file->map = map, SUCCESS);
}

static void free_interrupt(char **tab, int ind)
{
	while (--ind >= 0)
		free(tab[ind]);
	free(tab);
}

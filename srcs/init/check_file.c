#include "../../includes/cub3d.h"

int	check_file(t_file *f)
{
	if (!f)
		return (FAILURE);
	if (f->so != 1 || f->no != 1 || f->we != 1 || f->ea != 1)
		return (ft_fprintf(2, "Error: Cardinal missing or repeat.\n"), FAILURE);
	if (f->f != 1 || f->c != 1)
		return (ft_fprintf(2, "Error: Color missing or repeat.\n"), FAILURE);
	if (f->tex_so == NULL || f->tex_no == NULL || f->tex_ea == NULL
		|| f->tex_we == NULL)
		return (ft_fprintf(2, "Error: Cardinal textures missing.\n"), FAILURE);
	if (f->f_rgb[0] < 0 || f->f_rgb[1] < 0 || f->f_rgb[2] < 0)
		return (ft_fprintf(2, "Error: Negative color code\n"), FAILURE);
	if (f->c_rgb[0] < 0 || f->c_rgb[1] < 0 || f->c_rgb[2] < 0)
		return (ft_fprintf(2, "Error: Negative color code\n"), FAILURE);
	if (f->f_rgb[0] > 255 || f->f_rgb[1] > 255 || f->f_rgb[2] > 255)
		return (ft_fprintf(2, "Error: Color code exceeding 255\n"), FAILURE);
	if (f->c_rgb[0] > 255 || f->c_rgb[1] > 255 || f->c_rgb[2] > 255)
		return (ft_fprintf(2, "Error: Color code exceeding 255\n"), FAILURE);
	if (is_map_valid(f))
		return (FAILURE);
	return (SUCCESS);
}

int			check_extension(char *filename, char *ext)
{
	char	**tab;
	int		size;

	tab = ft_split(filename, '.');
	if (!tab)
		return (err_msg(ERROR_MALLOC, NULL), FAILURE);
	size = ft_split_size(tab);
	if (size < 2)
		return (ft_free_split(tab), ft_fprintf(2, "Error: No file extension\n"), FAILURE);
	if (ft_strcmp(tab[size - 1], ext))
		return (ft_free_split(tab), ft_fprintf(2, "Error: Wrong file extension %s\n", ext), FAILURE);
	return (ft_free_split(tab), SUCCESS);
}

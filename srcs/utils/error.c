#include "../../includes/cub3d.h"

//TODO: Rework this shit
void err_msg(int err_code, char *info)
{
	if (err_code == OPEN_ERROR)
		ft_fprintf(2, "Error: Failed to open file %s\n", info);
	else if (err_code == MALLOC_ERROR)
		ft_fprintf(2, "Error: malloc failed\n");
	else if (err_code == MISSING_INFO_ERROR)
		ft_fprintf(2, "Error: Textures or Colors missing\n");
	else if (err_code == CARDINAL_ERROR)
		ft_fprintf(2, "Error: Cardinal Textures missing\n");
	else if (err_code == FLOOR_ERROR)
		ft_fprintf(2, "Error: Color code missing\n");
	else if (err_code == MAP_ERROR)
		ft_fprintf(2, "Error: Invalid map\n");
}

#include "../../includes/cub3d.h"

//TODO: Rework this shit
void err_msg(int err_code, char *info)
{
	if (err_code == ERROR_OPEN)
		ft_fprintf(2, "Error: Failed to open file %s\n", info);
	else if (err_code == ERROR_MALLOC)
		ft_fprintf(2, "Error: malloc failed\n");
	else if (err_code == ERROR_MISSING_INFO)
		ft_fprintf(2, "Error: Textures or Colors missing\n");
	else if (err_code == ERROR_CARDINAL)
		ft_fprintf(2, "Error: Cardinal Textures missing\n");
	else if (err_code == ERROR_FLOOR)
		ft_fprintf(2, "Error: Color code missing\n");
	else if (err_code == ERROR_MAP)
		ft_fprintf(2, "Error: Invalid map\n");
	else
		ft_fprintf(2, "Error: unexpected %d\n", err_code);
}

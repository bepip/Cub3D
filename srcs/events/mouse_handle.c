#include "../../includes/cub3d.h"
#include <stdio.h>

int	mouse_handle(int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	(void) game;
	float	temp_dir_x;
	float	temp_plane_x;

	const float	mouse_rot = 0.03;
	printf("(%d,%d)\n", x, y);
	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-mouse_rot) - game->dir_y * sin(-mouse_rot);
	game->dir_y = temp_dir_x * sin(-mouse_rot) + game->dir_y * cos(-mouse_rot);
	game->dir_plane_x = game->dir_plane_x * cos(-mouse_rot)
		- game->dir_plane_y * sin(-mouse_rot);
	game->dir_plane_y = temp_plane_x * sin(-mouse_rot) + game->dir_plane_y
		* cos(-mouse_rot);
	return (SUCCESS);
}

void	hide_show_mouse(t_game *game)
{
	static int	h = 0;

	if (h == 0)
	{
		mlx_mouse_hide(game->mlx, game->win);
		h = 1;
	}
	else
	{
		mlx_mouse_show(game->mlx, game->win);
		h = 0;
	}
}

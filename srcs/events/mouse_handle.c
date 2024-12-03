#include "../../includes/cub3d.h"

static void	mouse_right(t_game *game);
static void	mouse_left(t_game *game);

int	mouse_handle(int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (game->old_mpos_x < x || game->old_mpos_x == WIDTH - 1)
	{
		mouse_right(game);
		game->old_mpos_x = x;
	}
	else if (game->old_mpos_x > 0 || game->old_mpos_x == 0)
	{
		mouse_left(game);
		game->old_mpos_x = x;
	}
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

static void	mouse_right(t_game *game)
{
	float		temp_dir_x;
	float		temp_plane_x;
	const float	mouse_rot = 0.015;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-mouse_rot) - game->dir_y * sin(-mouse_rot);
	game->dir_y = temp_dir_x * sin(-mouse_rot) + game->dir_y * cos(-mouse_rot);
	game->dir_plane_x = game->dir_plane_x * cos(-mouse_rot)
		- game->dir_plane_y * sin(-mouse_rot);
	game->dir_plane_y = temp_plane_x * sin(-mouse_rot) + game->dir_plane_y
		* cos(-mouse_rot);
}

static void	mouse_left(t_game *game)
{
	float		temp_dir_x;
	float		temp_plane_x;
	const float	mouse_rot = 0.015;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(mouse_rot) - game->dir_y * sin(mouse_rot);
	game->dir_y = temp_dir_x * sin(mouse_rot) + game->dir_y * cos(mouse_rot);
	game->dir_plane_x = game->dir_plane_x * cos(mouse_rot)
		- game->dir_plane_y * sin(mouse_rot);
	game->dir_plane_y = temp_plane_x * sin(mouse_rot) + game->dir_plane_y
		* cos(mouse_rot);
}

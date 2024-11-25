#include "../../includes/cub3d.h"

void	blank_textures(t_game *gamep);

void	init_blank_game(t_game *gamep)
{
	blank_textures(gamep);
	gamep->map = NULL;
	gamep->mlx = NULL;
	gamep->screen = NULL;
	gamep->win = NULL;
	gamep->img_game = NULL;
	gamep->img_minimap = NULL;
}

void	blank_textures(t_game *gamep)
{
	gamep->textures.img_no = NULL;
	gamep->textures.img_so = NULL;
	gamep->textures.img_ea = NULL;
	gamep->textures.img_we = NULL;
	gamep->textures.f_rgb[0] = -1;
	gamep->textures.f_rgb[1] = -1;
	gamep->textures.f_rgb[2] = -1;
	gamep->textures.c_rgb[0] = -1;
	gamep->textures.c_rgb[1] = -1;
	gamep->textures.c_rgb[2] = -1;
}

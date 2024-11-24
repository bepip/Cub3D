#include "../../includes/cub3d.h"

//Should mlx_new_image be called here?
//TODO: check NULL returns
int	init_mlx(t_game *game, t_file *file)
{
	(void) file;
	(void) game;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_fprintf(2, "Error: mlx_init failed\n"), FAILURE);
	game->width = WIDTH;
	game->height = HEIGHT;
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->screen = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	printf("texutre file: %s\n", file->tex_no);
	/*game->textures->img_no = mlx_xpm_file_to_image(
		game->mlx, file->tex_no,
		&game->textures->img_no->width,
		&game->textures->img_no->height);
	game->textures->img_so = mlx_xpm_file_to_image(
		game->mlx, file->tex_so,
		&game->textures->img_so->width,
		&game->textures->img_so->height);
	game->textures->img_we = mlx_xpm_file_to_image(
		game->mlx, file->tex_we,
		&game->textures->img_we->width,
		&game->textures->img_we->height);
	game->textures->img_ea = mlx_xpm_file_to_image(
		game->mlx, file->tex_ea,
		&game->textures->img_ea->width,
		&game->textures->img_ea->height);*/
	return (SUCCESS);
}

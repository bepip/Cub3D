#include "../../includes/cub3d.h"

void	free_game(t_game *game)
{
	ft_free_split(game->map);
	mlx_destroy_image(game->mlx, game->screen);
	//mlx_destroy_image(game->mlx, game->img_game);
	//mlx_destroy_image(game->mlx, game->img_minimap);
	mlx_destroy_image(game->mlx, game->textures.img_no);
	mlx_destroy_image(game->mlx, game->textures.img_so);
	mlx_destroy_image(game->mlx, game->textures.img_ea);
	mlx_destroy_image(game->mlx, game->textures.img_we);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	//mlx_loop_end(game->mlx);
	free(game->mlx);
}

void		free_file(t_file *filep)
{
	ft_free_split(filep->cp_file);
	ft_free_split(filep->map);
	free(filep->tex_no);
	free(filep->tex_so);
	free(filep->tex_we);
	free(filep->tex_ea);
}

void	free_cardinals(t_file *file)
{
	free(file->tex_no);
	free(file->tex_so);
	free(file->tex_ea);
	free(file->tex_we);
}

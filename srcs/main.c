#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return(err_msg(ERROR_WRONG_NBR_ARG, NULL), FAILURE);
	if (init_game(&game, argv[1]))
		return(FAILURE);
	/*mlx_hook(game.win, KeyPress, KeyPressMask, &key_handle, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, &close_window,
		&game);
	mlx_loop(game.mlx);*/
	free_game(&game);
	return (0);
}

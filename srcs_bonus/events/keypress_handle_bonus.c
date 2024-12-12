/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handle_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:33:44 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 16:15:26 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	handle_game_keypress(int key, t_game *game);

int	keypress_handle(int key, t_game *game)
{
	if (game->state == 0 && key == XK_Return)
		game->state = 1;
	else if (game->state == 1)
		handle_game_keypress(key, game);
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	return (SUCCESS);
}

void	handle_game_keypress(int key, t_game *game)
{
	if (key == XK_space)
		space_key(game);
	else if (key == XK_w)
		game->key[0] = 1;
	else if (key == XK_a)
		game->key[1] = 1;
	else if (key == XK_s)
		game->key[2] = 1;
	else if (key == XK_d)
		game->key[3] = 1;
	else if (key == XK_Right)
		game->key[4] = 1;
	else if (key == XK_Left)
		game->key[5] = 1;
}

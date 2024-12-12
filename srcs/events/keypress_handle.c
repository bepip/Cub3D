/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:39:32 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 17:40:02 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_game_keypress(int key, t_game *game);

int	keypress_handle(int key, t_game *game)
{
	handle_game_keypress(key, game);
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	return (SUCCESS);
}

void	handle_game_keypress(int key, t_game *game)
{
	if (key == XK_w)
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

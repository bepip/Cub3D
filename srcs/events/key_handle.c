/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:14 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 17:46:18 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_game_keypress(int key, t_game *game);
void	handle_game_keyrelease(int key, t_game *game);

int	keypress_handle(int key, t_game *game)
{
	handle_game_keypress(key, game);
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	return (SUCCESS);
}

int	keyrelease_handle(int key, t_game *game)
{
	if (key == XK_w)
		game->key[0] = 0;
	else if (key == XK_a)
		game->key[1] = 0;
	else if (key == XK_s)
		game->key[2] = 0;
	else if (key == XK_d)
		game->key[3] = 0;
	else if (key == XK_Right)
		game->key[4] = 0;
	else if (key == XK_Left)
		game->key[5] = 0;
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

void	player_actions(t_game *game)
{
	if (game->key[0] == 1)
		w_key(game);
	if (game->key[1] == 1)
		a_key(game);
	if (game->key[2] == 1)
		s_key(game);
	if (game->key[3] == 1)
		d_key(game);
	if (game->key[4] == 1)
		right_arrow_key(game);
	if (game->key[5] == 1)
		left_arrow_key(game);
}

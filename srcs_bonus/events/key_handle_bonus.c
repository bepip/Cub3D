/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:14 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 15:52:39 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	handle_game_key(int key, t_game *game);

int	key_handle(int key, t_game *game)
{
	if (game->state == 0 && key == XK_Return)
		game->state = 1;
	else if (game->state == 1)
		handle_game_key(key, game);
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	return (SUCCESS);
}

void	handle_game_key(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == XK_space)
		space_key(game);
	else if (key == XK_w)
		w_key(game);
	else if (key == XK_s)
		s_key(game);
	else if (key == XK_a)
		a_key(game);
	else if (key == XK_d)
		d_key(game);
	else if (key == XK_Right)
		right_arrow_key(game);
	else if (key == XK_Left)
		left_arrow_key(game);
}

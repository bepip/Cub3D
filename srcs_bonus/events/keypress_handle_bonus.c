/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:33:44 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 15:03:11 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	handle_game_keypress(int key, t_game *game);
void	torch_anim(t_game *game, int key);

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

void	torch_anim(t_game *game, int key)
{
	const double	step = 0.06;
	const double	scale = 90;
	static double	c = 0.0;
	static int		dir = 1;

	if (key == XK_w || key == XK_s || key == XK_a || key == XK_d)
	{
		if (c + step > 1 || c - step < -1)
			dir *= -1;
		c = c + dir * step;
		game->t_coefx = cos(c * M_PI) * scale;
		game->t_coefy = (sin(-fabs(c) * M_PI) / 2) * scale;
	}
}

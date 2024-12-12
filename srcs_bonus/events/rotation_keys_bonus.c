/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_keys_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:31 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 17:53:32 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	left_arrow_key(t_game *game)
{
	float	temp_dir_x;
	float	temp_plane_x;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-ROT_SPEED) - game->dir_y * sin(-ROT_SPEED);
	game->dir_y = temp_dir_x * sin(-ROT_SPEED) + game->dir_y * cos(-ROT_SPEED);
	game->dir_plane_x = game->dir_plane_x * cos(-ROT_SPEED)
		- game->dir_plane_y * sin(-ROT_SPEED);
	game->dir_plane_y = temp_plane_x * sin(-ROT_SPEED) + game->dir_plane_y
		* cos(-ROT_SPEED);
}

void	right_arrow_key(t_game *game)
{
	float	temp_dir_x;
	float	temp_plane_x;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(ROT_SPEED) - game->dir_y * sin(ROT_SPEED);
	game->dir_y = temp_dir_x * sin(ROT_SPEED) + game->dir_y * cos(ROT_SPEED);
	game->dir_plane_x = game->dir_plane_x * cos(ROT_SPEED) - game->dir_plane_y
		* sin(ROT_SPEED);
	game->dir_plane_y = temp_plane_x * sin(ROT_SPEED) + game->dir_plane_y
		* cos(ROT_SPEED);
}

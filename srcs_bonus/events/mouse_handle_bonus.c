/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:19 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 13:17:44 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	mouse_right(t_game *game);
static void	mouse_left(t_game *game);

int	mouse_handle(int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (game->state == 0)
		return (SUCCESS);
	if (game->old_mpos_x < x || game->old_mpos_x == WIDTH - 1)
		mouse_right(game);
	else if (game->old_mpos_x > 0 || game->old_mpos_x == 0)
		mouse_left(game);
	game->old_mpos_x = x;
	return (SUCCESS);
}

static void	mouse_left(t_game *game)
{
	float		temp_dir_x;
	float		temp_plane_x;
	const float	mouse_rot = 0.015;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(-mouse_rot) - game->dir_y * sin(-mouse_rot);
	game->dir_y = temp_dir_x * sin(-mouse_rot) + game->dir_y * cos(-mouse_rot);
	game->dir_plane_x = game->dir_plane_x * cos(-mouse_rot)
		- game->dir_plane_y * sin(-mouse_rot);
	game->dir_plane_y = temp_plane_x * sin(-mouse_rot) + game->dir_plane_y
		* cos(-mouse_rot);
}

static void	mouse_right(t_game *game)
{
	float		temp_dir_x;
	float		temp_plane_x;
	const float	mouse_rot = 0.015;

	temp_plane_x = game->dir_plane_x;
	temp_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(mouse_rot) - game->dir_y * sin(mouse_rot);
	game->dir_y = temp_dir_x * sin(mouse_rot) + game->dir_y * cos(mouse_rot);
	game->dir_plane_x = game->dir_plane_x * cos(mouse_rot)
		- game->dir_plane_y * sin(mouse_rot);
	game->dir_plane_y = temp_plane_x * sin(mouse_rot) + game->dir_plane_y
		* cos(mouse_rot);
}

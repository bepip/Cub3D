/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:05:21 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 18:05:38 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	render_startscreen(t_game *game);

int	render(t_game *game)
{
	if (game->state == 0)
		render_startscreen(game);
	else
	{
		render_raycast(game);
		draw_minimap(game);
		render_animation(game);
		player_actions(game);
		mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	}
	return (SUCCESS);
}

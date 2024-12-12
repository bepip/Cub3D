/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:59:18 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 15:35:25 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

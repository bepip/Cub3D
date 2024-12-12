/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:00:23 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 15:03:00 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	is_moving(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (game->key[i] == 1)
			return (1);
	}
	return (0);
}

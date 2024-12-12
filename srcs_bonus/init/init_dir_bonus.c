/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:27:17 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 17:54:54 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	set_dir(t_game *gamep, int dir_x, int dir_y)
{
	int	i;

	i = -1;
	while (++i < 6)
		gamep->key[i] = 0;
	gamep->dir_x = dir_x;
	gamep->t_coefx = 0.0;
	gamep->t_coefy = 0.0;
	gamep->dir_y = dir_y;
	gamep->dir_plane_x = 0.66 * (dir_x * cos(M_PI_2) - dir_y * sin(M_PI_2));
	gamep->dir_plane_y = 0.66 * (dir_x * sin(M_PI_2) + dir_y * cos(M_PI_2));
}

int	set_player_dir(t_game *gamep, t_file *file)
{
	if (file->dir == 'N')
		set_dir(gamep, 0, -1);
	else if (file->dir == 'S')
		set_dir(gamep, 0, 1);
	else if (file->dir == 'E')
		set_dir(gamep, -1, 0);
	else if (file->dir == 'W')
		set_dir(gamep, 1, 0);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:14 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 11:28:16 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_handle(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	if (key == XK_w)
		w_key(game);
	if (key == XK_s)
		s_key(game);
	if (key == XK_a)
		a_key(game);
	if (key == XK_d)
		d_key(game);
	if (key == XK_c)
		hide_show_mouse(game);
	if (key == 65363)
		right_arrow_key(game);
	if (key == 65361)
		left_arrow_key(game);
	return (SUCCESS);
}

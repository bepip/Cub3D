/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:55:58 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/12 14:56:13 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

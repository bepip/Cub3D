/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:24:18 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/19 09:34:31 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void display_game_data(t_game game)
{
	int i;
	int j;

	i = -1;
	ft_printf("map:\n");
	while (game.map[++i])
	{
		j = -1;
		while (game.map[++i][++j])
			ft_printf("%s ");
		ft_printf("\n");
	}
	ft_printf("textures:\n");
	ft_printf("NO: %s\n", game.textures->tex_no);
	ft_printf("SO: %s\n", game.textures->tex_so);
	ft_printf("EA: %s\n", game.textures->tex_ea);
	ft_printf("WE: %s\n", game.textures->tex_we);
	ft_printf("Colors:\n");
	ft_printf("Floor: (%d,%d,%d)\n", game.textures->f_rgb[0], game.textures->f_rgb[1],
			game.textures->f_rgb[2]);
	ft_printf("Ceiling: (%d,%d,%d)\n", game.textures->c_rgb[0], game.textures->c_rgb[1],
			game.textures->c_rgb[2]);
}

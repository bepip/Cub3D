/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_vertline_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:41 by pibernar          #+#    #+#             */
/*   Updated: 2024/12/04 13:16:55 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	set_cur_texture(t_game *game)
{
	if (game->side == 0)
	{
		if (game->dir_ray_x > 0)
			game->cur_tex = game->textures.img_ea;
		else
			game->cur_tex = game->textures.img_we;
	}
	else
	{
		if (game->dir_ray_y < 0)
			game->cur_tex = game->textures.img_so;
		else
			game->cur_tex = game->textures.img_no;
	}
}

// to make it darker
// color = (color >> 1) & 0x7F7F7F;
static void	mlx_draw_vertline_texutre(int x, int drawStart, int drawEnd,
		t_game *g)
{
	int	y;
	int	*dst;
	int	color;
	int	*tex_data;

	dst = (int *)mlx_get_data_addr(g->screen, &g->bpp, &g->size_line,
			&g->endian);
	tex_data = (int *)mlx_get_data_addr(g->cur_tex, &g->tex_bpp,
			&g->tex_size_line, &g->tex_endian);
	y = -1;
	while (++y <= HEIGHT)
	{
		if (y < drawStart)
			dst[y * g->size_line / 4 + x] = (g->textures.c_rgb >> 1) & 0x7F7F7F;
		else if (drawStart <= y && y <= drawEnd)
		{
			g->tex_y = (int)g->tex_pos & (g->cur_tex->height - 1);
			g->tex_pos += g->tex_step;
			color = tex_data[(int)g->tex_y * g->cur_tex->width + g->tex_x];
			color = (color >> 1) & 0x7F7F7F;
			dst[y * g->size_line / 4 + x] = color;
		}
		else
			dst[y * g->size_line / 4 + x] = (g->textures.f_rgb >> 1) & 0x7F7F7F;
	}
}

// line_h is the height of the line
// s for start
void	draw_vertline(t_game *g, int x)
{
	int	line_h;
	int	s;
	int	end;

	line_h = (int)(HEIGHT / g->dist_perp);
	s = -line_h / 2 + HEIGHT / 2;
	if (s < 0)
		s = 0;
	end = line_h / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	if (g->side == 0)
		g->hit_wall = g->pos_y + g->dist_perp * g->dir_ray_y;
	else
		g->hit_wall = g->pos_x + g->dist_perp * g->dir_ray_x;
	g->hit_wall -= floor(g->hit_wall);
	set_cur_texture(g);
	g->tex_x = (int)(g->hit_wall * g->cur_tex->width);
	if (g->side == 0 && g->dir_ray_x > 0)
		g->tex_x = g->cur_tex->width - g->tex_x - 1;
	if (g->side == 1 && g->dir_ray_y < 0)
		g->tex_x = g->cur_tex->width - g->tex_x - 1;
	g->tex_step = (float)g->cur_tex->width / line_h;
	g->tex_pos = (s - (float)HEIGHT / 2 + (float)line_h / 2) * g->tex_step;
	mlx_draw_vertline_texutre(x, s, end, g);
}
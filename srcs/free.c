/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:35:52 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/19 16:24:39 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void free_textures(t_textures *t);

void	free_game(t_game *game)
{
	ft_free_split(game->map);
	free_textures(game->textures);
}

void		free_file(t_file *filep)
{
	ft_free_split(filep->cp_file);
	ft_free_split(filep->map);
	free(filep->tex_no);
	free(filep->tex_so);
	free(filep->tex_we);
	free(filep->tex_ea);
}

static void free_textures(t_textures *t)
{
	free(t->tex_no);
	free(t->tex_so);
	free(t->tex_we);
	free(t->tex_ea);
	free(t);
}

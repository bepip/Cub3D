/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:17 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/19 16:11:45 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "s_file.h"

# define OPEN_ERROR -1
# define SUCCESS 0
# define FAILURE 1
# define MALLOC_ERROR 2
# define CARDINAL_ERROR 3
# define FLOOR_ERROR 4
# define MISSING_INFO_ERROR 5
# define MAP_ERROR 6
# define MAPMISSING_ERROR 7
# define RGB_INVALID_INT_ERROR 8

typedef struct s_textures
{
	char	*tex_no;
	char	*tex_so;
	char	*tex_ea;
	char	*tex_we;
	int		f_rgb[3];
	int		c_rgb[3];
}	t_textures;

typedef struct s_game
{
	char		**map;
	t_textures	*textures;
}	t_game;

//init how to name functions? initGameAssets? or parseGameDAta? load_gameData?
int		initialize_data(t_game *game, char *filename);
int		init_game_data(t_game *gamep, t_file *data);
void	free_game(t_game *game);

//error
void err_msg(int err_code, char *msg);

//displays
void display_game_data(t_game game);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:38:55 by laichoun          #+#    #+#             */
/*   Updated: 2024/11/20 17:39:58 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return(ft_fprintf(1, "Error: Wrong number of argument put a file.cub\n"), FAILURE);
	if (init_game(&game, argv[1]))
		return(FAILURE);
	//display_game_data(game);
	free_game(&game);
	return (0);
}

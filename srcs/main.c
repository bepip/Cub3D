/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:38:55 by laichoun          #+#    #+#             */
/*   Updated: 2024/11/18 15:59:37 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_file	data_file;

	if (argc != 2)
		return(ft_fprintf(1, "Error\nWrong number of argument put a file.cub\n"), 1);
	printf("%d\n", length_file(argv[1]));
	if (!copy_file(argv[1], &data_file))
		return(1);
	int	i = 0;
	while (data_file.cp_file[i])
	{
		printf("%s", data_file.cp_file[i]);
		i ++;
	}
	ft_free_split(data_file.cp_file);
	return (0);
}

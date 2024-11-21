/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:55:54 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/21 17:51:05 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FILE_H
# define S_FILE_H

typedef struct s_file
{
	char	**cp_file;
	char	**map;
	int		width;
	int		height;
	int		player;
	int		so;
	int		no;
	int		ea;
	int		we;
	int		f;
	int		c;
	int		map_ind;
	char	*tex_no;
	char	*tex_so;
	char	*tex_ea;
	char	*tex_we;
	int		f_rgb[3];
	int		c_rgb[3];
}			t_file;

int		init_map(t_file *file);
int		init_file(t_file *data);
void	free_file(t_file *filep);
int		check_file(t_file *data);
void	display_file(t_file f);
int		valid_map(char **map);
int		copy_file(char *file, t_file *file_p);
int		set_variable(t_file *file);
int		set_cardinal_points(t_file *file, char **tab);

int is_surrounded_walls(t_file *file);
int is_valid_row(t_file *file);
int is_valid_col(t_file *file);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:55:54 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/19 17:14:16 by pibernar         ###   ########.fr       */
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
	int		so;
	int		no;
	int		ea;
	int		we;
	int		f;
	int		c;
	char	*tex_no;
	char	*tex_so;
	char	*tex_ea;
	char	*tex_we;
	int		f_rgb[3];
	int		c_rgb[3];
}			t_file;

int			init_file(t_file *data);
void		free_file(t_file *filep);
int			copy_file(char *file, t_file *data_file);
int			set_cardinal_points(t_file *data, char **tab);
int			set_colors(t_file *data, char **tab);
int			set_variable(t_file *data);
int			check_file(t_file *data);
void		display_file(t_file f);
int			valid_map(char **map);
#endif

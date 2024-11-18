/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:55:54 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/18 16:57:16 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FILE_H
# define S_FILE_H

typedef struct s_file
{
	char	**cp_file;
	char	**map;
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

#endif

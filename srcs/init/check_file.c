/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:16:47 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/20 17:41:32 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//TODO: check if all data are set and correct
//		add err msg
//		check if textures can be accessed
int	check_file(t_file *f)
{
	if (!f)
		return (FAILURE);
	if (f->so != 1 || f->no != 1 || f->we != 1 || f->ea != 1 || f->f != 1
		|| f->c != 1)
		return (FAILURE);
	if (f->tex_so == NULL || f->tex_no == NULL || f->tex_ea == NULL
		|| f->tex_we == NULL)
		return (FAILURE);
	if (f->f_rgb[0] < 0 || f->f_rgb[1] < 0 || f->f_rgb[2] < 0)
		return (FAILURE);
	if (f->c_rgb[0] < 0 || f->c_rgb[1] < 0 || f->c_rgb[2] < 0)
		return (FAILURE);
	if (f->f_rgb[0] > 255 || f->f_rgb[1] > 255 || f->f_rgb[2] > 255)
		return (FAILURE);
	if (f->c_rgb[0] > 255 || f->c_rgb[1] > 255 || f->c_rgb[2] > 255)
		return (FAILURE);
	/*if (is_valid_map(f))
		return (FAILURE);*/
	return (SUCCESS);
}

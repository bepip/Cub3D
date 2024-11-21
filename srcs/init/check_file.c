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
//		check if textures can be accessed
int	check_file(t_file *f)
{
	if (!f)
		return (FAILURE);
	if (f->so != 1 || f->no != 1 || f->we != 1 || f->ea != 1)
		return (ft_fprintf(2, "Error: Cardinal missing or repeat.\n"), FAILURE);
	if (f->f != 1 || f->c != 1)
		return (ft_fprintf(2, "Error: Color missing or repeat.\n"), FAILURE);
	if (f->tex_so == NULL || f->tex_no == NULL || f->tex_ea == NULL
		|| f->tex_we == NULL)
		return (ft_fprintf(2, "Error: Cardinal textures missing.\n"), FAILURE);
	if (f->f_rgb[0] < 0 || f->f_rgb[1] < 0 || f->f_rgb[2] < 0)
		return (ft_fprintf(2, "Error: Negative color code\n"), FAILURE);
	if (f->c_rgb[0] < 0 || f->c_rgb[1] < 0 || f->c_rgb[2] < 0)
		return (ft_fprintf(2, "Error: Negative color code\n"), FAILURE);
	if (f->f_rgb[0] > 255 || f->f_rgb[1] > 255 || f->f_rgb[2] > 255)
		return (ft_fprintf(2, "Error: Color code exceeding 255\n"), FAILURE);
	if (f->c_rgb[0] > 255 || f->c_rgb[1] > 255 || f->c_rgb[2] > 255)
		return (ft_fprintf(2, "Error: Color code exceeding 255\n"), FAILURE);
	/* err_msg handled inside func
	 * if (is_valid_map(f))
		return (FAILURE);*/
	return (SUCCESS);
}

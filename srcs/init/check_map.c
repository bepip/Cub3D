/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:53:01 by Asma              #+#    #+#             */
/*   Updated: 2024/11/21 17:54:28 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//1) check de la première ligne c'est forcément que des 1 avec ou sans les des espaces
//2) check de la dernière ligne avec ou sans les espaces 

#include "../../includes/cub3d.h"
#include <stdio.h>

int is_surrounded_walls(t_file *file);
int is_valid_row(t_file *file);
int is_valid_col(t_file *file);

int is_surrounded_walls(t_file *file)
{
    if (is_valid_row(file) == SUCCESS)
        if (is_valid_col(file) == SUCCESS)
            return (SUCCESS);
    return (FAILURE);
}

/*
int	is_valid_map(t_file *file)
{
    if (is_surrounded_walls(file))
}
*/


int is_valid_row(t_file *file)
{
    int i;
    int j;

    i = 0;
//    ft_display_split(file->map);
//    printf("height ; %d\n", file->height);
//    printf("width ; %d\n", file->width);
    while (i < file->height)
    {
        j = 0;
        while (j < file->width)
        {
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
            while (j < file->width && file->map[i][j] == 32)
                j ++;
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
//            printf("char : %c\n", file->map[i][j]);
            if (j < file->width && file->map[i][j] != '1')
            {
//                printf("j : %d\n", j);
//                printf("i : %d\n", i);
//                printf("char : %c\n", file->map[i][j]);
                printf("NOK first char is not a wall border_rows, position i ; %d, j : %d\n", i, j);
                return (FAILURE);
            }
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
//            printf("char : %c\n", file->map[i][j]);
            while (j < file->width && file->map[i][j] != 32)
                j ++;
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
//            printf("char : %c\n", file->map[i][j]);
            if (file->map[i][j - 1] != '1' && file->map[i][j - 1] != ' ')
                {
//                    printf("j : %d\n", j);
//                    printf("i : %d\n", i);
//                    printf("char : %c\n", file->map[i][j]);
                    printf("NOK first char is not a wall border_rows test, position i ; %d, j : %d\n", i, j);
                    return (FAILURE);
                }
            j ++;
        }
        i ++;
    }
    return (SUCCESS);
}

int is_valid_col(t_file *file)
{
    int i;
    int j;

    j = 1;
//    printf("height col ; %d\n", file->height);
//    printf("width col ; %d\n", file->width);
    while (j < file->width)
    {
        i = 0;
        while (i < file->height)
        {
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
            while (i < file->height && file->map[i][j] == 32)
                i ++;
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
//            if (i < file->height)
//                printf("char : %c\n", file->map[i][j]);
            if (i < file->height && file->map[i][j] != '1')
            {
//                printf("j : %d\n", j);
//                printf("i : %d\n", i);
//                printf("char : %c\n", file->map[i][j]);
                printf("NOK first char is not a wall border_rows, position i ; %d, j : %d\n", i, j);
                return (FAILURE);
            }
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
//            if (i < file->height)
//                printf("char : %c\n", file->map[i][j]);
            while (i < file->height && file->map[i][j] != 32)
                i ++;
//            printf("j : %d\n", j);
//            printf("i : %d\n", i);
//            if (i < file->height)
//                printf("char : %c\n", file->map[i][j]);
            if (file->map[i - 1][j] != '1' && file->map[i - 1][j] != ' ')
            {
//                    printf("j : %d\n", j);
//                    printf("i : %d\n", i);
//                    printf("char : %c\n", file->map[i - 1][j]);
                    printf("NOK first char is not a wall border_rows test, position i ; %d, j : %d\n", i -1, j);
                    return (FAILURE);
            }
            i ++;
//          printf("j : %d\n", j);
//            printf("i : %d\n", i);
        }
        j ++;
    }
    return (SUCCESS);
}

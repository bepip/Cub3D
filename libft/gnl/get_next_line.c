/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:43:12 by pibernar          #+#    #+#             */
/*   Updated: 2024/04/10 12:17:53 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_right_side(char *current_line);
char	*ft_get_line(int fd, char *current_line);
char	*ft_strconcat(char *current_line, char *buf);
char	*ft_get_left_side(char *current_line);

char	*ft_get_line(int fd, char *current_line)
{
	char	*buf;
	int		bytes_read;

	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	buf[0] = 0;
	while (ft_strchr(buf, '\n') == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), NULL);
		buf[bytes_read] = 0;
		current_line = ft_strconcat(current_line, buf);
	}
	free(buf);
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	*current_line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_line = ft_get_line(fd, current_line);
	if (!current_line)
		return (NULL);
	str = ft_get_left_side(current_line);
	current_line = ft_get_right_side(current_line);
	return (str);
}

char	*ft_strconcat(char *current_line, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!current_line)
	{
		current_line = malloc(sizeof(char) * 1);
		current_line[0] = 0;
	}
	if (!current_line || !buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(current_line) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (current_line[++i])
		str[i] = current_line[i];
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = 0;
	free(current_line);
	return (str);
}

char	*ft_get_left_side(char *current_line)
{
	char	*left_side;
	int		i;

	i = 0;
	if (current_line[i] == 0)
		return (0);
	while (current_line[i] && current_line[i] != '\n')
		i++;
	left_side = malloc(sizeof(char) * (i + 2));
	if (!left_side)
		return (NULL);
	i = 0;
	while (current_line[i] != '\n' && current_line[i])
	{
		left_side[i] = current_line[i];
		i++;
	}
	if (current_line[i] == '\n')
		left_side[i++] = '\n';
	left_side[i] = 0;
	return (left_side);
}

char	*ft_get_right_side(char *current_line)
{
	char	*right_side;
	int		i;
	int		shift;

	shift = 0;
	while (current_line[shift] && current_line[shift] != '\n')
		shift++;
	if (current_line[shift] == '\0')
		return (free(current_line), NULL);
	right_side = malloc(ft_strlen(current_line) - shift + 1);
	if (!right_side)
		return (NULL);
	shift++;
	i = 0;
	while (current_line[shift])
		right_side[i++] = current_line[shift++];
	right_side[i] = 0;
	if (*right_side == '\0')
	{
		free(right_side);
		right_side = NULL;
	}
	return (free(current_line), right_side);
}

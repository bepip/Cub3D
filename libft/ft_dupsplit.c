/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:15:23 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/19 16:20:01 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dupsplit(char **split)
{
	char	**new;
	int		size;
	int		i;

	if (!split)
		return (NULL);
	if (!(*split))
		return (NULL);
	size = ft_split_size(split);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (split[++i])
		new[i] = ft_strdup(split[i]);
	new[i] = NULL;
	return (new);
}

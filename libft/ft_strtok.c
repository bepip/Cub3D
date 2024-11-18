/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibernar <@student.42Luxembourg.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:16:49 by pibernar          #+#    #+#             */
/*   Updated: 2024/11/18 15:18:49 by pibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_sep(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(char *str, char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
		i++;
	if (i == 0)
		return (0);
	i = 1;
	if (ft_sep(str[0], set) == 0)
		count++;
	while (str[i] != 0)
	{
		if (ft_sep(str[i - 1], set) == 1 && ft_sep(str[i], set) == 0)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_add(char *str, char *set, int i)
{
	char	*s;
	int		l;
	int		j;

	l = 0;
	while (str[i + l] != 0 && ft_sep(str[i + l], set) == 0)
		l++;
	s = malloc(sizeof(char) * (l + 1));
	if (s == 0)
		return (0);
	j = 0;
	while (j < l)
	{
		s[j] = str[i + j];
		j++;
	}
	s[j] = 0;
	return (s);
}

char	**ft_strtok(char *str, char *charset)
{
	char	**split;
	int		count;
	int		i;
	int		ind;
	char	*s;

	count = ft_count(str, charset);
	split = malloc (sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = 0;
	ind = 0;
	while (str[i] != 0 && ind < count)
	{
		while (ft_sep(str[i], charset) == 1 && str[i] != 0)
			i++;
		s = ft_add(str, charset, i);
		split[ind++] = s;
		while (ft_sep(str[i], charset) == 0 && str[i] != 0)
			i++;
	}
	split[ind] = 0;
	return (split);
}

size_t	ft_split_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
